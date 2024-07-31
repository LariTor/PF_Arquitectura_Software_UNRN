/**
 * @file configRange_state.h
 * @author Lara Torletti (lara.a.torletti@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-07-29
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef CONFIGRANGE_STATE_H
#define CONFIGRANGE_STATE_H

#include "state.h"
#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

class ConfigRangeState : public State
{
private:
    LiquidCrystal_I2C &lcd;
    int lowerLimit;
    int upperLimit;
    bool settingLowerLimit;
    void initializeLcd();
    void printLogo();

public:
    ConfigRangeState(LiquidCrystal_I2C &lcd);
    void handleUp(Context *context) override;
    void handleDown(Context *context) override;
    void handleSelect(Context *context) override;
    void handleBack(Context *context) override;
    void displayMenu(Context *context) override;
};

#endif // CONFIGRANGE_STATE_H