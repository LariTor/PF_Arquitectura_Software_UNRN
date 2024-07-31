/**
 * @file custom_char.ino
 * @author Lara Torletti (lara.a.torletti@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-07-29
 *
 * @copyright Copyright (c) 2024
 *
 */

uint8_t bell[8] = {0x4, 0xe, 0xe, 0xe, 0x1f, 0x0, 0x4};
uint8_t note[8] = {0x2, 0x3, 0x2, 0xe, 0x1e, 0xc, 0x0};
uint8_t clock[8] = {0x0, 0xe, 0x15, 0x17, 0x11, 0xe, 0x0};
uint8_t heart[8] = {0x0, 0xa, 0x1f, 0x1f, 0xe, 0x4, 0x0};
uint8_t duck[8] = {0x0, 0xc, 0x1d, 0xf, 0xf, 0x6, 0x0};
uint8_t check[8] = {0x0, 0x1, 0x3, 0x16, 0x1c, 0x8, 0x0};
uint8_t cross[8] = {0x0, 0x1b, 0xe, 0x4, 0xe, 0x1b, 0x0};
uint8_t retarrow[8] = {0x1, 0x1, 0x5, 0x9, 0x1f, 0x8, 0x4};
uint8_t menu_icon[8] = {0x00, 0x00, 0x0E, 0x00, 0x0E, 0x00, 0x0E, 0x00};
uint8_t sample_icon[8] = {0x10, 0x11, 0x12, 0x14, 0x14, 0x18, 0x1F, 0x00};
uint8_t conf_icon[8] = {0x04, 0x15, 0x0A, 0x11, 0x0A, 0x15, 0x04, 0x00};

uint8_t logo_2x2[4][8] = {
    {0x0, 0x0, 0x0, 0x7, 0xC, 0x18, 0x10, 0x10},
    {0x0, 0x0, 0x0, 0x4, 0x4, 0x1F, 0x4, 0x4},
    {0x10, 0x10, 0x18, 0xC, 0x7, 0x0, 0x0, 0x0},
    {0x1F, 0x5, 0x5, 0xC, 0x18, 0x0, 0x0, 0x0}};
