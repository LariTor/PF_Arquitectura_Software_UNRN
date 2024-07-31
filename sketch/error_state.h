/**
 * @file error_state.h
 * @author Lara Torletti (lara.a.torletti@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-07-01
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef ERROR_STATE_H
#define ERROR_STATE_H

#include <LiquidCrystal_I2C.h>

class ErrorState
{
public:
    virtual ~ErrorState() {}
    virtual void displayError(LiquidCrystal_I2C &lcd) = 0;
};

#endif // ERROR_STATE_H