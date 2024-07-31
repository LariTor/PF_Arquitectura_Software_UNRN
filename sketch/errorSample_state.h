/**
 * @file errorSample_state.h
 * @author Lara Torletti (lara.a.torletti@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-07-29
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef ERRORSAMPLE_STATE_H
#define ERRORSAMPLE_STATE_H

#include "state.h"
#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

class ErrorSampleState : public State
{
private:
    int currentIndex;
    LiquidCrystal_I2C &lcd;
    void initializeLcd();
    void printLogo();
    void buzzerFunc();

public:
    ErrorSampleState(LiquidCrystal_I2C &lcd);
    void handleUp(Context *context) override;
    void handleDown(Context *context) override;
    void handleSelect(Context *context) override;
    void handleBack(Context *context) override;
    void displayMenu(Context *context) override;
};

#endif // ERRORSAMPLE_STATE_H