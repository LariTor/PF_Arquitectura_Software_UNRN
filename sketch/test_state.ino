/**
 * @file test_state.ino
 * @author Lara Torletti (lara.a.torletti@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-07-29
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "test_state.h"
#include "menu_state.h"
#include "context.h"
#include "custom_char.h"

TestState::TestState(LiquidCrystal_I2C &lcd) : lcd(lcd) {}

void TestState::handleUp(Context *context)
{
    // No action needed for Up in Test state
}

void TestState::handleDown(Context *context)
{
    // No action needed for Down in Test state
}

void TestState::handleSelect(Context *context)
{
    // No action needed for Down in Test state
}

void TestState::handleBack(Context *context)
{
    context->setState(new MenuState(lcd)); // Transition to MenuState on Back
}

void TestState::displayMenu(Context *context)
{
    initializeLcd();
    printLogo();
    lcd.setCursor(4, 2);
    lcd.print("-------------");
    lcd.setCursor(4, 3);
    lcd.print("Test Window");
}

void TestState::printLogo()
{

    lcd.setCursor(9, 0);
    lcd.printByte(0);
    lcd.setCursor(10, 0);
    lcd.printByte(1);
    lcd.setCursor(9, 1);
    lcd.printByte(2);
    lcd.setCursor(10, 1);
    lcd.printByte(3);
}

void TestState::initializeLcd()
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.createChar(0, logo_2x2[0]);
    lcd.createChar(1, logo_2x2[1]);
    lcd.createChar(2, logo_2x2[2]);
    lcd.createChar(3, logo_2x2[3]);
    lcd.home();
}