/**
 * @file sampling_state.h
 * @author Lara Torletti (lara.a.torletti@gmail.com)
 * @brief Definición de la clase SamplingState para gestionar el estado de muestreo.
 * @version 0.1
 * @version 0.1
 * @date 2024-07-01
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SAMPLING_STATE_H
#define SAMPLING_STATE_H

#include "state.h"
#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

/**
 * @class SamplingState
 * @brief Clase que maneja el estado de muestreo en la máquina de estados.
 *
 * Esta clase gestiona las acciones y la visualización del estado de muestreo.
 * Hereda de la clase base `State` y proporciona implementaciones específicas
 * para el manejo de botones y la visualización en el LCD.
 */
class SamplingState : public State
{
private:
    int currentIndex;                              ///< Índice actual para el muestreo.
    LiquidCrystal_I2C &lcd;                        ///< Referencia al objeto LCD.
    void initializeLcd();                          ///< Inicializa la pantalla LCD.
    void printLogo();                              ///< Imprime el logo en la pantalla LCD.
    void buzzerFunc(int value, int Rlow, int Rup); ///< Controla el buzzer basado en el valor de muestreo.
    void countNumbersInRange(Context *contex);     ///< Cuenta los números en el rango definido.
    void SamplingState::updateLCD(int count);      ///< Actualiza la pantalla LCD con el conteo de números.

public:
    SamplingState(LiquidCrystal_I2C &lcd); ///< Constructor que inicializa el LCD.

    void handleUp(Context *context) override;     ///< Maneja la acción del botón "Up".
    void handleDown(Context *context) override;   ///< Maneja la acción del botón "Down".
    void handleSelect(Context *context) override; ///< Maneja la acción del botón "Select".
    void handleBack(Context *context) override;   ///< Maneja la acción del botón "Back".
    void displayMenu(Context *context) override;  ///< Muestra el menú en la pantalla LCD.
};

#endif // SAMPLING_STATE_H