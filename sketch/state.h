/**
 * @file state.hpp
 * @author Lara Torletti (lara.a.torletti@gmail.com)
 * @brief Define la interfaz abstracta para los estados en la máquina de estados.
 * @version 0.1
 * @date 2024-07-01
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef STATE_H
#define STATE_H

#include "context.h"

class Context;

/**
 * @class State
 * @brief Clase base abstracta para los estados de la máquina de estados.
 *
 * Esta clase define una interfaz común que todos los estados deben implementar.
 * Los métodos virtuales puros aseguran que cada estado concrete sus propias
 * versiones de estos métodos.
 */
class State
{
public:
    // Destructor virtual para permitir la eliminación correcta de objetos derivados
    virtual ~State() {}

    /**
     * @brief Maneja la acción del botón "Up".
     * @param context Puntero al contexto actual de la máquina de estados.
     */
    virtual void handleUp(Context *context) = 0;

    /**
     * @brief Maneja la acción del botón "Down".
     * @param context Puntero al contexto actual de la máquina de estados.
     */
    virtual void handleDown(Context *context) = 0;

    /**
     * @brief Maneja la acción del botón "Select".
     * @param context Puntero al contexto actual de la máquina de estados.
     */
    virtual void handleSelect(Context *context) = 0;

    /**
     * @brief Maneja la acción del botón "Back".
     * @param context Puntero al contexto actual de la máquina de estados.
     */
    virtual void handleBack(Context *context) = 0;

    /**
     * @brief Muestra el menú o la información del estado en el LCD.
     * @param context Puntero al contexto actual de la máquina de estados.
     */
    virtual void displayMenu(Context *context) = 0;
};

#endif // STATE_H
