/**
 * @file error_decorator.h
 * @author Lara Torletti (lara.a.torletti@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-07-01
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef ERROR_DECORATOR_H
#define ERROR_DECORATOR_H

#include "error_state.h"

class ErrorDecorator : public ErrorState
{
protected:
    ErrorState *wrappedError;

public:
    ErrorDecorator(ErrorState *error) : wrappedError(error) {}
    void displayError(LiquidCrystal_I2C &lcd) override
    {
        if (wrappedError)
        {
            wrappedError->displayError(lcd);
        }
    }
};

#endif // ERROR_DECORATOR_H
