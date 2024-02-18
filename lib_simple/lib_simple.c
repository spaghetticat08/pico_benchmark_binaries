/**
 * @file lib_simple.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdlib.h>

#include "pico/stdlib.h"


const uint LED_PIN = PICO_DEFAULT_LED_PIN;

void set_led_out(int new_setting) {
    gpio_put(LED_PIN, new_setting);
}

int roll_random() {
    int random_int = rand();
    if (random_int % 2 == 0) {
        // even, turn led on
        return 1;
    }
    else {
        return 0;
    }
}

void main() {
   gpio_init(LED_PIN);
   gpio_set_dir(LED_PIN, GPIO_OUT);

   //first we turn the led on and off to test its functionality
   gpio_put(LED_PIN, 1);
   sleep_ms(1000);
   gpio_put(LED_PIN, 0);
   sleep_ms(1000);

   while (true)
   {
        int led_val = roll_random();
        set_led_out(led_val);
        sleep_ms(500);
   }
   
}