/**
 * @file configIsotope_state.h
 * @author Lara Torletti (lara.a.torletti@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-07-29
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef CONFIGISOTOPE_STATE_H
#define CONFIGISOTOPE_STATE_H

#include "state.h"
#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

class ConfigIsotopeState : public State
{
private:
    LiquidCrystal_I2C &lcd;
    int currentIndex;
    static const char *menuItems[];
    static const int menuLength;
    void initializeLcd();
    void printLogo();

public:
    ConfigIsotopeState(LiquidCrystal_I2C &lcd);
    void handleUp(Context *context) override;
    void handleDown(Context *context) override;
    void handleSelect(Context *context) override;
    void handleBack(Context *context) override;
    void displayMenu(Context *context) override;
};

#endif // CONFIGISOTOPE_STATE_H