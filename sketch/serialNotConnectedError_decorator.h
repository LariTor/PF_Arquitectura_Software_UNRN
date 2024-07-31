/**
 * @file serialNotConnectedError_decorator.h
 * @author Lara Torletti (lara.a.torletti@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-07-01
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SERIALNOTCONNECTEDERROR_DECORATOR_H
#define SERIALNOTCONNECTEDERROR_DECORATOR_H

#include "error_decorator.h"

class SerialNotConnectedErrorDecorator : public ErrorDecorator
{
public:
    SerialNotConnectedErrorDecorator(ErrorState *error) : ErrorDecorator(error) {}
    void displayError(LiquidCrystal_I2C &lcd) override
    {
        ErrorDecorator::displayError(lcd);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Error: Serial");
        lcd.setCursor(0, 1);
        lcd.print("No Conectado");
    }
};

#endif // SERIALNOTCONNECTEDERROR_DECORATOR_H