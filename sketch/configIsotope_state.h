/**
 * @file configIsotope_state.h
 * @author Lara Torletti (lara.a.torletti@gmail.com)
 * @brief Definición de la clase ConfigIsotopeState para la configuración del isótopo en la interfaz.
 * @version 0.1
 * @date 2024-07-01
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef CONFIGISOTOPE_STATE_H
#define CONFIGISOTOPE_STATE_H

#include "state.h"
#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

/**
 * @class ConfigIsotopeState
 * @brief Clase que maneja el estado de configuración del isótopo en la interfaz.
 *
 * Esta clase gestiona las acciones y la visualización para la selección de isótopos en la pantalla LCD.
 * Hereda de la clase base `State` y proporciona implementaciones específicas
 * para el manejo de botones y la visualización en el LCD.
 */
class ConfigIsotopeState : public State
{
private:
    LiquidCrystal_I2C &lcd;         ///< Referencia al objeto LCD.
    int currentIndex;               ///< Índice del elemento seleccionado en el menú.
    static const char *menuItems[]; ///< Elementos del menú para selección de isótopos.
    static const int menuLength;    ///< Longitud del menú.

    void initializeLcd(); ///< Inicializa la pantalla LCD.
    void printLogo();     ///< Imprime el logo en la pantalla LCD.

public:
    /**
     * @brief Constructor que inicializa el LCD y el índice del menú.
     * @param lcd Referencia al objeto LiquidCrystal_I2C.
     */
    ConfigIsotopeState(LiquidCrystal_I2C &lcd);

    void handleUp(Context *context) override;     ///< Maneja la acción del botón "Up".
    void handleDown(Context *context) override;   ///< Maneja la acción del botón "Down".
    void handleSelect(Context *context) override; ///< Maneja la acción del botón "Select".
    void handleBack(Context *context) override;   ///< Maneja la acción del botón "Back".
    void displayMenu(Context *context) override;  ///< Muestra el menú en la pantalla LCD.
};

#endif // CONFIGISOTOPE_STATE_H