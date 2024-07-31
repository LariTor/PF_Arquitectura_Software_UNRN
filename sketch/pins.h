/**
 * @file pins.h
 * @author Lara Torletti (lara.a.torletti@gmail.com)
 * @brief Declaración de pines y funciones de inicialización para el sistema.
 * @version 0.1
 * @date 2024-07-01
 *@details Este archivo contiene las declaraciones de los pines utilizados en el sistema,
 *          así como la función para inicializarlos. Está diseñado para ser utilizado en un
 *          proyecto basado en Arduino.
 * @copyright Copyright (c) 2024
 *
 */

#ifndef PINS_H
#define PINS_H

#include <LiquidCrystal_I2C.h>

extern const int button_up;     ///< Pin del botón para subir
extern const int button_down;   ///< Pin del botón para bajar
extern const int button_select; ///< Pin del botón para seleccionar
extern const int button_back;   ///< Pin del botón para regresar

extern const int led_red;    ///< Pin del LED rojo
extern const int led_yellow; ///< Pin del LED amarillo

extern const int buzzer; ///< Pin del buzzer

/**
 * @brief Inicializa los pines configurándolos como entradas o salidas según corresponda.
 */
void initPins();

#endif // PINS_H