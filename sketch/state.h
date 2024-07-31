/**
 * @file state.hpp
 * @author Lara Torletti (lara.a.torletti@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-07-29
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef STATE_H
#define STATE_H

#include "context.h"

class Context;

class State
{
public:
    virtual ~State() {}
    virtual void handleUp(Context *context) = 0;
    virtual void handleDown(Context *context) = 0;
    virtual void handleSelect(Context *context) = 0;
    virtual void handleBack(Context *context) = 0;
    virtual void displayMenu(Context *context) = 0;
};

#endif // STATE_H
