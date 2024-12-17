#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define BUTTON_PIN 15
#define LED_PIN 16

void gpio_callback(uint gpio, uint32_t events)
{
    printf("Interrupt triggered!\n");
    if (gpio_get(LED_PIN) == 0){
        gpio_put(LED_PIN, 1);
    } else {
        gpio_put(LED_PIN, 0);
    }
}

int main()
{
    gpio_init(BUTTON_PIN);
    gpio_init(LED_PIN);

    gpio_set_dir(LED_PIN, 1);
    gpio_set_dir(BUTTON_PIN, 0);
    gpio_pull_up(BUTTON_PIN);
    gpio_set_irq_enabled_with_callback(BUTTON_PIN, GPIO_IRQ_EDGE_FALL, true, &gpio_callback);

    while (true)
    {
        sleep_ms(1000);
    }
    

}