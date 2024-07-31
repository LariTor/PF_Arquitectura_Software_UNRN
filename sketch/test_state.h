/**
 * @file test_state.h
 * @author Lara Torletti (lara.a.torletti@gmail.com)
 * @brief Definición de la clase TestState para gestionar una ventana de prueba en la interfaz.
 * @version 0.1
 * @date 2024-07-29
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef TEST_STATE_H
#define TEST_STATE_H

#include "state.h"
#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

/**
 * @class TestState
 * @brief Clase que maneja el estado de prueba en la interfaz.
 *
 * Esta clase gestiona las acciones y la visualización para una ventana de prueba.
 * Hereda de la clase base `State` y proporciona implementaciones específicas
 * para el manejo de botones y la visualización en el LCD.
 */
class TestState : public State
{
public:
    /**
     * @brief Constructor que inicializa el LCD.
     * @param lcd Referencia al objeto LiquidCrystal_I2C.
     */
    TestState(LiquidCrystal_I2C &lcd);

    void handleUp(Context *context) override;     ///< Maneja la acción del botón "Up".
    void handleDown(Context *context) override;   ///< Maneja la acción del botón "Down".
    void handleSelect(Context *context) override; ///< Maneja la acción del botón "Select".
    void handleBack(Context *context) override;   ///< Maneja la acción del botón "Back".
    void displayMenu(Context *context) override;  ///< Muestra el menú en la pantalla LCD.

private:
    LiquidCrystal_I2C &lcd; ///< Referencia al objeto LCD.
    void initializeLcd();   ///< Inicializa la pantalla LCD.
    void printLogo();       ///< Imprime el logo en la pantalla LCD.
};

#endif // TEST_STATE_H