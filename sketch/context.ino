/**
 * @file context.ino
 * @author Lara Torletti (lara.a.torletti@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-07-29
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "context.h"
#include "state.h"
#include "init_state.h"
#include "menu_state.h"

Context *Context::instance = nullptr;

Context *Context::getInstance()
{

    if (instance == nullptr)
    {
        instance = new Context();
        instance->setState(new InitState(instance->getLcd())); // Inicializa con el estado de bienvenida
    }
    return instance;
}

Context::Context() : lcd(0x27, 20, 4), currentState(nullptr), lowerLimit(0), upperLimit(0), isotope("")
{
    lcd.init();
    lcd.backlight();
    lcd.home();
}

void Context::setState(State *state)
{
    if (currentState != nullptr)
    {
        delete currentState; // Liberar el estado anterior
    }
    currentState = state;
    displayMenu();
}

void Context::handleUp()
{
    if (currentState)
        currentState->handleUp(this);
}

void Context::handleDown()
{
    if (currentState)
        currentState->handleDown(this);
}

void Context::handleSelect()
{
    if (currentState)
        currentState->handleSelect(this);
}

void Context::handleBack()
{
    if (currentState)
        currentState->handleBack(this);
}

void Context::displayMenu()
{
    if (currentState)
        currentState->displayMenu(this);
}

LiquidCrystal_I2C &Context::getLcd()
{
    return lcd;
}

void Context::setLowerLimit(int lowerLimit)
{
    this->lowerLimit = lowerLimit;
}

int Context::getLowerLimit() const
{
    return lowerLimit;
}

void Context::setUpperLimit(int upperLimit)
{
    this->upperLimit = upperLimit;
}

int Context::getUpperLimit() const
{
    return upperLimit;
}
void Context::setIsotope(const char *isotope)
{
    this->isotope = isotope;
}

const char *Context::getIsotope() const
{
    return isotope;
}