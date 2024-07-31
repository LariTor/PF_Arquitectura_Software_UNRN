/**
 * @file waitingsample_state.h
 * @author Lara Torletti (lara.a.torletti@gmail.com)
 * @brief Definición de la clase WaitingSampleState para gestionar el estado de espera antes del muestreo.
 * @version 0.1
 * @date 2024-07-01
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef WAITINGSAMPLE_STATE_H
#define WAITINGSAMPLE_STATE_H

#include "state.h"
#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

/**
 * @class WaitingSampleState
 * @brief Clase que maneja el estado de espera antes de iniciar el muestreo.
 *
 * Esta clase gestiona las acciones y la visualización del estado de espera.
 * Hereda de la clase base `State` y proporciona implementaciones específicas
 * para el manejo de botones y la visualización en el LCD.
 */
class WaitingSampleState : public State
{
private:
    int currentIndex;       ///< Índice actual (no utilizado en esta implementación).
    LiquidCrystal_I2C &lcd; ///< Referencia al objeto LCD.

    void initializeLcd(); ///< Inicializa la pantalla LCD.
    void printLogo();     ///< Imprime el logo en la pantalla LCD.

public:
    WaitingSampleState(LiquidCrystal_I2C &lcd); ///< Constructor que inicializa el LCD.

    void handleUp(Context *context) override;     ///< Maneja la acción del botón "Up".
    void handleDown(Context *context) override;   ///< Maneja la acción del botón "Down".
    void handleSelect(Context *context) override; ///< Maneja la acción del botón "Select".
    void handleBack(Context *context) override;   ///< Maneja la acción del botón "Back".
    void displayMenu(Context *context) override;  ///< Muestra el menú en la pantalla LCD.
};

#endif // WAITINGSAMPLE_STATE_H