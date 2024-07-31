/**
 * @file custom_char.h
 * @author Lara Torletti (lara.a.torletti@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-07-29
 *
 * @copyright Copyright (c) 2024
 *
 */

#if defined(ARDUINO) && ARDUINO >= 100
#define printByte(args) write(args);
#else
#define printByte(args) print(args, BYTE);
#endif

extern uint8_t bell[];
extern uint8_t note[];
extern uint8_t clock[];
extern uint8_t heart[];
extern uint8_t duck[];
extern uint8_t check[];
extern uint8_t cross[];
extern uint8_t retarrow[];
extern uint8_t menu_icon[];
extern uint8_t logo_2x2[4][8];
extern uint8_t sample_icon[];
extern uint8_t conf_icon[];