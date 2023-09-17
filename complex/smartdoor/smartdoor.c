/**
 * Copyright (c) 2023 mjcross
 *
 * SPDX-License-Identifier: BSD-3-Clause
 **/

#include "pico/stdlib.h"


int main() {

    // initialize rfid reader

    // initialize stepper motor

    // stepper motor locks the door

    // we need to add interrupts so when the rfid card is tapped
    // that we get a signal to open the door

    // after opening the door we start a timer of 30 sec until we close the door
    // For every time the card is tapped during those 30 sec, the timer will restart
}