/**
 * @file init_state.h
 * @author Lara Torletti (lara.a.torletti@gmail.com)
 * @brief Declaración de la clase InitState y sus miembros.
 * @version 0.1
 * @date 2024-07-1
 * @details Esta clase maneja el estado de inicialización en una máquina de estados para un sistema basado en Arduino.
 *          Proporciona la interfaz y los métodos necesarios para gestionar la pantalla de bienvenida del sistema.
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef INIT_STATE_H
#define INIT_STATE_H

#include "state.h"
#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

/**
 * @class InitState
 * @brief Clase que representa el estado de inicialización del sistema.
 */
class InitState : public State
{
public:
    /**
     * @brief Constructor de la clase InitState.
     *
     * @param lcd Referencia a un objeto LiquidCrystal_I2C para el control del LCD.
     */
    InitState(LiquidCrystal_I2C &lcd);

    void handleUp(Context *context) override;   ///< No action needed
    void handleDown(Context *context) override; ///< No action needed

    /**
     * @brief Maneja el evento de pulsar el botón de selección.
     *
     * @param context Puntero al contexto de la máquina de estados.
     */
    void handleSelect(Context *context) override;
    void handleBack(Context *context) override; ///< No action needed

    /**
     * @brief Muestra el menú de inicialización en el LCD.
     *
     * @param context Puntero al contexto de la máquina de estados.
     */
    void displayMenu(Context *context) override;

private:
    LiquidCrystal_I2C &lcd; ///< Referencia al objeto LiquidCrystal_I2C para el control del LCD.

    /**
     * @brief Inicializa las variables y pantalla.
     */
    void initializeLcd();

    /**
     * @brief Imprime el logo en la pantalla LCD.
     */
    void printLogo();
};

#endif // INIT_STATE_H