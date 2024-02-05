/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "pico/stdlib.h"
#include "pico/rand.h"

// Change the define here to the GPIO number that should be used for the led
#define LED_PIN 15

int main() {
    int running = 0;
    uint32_t randVal = get_rand_32();
    if (randVal % 2) {
        running = 1;
    }

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    while (running) {
        gpio_put(LED_PIN, 1);
        sleep_ms(1000);
        gpio_put(LED_PIN, 0);
        sleep_ms(1000);
    }
}