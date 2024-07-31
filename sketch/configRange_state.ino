/**
 * @file configRange_state.ino
 * @author Lara Torletti (lara.a.torletti@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-07-29
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "configRange_state.h"
#include "config_state.h"
#include "context.h"
#include "custom_char.h"

#if defined(ARDUINO) && ARDUINO >= 100
#define printByte(args) write(args);
#else
#define printByte(args) print(args, BYTE);
#endif

ConfigRangeState::ConfigRangeState(LiquidCrystal_I2C &lcd) : lcd(lcd), lowerLimit(0), upperLimit(100), settingLowerLimit(true) {}

void ConfigRangeState::handleUp(Context *context)
{
    if (settingLowerLimit)
    {
        if (lowerLimit < 900)
        {
            lowerLimit++;
        }
    }
    else
    {
        if (upperLimit < 900)
        {
            upperLimit++;
        }
    }
    displayMenu(context);
}

void ConfigRangeState::handleDown(Context *context)
{
    if (settingLowerLimit)
    {
        if (lowerLimit > 0)
        {
            lowerLimit--;
        }
    }
    else
    {
        if (upperLimit > 0)
        {
            upperLimit--;
        }
    }
    displayMenu(context);
}

void ConfigRangeState::handleSelect(Context *context)
{
    if (settingLowerLimit)
    {
        settingLowerLimit = false;
    }
    else
    {
        context->setLowerLimit(lowerLimit);
        context->setUpperLimit(upperLimit);
    }
    displayMenu(context);
}

void ConfigRangeState::handleBack(Context *context)
{
    context->setState(new ConfigState(lcd));
}

void ConfigRangeState::displayMenu(Context *context)
{
    initializeLcd();
    lcd.printByte(0);
    lcd.print(" Configurar Rango");
    printLogo();

    lcd.setCursor(0, 1);
    lcd.print("Inferior: ");
    lcd.print(lowerLimit);
    lcd.setCursor(0, 2);
    lcd.print("Superior: ");
    lcd.print(upperLimit);

    if (settingLowerLimit)
    {
        lcd.setCursor(10, 1);
    }
    else
    {
        lcd.setCursor(10, 2);
    }
    lcd.blink();
}

void ConfigRangeState::printLogo()
{
    lcd.setCursor(18, 2);
    lcd.printByte(1);
    lcd.setCursor(19, 2);
    lcd.printByte(2);
    lcd.setCursor(18, 3);
    lcd.printByte(3);
    lcd.setCursor(19, 3);
    lcd.printByte(4);
}

void ConfigRangeState::initializeLcd()
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.createChar(0, conf_icon);
    lcd.createChar(1, logo_2x2[0]);
    lcd.createChar(2, logo_2x2[1]);
    lcd.createChar(3, logo_2x2[2]);
    lcd.createChar(4, logo_2x2[3]);
    lcd.home();
}
