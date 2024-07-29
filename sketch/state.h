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

class State
{
public:
    virtual void handleUp() = 0;
    virtual void handleDown() = 0;
    virtual void handleSelect() = 0;
    virtual void handleBack() = 0;
    virtual void display() = 0;
};

#endif // STATE_H
