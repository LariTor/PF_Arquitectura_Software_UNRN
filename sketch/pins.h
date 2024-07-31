/**
 * @file pins.h
 * @author Lara Torletti (lara.a.torletti@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-07-29
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <LiquidCrystal_I2C.h>

extern const int button_up;     // Botón para abajo
extern const int button_down;   // Botón para arriba
extern const int button_select; // Botón para seleccionar
extern const int button_back;   // Botón para regresar

extern const int led_red;
extern const int led_yellow;

extern const int buzzer;

void initPins();