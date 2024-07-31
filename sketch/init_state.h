/**
 * @file init_state.h
 * @author Lara Torletti (lara.a.torletti@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-07-29
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef INIT_STATE_H
#define INIT_STATE_H

#include "state.h"
#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

class InitState : public State
{
public:
    InitState(LiquidCrystal_I2C &lcd);

    void handleUp(Context *context) override;
    void handleDown(Context *context) override;
    void handleSelect(Context *context) override;
    void handleBack(Context *context) override;
    void displayMenu(Context *context) override;

private:
    LiquidCrystal_I2C &lcd;
    void initializeLcd();
    void printLogo();
};

#endif // INIT_STATE_H