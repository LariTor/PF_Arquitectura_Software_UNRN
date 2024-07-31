/**
 * @file pins.ino
 * @author Lara Torletti (lara.a.torletti@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-07-29
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "pins.h"

const int button_up = 10;
const int button_down = 11;
const int button_select = 6;
const int button_back = 7;

const int led_red = 12;
const int led_yellow = 13;

const int buzzer = 4;

void initPins()
{
    pinMode(button_up, INPUT);
    pinMode(button_down, INPUT);
    pinMode(button_select, INPUT);
    pinMode(button_back, INPUT);

    pinMode(led_red, OUTPUT);
    pinMode(led_yellow, OUTPUT);
    pinMode(buzzer, OUTPUT);
}