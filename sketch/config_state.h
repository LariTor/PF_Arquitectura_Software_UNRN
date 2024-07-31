/**
 * @file config_state.h
 * @author Lara Torletti (lara.a.torletti@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-07-29
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef CONFIG_STATE_H
#define CONFIG_STATE_H

#include "state.h"
#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

class ConfigState : public State
{
public:
    ConfigState(LiquidCrystal_I2C &lcd);

    void handleUp(Context *context) override;
    void handleDown(Context *context) override;
    void handleSelect(Context *context) override;
    void handleBack(Context *context) override;
    void displayMenu(Context *context) override;

private:
    int currentIndex;
    LiquidCrystal_I2C &lcd;
    void initializeLcd();
    void printLogo();
    static const char *menuItems[];
    static const int menuLength;
};

#endif // CONFIG_STATE_H
