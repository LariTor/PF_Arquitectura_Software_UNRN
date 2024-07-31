/**
 * @file noDataError_decorator.h
 * @author Lara Torletti (lara.a.torletti@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-07-01
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef NODATAERROR_DECORATOR_H
#define NODATAERROR_DECORATOR_H

#include "error_decorator.h"

class NoDataErrorDecorator : public ErrorDecorator
{
public:
    NoDataErrorDecorator(ErrorState *error) : ErrorDecorator(error) {}
    void displayError(LiquidCrystal_I2C &lcd) override
    {
        ErrorDecorator::displayError(lcd);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Error: No Data");
        lcd.setCursor(0, 1);
        lcd.print("Recibido");
    }
};

#endif // NODATAERROR_DECORATOR_H