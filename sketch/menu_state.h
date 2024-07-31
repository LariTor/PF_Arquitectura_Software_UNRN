/**
 * @file menu_state.h
 * @author Lara Torletti (lara.a.torletti@gmail.com)
 * @brief Declaración de la clase MenuState y sus miembros.
 * @version 0.1
 * @date 2024-07-01
 * @details Esta clase maneja el estado del menú en una máquina de estados para un sistema basado en Arduino.
 *          Proporciona la interfaz y los métodos necesarios para gestionar el menú principal del sistema.
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef MENU_STATE_H
#define MENU_STATE_H

#include "state.h"
#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

/**
 * @class MenuState
 * @brief Clase que representa el estado del menú del sistema.
 */
class MenuState : public State
{
public:
    /**
     * @brief Constructor de la clase MenuState.
     *
     * @param lcd Referencia a un objeto LiquidCrystal_I2C para el control del LCD.
     */
    MenuState(LiquidCrystal_I2C &lcd);

    /**
     * @brief Maneja el evento de pulsar el botón hacia arriba.
     *
     * @param context Puntero al contexto de la máquina de estados.
     */
    void handleUp(Context *context) override;

    /**
     * @brief Maneja el evento de pulsar el botón hacia abajo.
     *
     * @param context Puntero al contexto de la máquina de estados.
     */
    void handleDown(Context *context) override;

    /**
     * @brief Maneja el evento de pulsar el botón de selección.
     *
     * @param context Puntero al contexto de la máquina de estados.
     */
    void handleSelect(Context *context) override;

    /**
     * @brief Maneja el evento de pulsar el botón de retroceso.
     *
     * @param context Puntero al contexto de la máquina de estados.
     */
    void handleBack(Context *context) override;

    /**
     * @brief Muestra el menú principal en el LCD.
     *
     * @param context Puntero al contexto de la máquina de estados.
     */
    void displayMenu(Context *context) override;

private:
    int currentIndex;       ///< Índice actual del menú.
    LiquidCrystal_I2C &lcd; ///< Referencia al objeto LiquidCrystal_I2C para el control del LCD.

    /**
     * @brief Inicializa la pantalla LCD.
     */
    void initializeLcd();

    /**
     * @brief Imprime el logo en la pantalla LCD.
     */
    void printLogo();
    static const char *menuItems[]; ///< Elementos del menú.
    static const int menuLength;    ///< Longitud del menú.
};

#endif // MENU_STATE_H
