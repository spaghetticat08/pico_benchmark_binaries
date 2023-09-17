/**
 * Copyright (c) 2023 mjcross
 *
 * SPDX-License-Identifier: BSD-3-Clause
 **/

#include "pico/stdlib.h"

#define TL_NORTH_RED 2
#define TL_NORTH_GREEN 3
#define TL_WEST_RED 4
#define TL_WEST_GREEN 5
#define TL_SOUTH_RED 6
#define TL_SOUTH_GREEN 7
#define TL_EAST_RED 8
#define TL_EAST_GREEN 9

enum State {
    TL_STATE_NORTH_GREEN,
    TL_STATE_WEST_GREEN,
    TL_STATE_SOUTH_GREEN,
    TL_STATE_EAST_GREEN,
    TL_STATE_ANY_YELLOW,
    TL_STATE_ALL_RED
};


int main() {
    enum State current_state = TL_STATE_ALL_RED;

    gpio_init(TL_NORTH_RED);
    gpio_init(TL_NORTH_GREEN);
    gpio_init(TL_WEST_RED);
    gpio_init(TL_WEST_GREEN);
    gpio_init(TL_SOUTH_RED);
    gpio_init(TL_SOUTH_GREEN);
    gpio_init(TL_EAST_RED);
    gpio_init(TL_EAST_GREEN);
    gpio_set_dir(TL_NORTH_RED, GPIO_OUT);
    gpio_set_dir(TL_NORTH_GREEN, GPIO_OUT);
    gpio_set_dir(TL_WEST_RED, GPIO_OUT);
    gpio_set_dir(TL_WEST_GREEN, GPIO_OUT);
    gpio_set_dir(TL_SOUTH_RED, GPIO_OUT);
    gpio_set_dir(TL_SOUTH_GREEN, GPIO_OUT);
    gpio_set_dir(TL_EAST_RED, GPIO_OUT);
    gpio_set_dir(TL_EAST_GREEN, GPIO_OUT);
    sleep_ms(1000);


    while (1)
    {
        switch (current_state)
        {
        case TL_STATE_ALL_RED:
            gpio_put(TL_NORTH_GREEN, 0);
            gpio_put(TL_WEST_GREEN, 0);
            gpio_put(TL_SOUTH_GREEN, 0);
            gpio_put(TL_EAST_GREEN, 0);
            gpio_put(TL_NORTH_RED, 1);
            gpio_put(TL_WEST_RED, 1);
            gpio_put(TL_SOUTH_RED, 1);
            gpio_put(TL_EAST_RED, 1);
            
            current_state = TL_STATE_NORTH_GREEN;

            break;
        case TL_STATE_NORTH_GREEN:
            gpio_put(TL_NORTH_GREEN, 1);
            gpio_put(TL_NORTH_RED, 0);

            current_state = TL_STATE_WEST_GREEN;
            break;
        case TL_STATE_WEST_GREEN:
            gpio_put(TL_NORTH_GREEN, 0);
            gpio_put(TL_NORTH_RED, 1);
            gpio_put(TL_WEST_RED, 0);
            gpio_put(TL_WEST_GREEN, 1);

            current_state = TL_STATE_SOUTH_GREEN;
            break;
        case TL_STATE_SOUTH_GREEN:
            gpio_put(TL_WEST_GREEN, 0);
            gpio_put(TL_WEST_RED, 1);
            gpio_put(TL_SOUTH_RED, 0);
            gpio_put(TL_SOUTH_GREEN, 1);

            current_state = TL_STATE_EAST_GREEN;
            break;
        case TL_STATE_EAST_GREEN:
            gpio_put(TL_WEST_GREEN, 0);
            gpio_put(TL_SOUTH_RED, 1);
            gpio_put(TL_EAST_RED, 0);
            gpio_put(TL_EAST_GREEN, 1);

            current_state = TL_STATE_ALL_RED;
            break;

        default:
            break;
        }

        sleep_ms(5000);
    }
    

}