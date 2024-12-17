/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 * 
 * SPDX-License-Identifier: BSD-3-Clause
*/

#include <stdio.h>
#include "pico/stdlib.h"


int main() {
    char str[50];

    printf("Please enter your message:\n");

    if (scanf("%s", str) != 0){
        printf("Echo: %s\n", str);
    }

    return 0;
}