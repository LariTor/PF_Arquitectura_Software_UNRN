#ifndef MENU_STATE_H
#define MENU_STATE_H

#include <LiquidCrystal_I2C.h>

#include "state.h"

class Context;

class MenuState : public State
{
public:
    MenuState(LiquidCrystal_I2C *lcd);
    void handleUp() override;
    void handleDown() override;
    void handleSelect() override;
    void handleBack() override;
    void display() override;

    void setContext(Context *context);

private:
    LiquidCrystal_I2C *lcd;
    Context *context;
};

#endif // MENU_STATE_H
