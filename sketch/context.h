/**
 * @file context.h
 * @author Lara Torletti (lara.a.torletti@gmail.com)
 * @brief Definición de la clase Context para la gestión del estado de la aplicación.
 * @version 0.1
 * @date 2024-07-01
 * @details La clase `Context` sigue el patrón de diseño de estado y actúa como un
 *          gestor central que mantiene el estado actual de la aplicación y facilita
 *          la transición entre estados. Proporciona métodos para manejar entradas y
 *          actualizar la interfaz de usuario del LCD.
 * @copyright Copyright (c) 2024
 *
 */

#ifndef CONTEXT_H
#define CONTEXT_H

#include "state.h"
#include <LiquidCrystal_I2C.h>

class State;

class Context
{
public:
    /**
     * @brief Obtiene la instancia única del Contexto.
     * @return Puntero a la instancia del Contexto.
     */
    static Context *getInstance();

    /**
     * @brief Establece el estado actual.
     * @param state Puntero al nuevo estado.
     */
    void setState(State *state);

    /**
     * @brief Maneja la entrada de botón hacia arriba.
     */
    void handleUp();

    /**
     * @brief Maneja la entrada de botón hacia abajo.
     */
    void handleDown();

    /**
     * @brief Maneja la entrada de selección de botón.
     */
    void handleSelect();

    /**
     * @brief Maneja la entrada de botón de retroceso.
     */
    void handleBack();

    /**
     * @brief Establece el límite inferior.
     * @param lowerLimit Valor del límite inferior.
     */
    void displayMenu();

    /**
     * @brief Establece el límite inferior del rango de medicion.
     * @param lowerLimit Valor del límite inferior.
     */
    void setLowerLimit(int lowerLimit);

    /**
     * @brief Obtiene el límite inferior del rango de medicion..
     * @return Valor del límite inferior.
     */
    int getLowerLimit() const;

    /**
     * @brief Establece el límite superiordel rango de medicion.
     * @param upperLimit Valor del límite superior.
     */
    void setUpperLimit(int upperLimit);

    /**
     * @brief Obtiene el límite superiordel rango de medicion.
     * @return Valor del límite superior.
     */
    int getUpperLimit() const;

    /**
     * @brief Establece el isótopo actual.
     * @param isotope Cadena con el nombre del isótopo.
     */
    void setIsotope(const char *isotope);

    /**
     * @brief Obtiene el isótopo actual.
     * @return Cadena con el nombre del isótopo.
     */
    const char *getIsotope() const;

    /**
     * @brief Obtiene el objeto de la pantalla LCD.
     * @return Referencia al objeto LCD.
     */
    LiquidCrystal_I2C &getLcd();

private:
    Context();                ///< Constructor privado para implementar el patrón Singleton
    State *currentState;      ///< Puntero al estado actual
    LiquidCrystal_I2C lcd;    ///< Objeto para controlar la pantalla LCD
    static Context *instance; ///< Instancia única del Contexto

    int lowerLimit;      ///< Límite inferior para el rango
    int upperLimit;      ///< Límite superior para el rango
    const char *isotope; ///< Nombre del isótopo actua
};

#endif // CONTEXT_H
