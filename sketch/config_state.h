/**
 * @file config_state.h
 * @author Lara Torletti (lara.a.torletti@gmail.com)
 * @brief Declaración de la clase ConfigState y sus miembros.
 *
 * @details Esta clase maneja el estado de configuración en una máquina de estados para un sistema basado en Arduino.
 *          Proporciona la interfaz y los métodos necesarios para gestionar el menú de configuración del sistema.
 *
 * @version 0.1
 * @date 2024-07-1
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef CONFIG_STATE_H
#define CONFIG_STATE_H

#include "state.h"
#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

/**
 * @class ConfigState
 * @brief Clase que representa el estado de configuración del sistema.
 */
class ConfigState : public State
{
public:
    /**
     * @brief Constructor de la clase ConfigState.
     *
     * @param lcd Referencia a un objeto LiquidCrystal_I2C para el control del LCD.
     */
    ConfigState(LiquidCrystal_I2C &lcd);

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
     * @brief Muestra el menú de configuración en el LCD.
     *
     * @param context Puntero al contexto de la máquina de estados.
     */
    void displayMenu(Context *context) override;

private:
    int currentIndex;       ///< Índice del ítem de menú actualmente seleccionado.
    LiquidCrystal_I2C &lcd; ///< Referencia al objeto LiquidCrystal_I2C para el control del LCD.

    /**
     * @brief Inicializa las variables y pantalla.
     */
    void initializeLcd();

    /**
     * @brief Imprime el logo en la pantalla LCD.
     */
    void printLogo();

    static const char *menuItems[]; ///< Arreglo de cadenas que contiene los ítems del menú de configuración.
    static const int menuLength;    ///< Longitud del menú de configuración.
};

#endif // CONFIG_STATE_H
