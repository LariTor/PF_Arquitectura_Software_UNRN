/**
 * @file errorSample_state.ino
 * @author Lara Torletti (lara.a.torletti@gmail.com)
 * @brief Implementación de la clase `ErrorSampleState`, que representa el estado de error en el muestreo.
 * @version 0.1
 * @date 2024-07-01
 * @details La clase `ErrorSampleState` maneja el estado en el que se detecta un error durante
 *          el muestreo. Hereda de `State` y proporciona métodos para manejar las entradas
 *          del usuario y actualizar la pantalla LCD en caso de error.
 * @copyright Copyright (c) 2024
 *
 */

#include "errorSample_state.h"
#include "waitingSample_state.h"
#include "menu_state.h"
#include "context.h"
#include "pins.h"
#include "custom_char.h"

ErrorSampleState::ErrorSampleState(LiquidCrystal_I2C &lcd) : lcd(lcd) {}

void ErrorSampleState::handleUp(Context *context)
{
    // No action needed for Up in Sampling state
}

void ErrorSampleState::handleDown(Context *context)
{
    // No action needed for Down in Sampling state
}

void ErrorSampleState::handleSelect(Context *context)
{
}

void ErrorSampleState::handleBack(Context *context)
{
    context->setState(new WaitingSampleState(lcd)); // Transition to MenuState on back
}

void ErrorSampleState::displayMenu(Context *context)
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
    lcd.print("Cuentas:XXXX");
    lcd.setCursor(7, 3);
    lcd.print("Estado:");
    lcd.print("ERROR");
}

void ErrorSampleState::printLogo()
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

void ErrorSampleState::initializeLcd()
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