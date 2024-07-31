/**
 * @file configRange_state.h
 * @author Lara Torletti (lara.a.torletti@gmail.com)
 * @brief Definición de la clase ConfigRangeState para la configuración de límites en la interfaz.
 * @version 0.1
 * @date 2024-07-29
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef CONFIGRANGE_STATE_H
#define CONFIGRANGE_STATE_H

#include "state.h"
#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

/**
 * @class ConfigRangeState
 * @brief Clase que maneja el estado de configuración de los límites en la interfaz.
 *
 * Esta clase gestiona las acciones y la visualización para la configuración del rango de valores (límite inferior y superior)
 * en la pantalla LCD. Hereda de la clase base `State` y proporciona implementaciones específicas
 * para el manejo de botones y la visualización en el LCD.
 */
class ConfigRangeState : public State
{
private:
    LiquidCrystal_I2C &lcd; ///< Referencia al objeto LCD.
    int lowerLimit;         ///< Límite inferior del rango.
    int upperLimit;         ///< Límite superior del rango.
    bool settingLowerLimit; ///< Indica si se está configurando el límite inferior o superior.
    void initializeLcd();   ///< Inicializa la pantalla LCD.
    void printLogo();       ///< Imprime el logo en la pantalla LCD.

public:
    /**
     * @brief Constructor que inicializa el LCD, los límites y el estado de configuración.
     * @param lcd Referencia al objeto LiquidCrystal_I2C.
     */
    ConfigRangeState(LiquidCrystal_I2C &lcd);

    void handleUp(Context *context) override;     ///< Maneja la acción del botón "Up".
    void handleDown(Context *context) override;   ///< Maneja la acción del botón "Down".
    void handleSelect(Context *context) override; ///< Maneja la acción del botón "Select".
    void handleBack(Context *context) override;   ///< Maneja la acción del botón "Back".
    void displayMenu(Context *context) override;  ///< Muestra el menú de configuración en la pantalla LCD.
};

#endif // CONFIGRANGE_STATE_H