/**
 * @file context.h
 * @author Lara Torletti (lara.a.torletti@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-07-29
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef CONTEXT_H
#define CONTEXT_H

#include "state.h"
#include <LiquidCrystal_I2C.h>

class State;

class Context
{
public:
    static Context *getInstance();

    void setState(State *state);
    void handleUp();
    void handleDown();
    void handleSelect();
    void handleBack();
    void displayMenu();

    void setLowerLimit(int lowerLimit);
    int getLowerLimit() const;
    void setUpperLimit(int upperLimit);
    int getUpperLimit() const;

    void setIsotope(const char *isotope);
    const char *getIsotope() const;

    LiquidCrystal_I2C &getLcd();

private:
    Context();
    State *currentState;
    LiquidCrystal_I2C lcd;
    static Context *instance;

    int lowerLimit;
    int upperLimit;
    const char *isotope;
};

#endif // CONTEXT_H
