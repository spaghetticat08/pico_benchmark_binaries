#include "pico/stdlib.h"
#include "pico/rand.h"
#include <stdio.h>


int gpio_led_arr[9] = {6, 7, 8, 11, 12, 13, 19, 20, 21};

int main() {

    for (int i = 0; i < 9; i++)
    {
        gpio_init(gpio_led_arr[i]);
        gpio_set_dir(gpio_led_arr[i], GPIO_OUT);
    }

    while(true) {

        uint8_t randValue = (uint8_t)get_rand_32();
        int randLedValue = randValue % 9;

        gpio_put(randLedValue, 1);
        sleep_ms(1000);
        gpio_put(randLedValue, 0);
        sleep_ms(1000);
    }
}