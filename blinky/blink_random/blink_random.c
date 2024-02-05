#include "pico/stdlib.h"
#include <stdio.h>

int main() {

    int led_pin_nr;

    printf("Enter a number for the GPIO to blink the LED:\n");
    scanf("%d", &led_pin_nr);

    gpio_init(led_pin_nr);
    gpio_set_dir(led_pin_nr, GPIO_OUT);

    while(true) {
        gpio_put(led_pin_nr, 1);
        sleep_ms(1000);
        gpio_put(led_pin_nr, 0);
        sleep_ms(1000);
    }
}