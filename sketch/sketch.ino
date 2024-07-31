/**
 * @file sketch.ino
 * @author Lara Torletti (lara.a.torletti@gmail.com)
 * @brief Main file for Arduino
 * @version 0.1
 * @date 2024-07-01

 * @copyright Copyright (c) 2024
 *
 */

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "pins.h"
#include "custom_char.h"
#include "context.h"
#include "menu_state.h"
#include "init_state.h"

void setup()
{
  // Inicializa el contexto y muestra el menú
  Context::getInstance()->displayMenu();
}

void loop()
{
  Context *context = Context::getInstance();
  bool redraw = false;

  // Lee el estado de los botones con debounce
  static unsigned long lastDebounceTime = 0;
  static const unsigned long debounceDelay = 200; // Tiempo de debounce en milisegundos

  unsigned long currentTime = millis();

  // Lee el estado del botón hacia arriba
  if (digitalRead(button_up) == LOW)
  {
    if (currentTime - lastDebounceTime > debounceDelay)
    {
      context->handleUp();
      redraw = true;
      lastDebounceTime = currentTime; // Actualiza el tiempo del último evento
    }
  }

  // Lee el estado del botón hacia abajo
  if (digitalRead(button_down) == LOW)
  {
    if (currentTime - lastDebounceTime > debounceDelay)
    {
      context->handleDown();
      redraw = true;
      lastDebounceTime = currentTime;
    }
  }

  // Lee el estado del botón de selección
  if (digitalRead(button_select) == LOW)
  {
    if (currentTime - lastDebounceTime > debounceDelay)
    {
      context->handleSelect();
      redraw = true;
      lastDebounceTime = currentTime;
    }
  }

  // Lee el estado del botón de retroceso
  if (digitalRead(button_back) == LOW)
  {
    if (currentTime - lastDebounceTime > debounceDelay)
    {
      context->handleBack();
      redraw = true;
      lastDebounceTime = currentTime;
    }
  }

  // Redibuja la pantalla si es necesario
  if (redraw)
  {
    context->displayMenu();
  }
}