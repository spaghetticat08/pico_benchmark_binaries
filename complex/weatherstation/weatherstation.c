/**
 * Copyright (c) 2023 mjcross
 *
 * SPDX-License-Identifier: BSD-3-Clause
 **/

#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"

#include "lcd_library/lcd_1602_i2c.h"
#include "bmp_library/bmp280_i2c.h"


int main() {

// First we will initialize the lcd display and send a test message
#if !defined(i2c_default) || !defined(PICO_DEFAULT_I2C_SDA_PIN) || !defined(PICO_DEFAULT_I2C_SCL_PIN)
    #warning i2c/lcd_1602_i2c and bmp280_i2c example requires a board with I2C pins
        puts("Default I2C pins were not defined");
    return 0;
#else
    i2c_init(i2c_default, 100 * 1000);
    gpio_set_function(PICO_DEFAULT_I2C_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(PICO_DEFAULT_I2C_SDA_PIN);
    gpio_pull_up(PICO_DEFAULT_I2C_SCL_PIN);

    bi_decl(bi_2pins_with_func(PICO_DEFAULT_I2C_SDA_PIN, PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C));
    lcd_init();

    static char *message[] =
            {
                "RP2040 by", "Raspberry Pi",
                "Testing lcd", "screen",
                "succesfull if", "you see this!"
            };

    for (int m = 0; m < sizeof(message) / sizeof(message[0]); m += MAX_LINES) {
        for (int line = 0; line < MAX_LINES; line++) {
            lcd_set_cursor(line, (MAX_CHARS / 2) - strlen(message[m + line]) / 2);
            lcd_string(message[m + line]);
        }
        sleep_ms(2000);
        lcd_clear();
    }

    sleep_ms(1000);
    // Initialize our sensors and ensure they are functioning

    bmp280_init();
    struct bmp280_calib_param params;
    bmp280_get_calib_params(&params);

    int32_t raw_temperature;
    int32_t raw_pressure;

    sleep_ms(250);
    // initial read of temperature and pressure
    bmp280_read_raw(&raw_temperature, &raw_pressure);
    int32_t temperature = bmp280_convert_temp(raw_temperature, &params);
    int32_t pressure = bmp280_convert_pressure(raw_pressure, raw_temperature, &params);
    printf("Pressure = %.3f kPa\n", pressure / 1000.f);
    printf("Temp. = %.2f C\n", temperature / 100.f);
    // With an interval of 5 seconds we retrieve the sensor data and display 
    // this on the lcd screen

    while (1)
    {
        bmp280_read_raw(&raw_temperature, &raw_pressure);
        int32_t temperature = bmp280_convert_temp(raw_temperature, &params);
        int32_t pressure = bmp280_convert_pressure(raw_pressure, raw_temperature, &params);

        char str_pressure[10];
        char str_temperature[8];
        //snprintf(str_pressure, sizeof(str_pressure), "%.3f", pressure / 1000.f);
        //snprintf(str_temperature, sizeof(str_temperature), "%.2f", temperature / 100.f);
        memcpy(str_pressure, (void*) pressure , sizeof(pressure)+1);
        memcpy(str_temperature, (void*) temperature, sizeof(temperature)+1);

        char *weather_message[] = 
                {
                    "Pressure =", str_pressure, 
                    "Temperature = ", str_temperature
                };

        for (int m = 0; m < sizeof(message) / sizeof(message[0]); m += MAX_LINES) {
            for (int line = 0; line < MAX_LINES; line++) {
                lcd_set_cursor(line, (MAX_CHARS / 2) - strlen(message[m + line]) / 2);
                lcd_string(message[m + line]);
            }
            sleep_ms(2000);
            lcd_clear();
        }

    sleep_ms(5000);
    }
#endif
}