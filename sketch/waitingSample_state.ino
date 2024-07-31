/**
 * @file waitingsample_state.ino
 * @author Lara Torletti (lara.a.torletti@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-07-29
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "waitingSample_state.h"
#include "sampling_state.h"
#include "menu_state.h"
#include "context.h"
#include "pins.h"
#include "custom_char.h"

WaitingSampleState::WaitingSampleState(LiquidCrystal_I2C &lcd) : lcd(lcd) {}

void WaitingSampleState::handleUp(Context *context)
{
    // No action needed for Up in Sampling state
}

void WaitingSampleState::handleDown(Context *context)
{
    // No action needed for Down in Sampling state
}

void WaitingSampleState::handleSelect(Context *context)
{
    Serial.begin(9600);
    context->setState(new SamplingState(lcd)); // Transition to MenuState on SELECT
}

void WaitingSampleState::handleBack(Context *context)
{
    context->setState(new MenuState(lcd)); // Transition to MenuState on back
}

void WaitingSampleState::displayMenu(Context *context)
{
    initializeLcd();
    printLogo();
    lcd.setCursor(0, 0);
    lcd.printByte(0);
    lcd.print("Muestreo");
    lcd.setCursor(0, 1);
    lcd.print("I:");
    const char *Iso = context->getIsotope();
    lcd.print(Iso);
    lcd.setCursor(0, 2);
    lcd.print("Rs:");
    int Rsup = context->getUpperLimit();
    lcd.print(Rsup);
    lcd.setCursor(0, 3);
    lcd.print("Ri:");
    int Rlow = context->getLowerLimit();
    lcd.print(Rlow);
    lcd.setCursor(6, 1);
    lcd.print("|");
    lcd.setCursor(6, 2);
    lcd.print("|");
    lcd.setCursor(6, 3);
    lcd.print("|");
    lcd.setCursor(7, 2);
    lcd.print("Cuentas:--");
    lcd.setCursor(7, 3);
    lcd.print("Estado:");
    lcd.print("WAIT");
}

void WaitingSampleState::printLogo()
{
    lcd.setCursor(18, 0);
    lcd.printByte(1);
    lcd.setCursor(19, 0);
    lcd.printByte(2);
    lcd.setCursor(18, 1);
    lcd.printByte(3);
    lcd.setCursor(19, 1);
    lcd.printByte(4);
}

void WaitingSampleState::initializeLcd()
{
    lcd.clear();
    lcd.noBlink();
    lcd.setCursor(0, 0);
    lcd.createChar(0, sample_icon);
    lcd.createChar(1, logo_2x2[0]);
    lcd.createChar(2, logo_2x2[1]);
    lcd.createChar(3, logo_2x2[2]);
    lcd.createChar(4, logo_2x2[3]);
    lcd.home();
}