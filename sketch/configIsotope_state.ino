/**
 * @file configIsotope_state.ino
 * @author Lara Torletti (lara.a.torletti@gmail.com)
 * @brief  Implementación de la clase ConfigIsotopeState para la configuración del isótopo en la interfaz.
 * @version 0.1
 * @date 2024-07-01
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "configIsotope_state.h"
#include "config_state.h"
#include "context.h"
#include "custom_char.h"

#if defined(ARDUINO) && ARDUINO >= 100
#define printByte(args) write(args);
#else
#define printByte(args) print(args, BYTE);
#endif

const char *ConfigIsotopeState::menuItems[] = {"F18", "Tc99"};
const int ConfigIsotopeState::menuLength = sizeof(menuItems) / sizeof(menuItems[0]);

ConfigIsotopeState::ConfigIsotopeState(LiquidCrystal_I2C &lcd) : lcd(lcd), currentIndex(0) { currentIndex = 0; }

void ConfigIsotopeState::handleUp(Context *context)
{
    currentIndex = (currentIndex - 1 + menuLength) % menuLength;
    displayMenu(context);
}

void ConfigIsotopeState::handleDown(Context *context)
{
    currentIndex = (currentIndex + 1) % menuLength;
    displayMenu(context);
}

void ConfigIsotopeState::handleSelect(Context *context)
{
    switch (currentIndex)
    {
    case 0:
        context->setIsotope(menuItems[0]);
        break;
    case 1:
        context->setIsotope(menuItems[1]);
        break;
    default:
        break;
    }
}

void ConfigIsotopeState::handleBack(Context *context)
{
    context->setState(new ConfigState(lcd));
}

void ConfigIsotopeState::displayMenu(Context *context)
{
    initializeLcd();
    lcd.printByte(0);
    lcd.print("Configurar Isotopo");
    printLogo();
    lcd.setCursor(0, 1);
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

void ConfigIsotopeState::printLogo()
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

void ConfigIsotopeState::initializeLcd()
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
