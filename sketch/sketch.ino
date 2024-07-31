#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "pins.h"
#include "custom_char.h"
#include "context.h"
#include "menu_state.h"
#include "init_state.h"

Context *context;

void setup()
{
  Context::getInstance()->displayMenu();
}

void loop()
{
  Context *context = Context::getInstance();
  bool redraw = false;

  if (digitalRead(button_up) == LOW)
  {
    delay(200);
    if (digitalRead(button_up) == LOW)
    {
      context->handleUp();
      redraw = true;
    }
  }
  if (digitalRead(button_down) == LOW)
  {
    delay(200);
    if (digitalRead(button_down) == LOW)
    {
      context->handleDown();
      redraw = true;
    }
  }
  if (digitalRead(button_select) == LOW)
  {
    delay(200);
    if (digitalRead(button_select) == LOW)
    {
      context->handleSelect();
      redraw = true;
    }
  }
  if (digitalRead(button_back) == LOW)
  {
    delay(200);
    if (digitalRead(button_back) == LOW)
    {
      context->handleBack();
      redraw = true;
    }
  }

  if (redraw)
  {
    context->displayMenu();
  }
}
