/**
 * @file errorSample_state.h
 * @author Lara Torletti (lara.a.torletti@gmail.com)
 * @brief Definición de la clase `ErrorSampleState`, que representa el estado de error en el muestreo.
 * @version 0.1
 * @date 2024-07-01
 * @details La clase `ErrorSampleState` maneja el estado en el que se detecta un error durante
 *          el muestreo. Hereda de `State` y proporciona métodos para manejar las entradas
 *          del usuario y actualizar la pantalla LCD en caso de error.
 * @copyright Copyright (c) 2024
 *
 */

#ifndef ERRORSAMPLE_STATE_H
#define ERRORSAMPLE_STATE_H

#include "state.h"
#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

/**
 * @class ErrorSampleState
 * @brief Clase que representa el estado de error en el muestreo.
 *
 * Hereda de `State` y se encarga de manejar las acciones específicas y la visualización
 * en el LCD cuando ocurre un error en el proceso de muestreo.
 */
class ErrorSampleState : public State
{
private:
    LiquidCrystal_I2C &lcd; ///< Referencia al objeto `LiquidCrystal_I2C`

    /**
     * @brief Inicializa la pantalla LCD para el estado de error.
     */
    void initializeLcd();

    /**
     * @brief Imprime el logotipo en la pantalla LCD.
     */
    void printLogo();

public:
    /**
     * @brief Constructor de `ErrorSampleState`.
     * @param lcd Referencia al objeto `LiquidCrystal_I2C` para controlar la pantalla LCD.
     */
    ErrorSampleState(LiquidCrystal_I2C &lcd);

    /**
     * @brief Maneja la entrada de botón hacia arriba.
     * @param context Puntero al objeto `Context` que gestiona el estado.
     */
    void handleUp(Context *context) override;

    /**
     * @brief Maneja la entrada de botón hacia abajo.
     * @param context Puntero al objeto `Context` que gestiona el estado.
     */
    void handleDown(Context *context) override;

    /**
     * @brief Maneja la entrada de selección de botón.
     * @param context Puntero al objeto `Context` que gestiona el estado.
     */
    void handleSelect(Context *context) override;

    /**
     * @brief Maneja la entrada de botón de retroceso.
     * @param context Puntero al objeto `Context` que gestiona el estado.
     */
    void handleBack(Context *context) override;

    /**
     * @brief Muestra la información del estado de error en la pantalla LCD.
     * @param context Puntero al objeto `Context` que gestiona el estado.
     */
    void displayMenu(Context *context) override;
};

#endif // ERRORSAMPLE_STATE_H