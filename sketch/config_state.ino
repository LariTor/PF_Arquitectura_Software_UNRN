/**
 * @file config_state.ino
 * @author Lara Torletti (lara.a.torletti@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-07-29
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "menu_state.h"
#include "configRange_state.h"
#include "configIsotope_state.h"
#include "config_state.h"
#include "context.h"
#include "custom_char.h"

#if defined(ARDUINO) && ARDUINO >= 100
#define printByte(args) write(args);
#else
#define printByte(args) print(args, BYTE);
#endif

const char *ConfigState::menuItems[] = {"Rango", "Isotopo"};
const int ConfigState::menuLength = sizeof(menuItems) / sizeof(menuItems[0]);

ConfigState::ConfigState(LiquidCrystal_I2C &lcd) : currentIndex(0), lcd(lcd) {}

void ConfigState::handleUp(Context *context)
{
    currentIndex = (currentIndex - 1 + menuLength) % menuLength;
    displayMenu(context);
}

void ConfigState::handleDown(Context *context)
{
    currentIndex = (currentIndex + 1) % menuLength;
    displayMenu(context);
}

void ConfigState::handleSelect(Context *context)
{
    switch (currentIndex)
    {
    case 0:
        context->setState(new ConfigRangeState(lcd));
        break;
    case 1:
        context->setState(new ConfigIsotopeState(lcd));
        break;
    default:
        break;
    }
}

void ConfigState::handleBack(Context *context)
{
    context->setState(new MenuState(lcd)); // Transition to InitState on back
}

void ConfigState::displayMenu(Context *context)
{
    initializeLcd();

    lcd.printByte(0);
    lcd.print(" Configuracion");

    printLogo();

    for (int i = 0; i < menuLength; ++i)
    {
        lcd.setCursor(0, i + 1); // Adjust for the title row
        if (i == currentIndex)
        {
            lcd.print("> ");
        }
        else
        {
            lcd.print("  ");
        }
        lcd.print(menuItems[i]);
    }
}

void ConfigState::printLogo()
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

void ConfigState::initializeLcd()
{
    lcd.clear();
    lcd.noBlink();
    lcd.setCursor(0, 0);
    lcd.createChar(0, conf_icon);
    lcd.createChar(1, logo_2x2[0]);
    lcd.createChar(2, logo_2x2[1]);
    lcd.createChar(3, logo_2x2[2]);
    lcd.createChar(4, logo_2x2[3]);
    lcd.home();
}