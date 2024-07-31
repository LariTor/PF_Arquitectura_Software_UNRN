/**
 * @file custom_char.h
 * @author Lara Torletti (lara.a.torletti@gmail.com)
 * @brief Definiciones de caracteres personalizados para el LCD.
 * @version 0.1
 * @date 2024-07-01
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef CUSTOM_CHAR_H
#define CUSTOM_CHAR_H

#if defined(ARDUINO) && ARDUINO >= 100
#define printByte(args) write(args); ///< Macro para escribir un byte en el LCD
#else
#define printByte(args) print(args, BYTE); ///< Macro para imprimir un byte en el LCD en versiones antiguas de Arduino
#endif

extern uint8_t bell[];         ///< Array para el icono de la campana
extern uint8_t note[];         ///< Array para el icono de la nota musical
extern uint8_t clock[];        ///< Array para el icono del reloj
extern uint8_t heart[];        ///< Array para el icono del corazón
extern uint8_t duck[];         ///< Array para el icono del pato
extern uint8_t check[];        ///< Array para el icono de marca de verificación
extern uint8_t cross[];        ///< Array para el icono de cruz
extern uint8_t retarrow[];     ///< Array para el icono de flecha hacia atrás
extern uint8_t menu_icon[];    ///< Array para el icono del menú
extern uint8_t logo_2x2[4][8]; ///< Array para los iconos de logo en formato 2x2
extern uint8_t sample_icon[];  ///< Array para el icono de muestreo
extern uint8_t conf_icon[];    ///< Array para el icono de configuración

#endif // CUSTOM_CHAR_H