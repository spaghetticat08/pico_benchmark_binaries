/**
 * Copyright (c) 2023 mjcross
 *
 * SPDX-License-Identifier: BSD-3-Clause
 **/

#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/pio.h"

#include "onewire_library.h"


/**
 * @brief Create a driver instance and populate the provided OW structure
 * 
 * @param ow A pointer to a blank OW structure to hold the driver parameters.
 * @param pio The PIO hardware instance to use.
 * @param offset The location of the onewire program in the PIO shared address space
 * @param gpio The pin to use for the bus
 * @return true on success
 * @return false 
 */
bool ow_init(OW *ow, PIO pio, uint offset, uint gpio) {
    int sm = pio_claim_unused_sm(pio, false);
    if (sm == -1) {
        return false;
    }

    gpio_init(gpio);
    pio_gpio_init(pio, gpio);
    ow->gpio = gpio;
    ow->pio = pio;
    ow->offset = offset;
    ow->sm = (uint)sm;
    ow->jmp_reset = onewire_reset_instr(ow->offset); // assemble the bus reset instruction
    onewire_sm_init(ow->pio, ow->sm, ow->offset, ow->gpio, 8); // set 8 bits per word
    return true;
}

/**
 * @brief Send a binary word on the bus (LSB first)
 * 
 * @param ow A pointer to an OW driver struct
 * @param data The word to be sent
 */
void ow_send(OW *ow, uint data){
    pio_sm_put_blocking(ow->pio, ow->sm, (uint32_t)data);
    pio_sm_get_blocking(ow->pio, ow->sm); //discard the response
}

/**
 * @brief Read a binary word from the bus
 * 
 * @param ow the word read (LSB first)
 * @return uint8_t pointer to an OW driver struct
 */
uint8_t ow_read(OW *ow) {
    pio_sm_put_blocking(ow->pio, ow->sm, 0xff);
    return (uint8_t) (pio_sm_get_blocking(ow->pio, ow->sm) >> 24); // shift response into bits 0..7
}

/**
 * @brief Reset the bus and detect any connected slaves
 * 
 * @param ow pointer to an OW driver struct
 * @return true if any slaves responded
 * @return false 
 */
bool ow_reset(OW *ow) {
    pio_sm_exec_wait_blocking(ow->pio, ow->sm, ow->jmp_reset);
    if ((pio_sm_get_blocking(ow->pio, ow->sm) & 1) == 0) {
        return true; // slave pulled the bus low
    }
    return false;
}

/**
 * @brief Find ROM codes (64 bit hardware addresses) of all connected devices
 * 
 * @param ow pointer to an OW driver struct
 * @param romcodes location at which store the addresses
 * @param maxdevs maximum number of devices to find (0 means no limit)
 * @param command 1-Wire search command (OW_SEARCHROM or OW_ALARM_SEARCH)
 * @return int the number of devices found or -1 if error occurred
 */
int ow_romsearch(OW *ow, uint64_t *romcodes, int maxdevs, uint command) {
    int index;
    uint64_t romcode = 0ull;
    int branch_point;
    int next_branch_point = -1;
    int num_found = 0;
    bool finished = false;

    onewire_sm_init(ow->pio, ow->sm, ow->offset, ow->gpio, 1); // set driver to 1-bit mode

    while (finished == false && (maxdevs == 0 || num_found < maxdevs)) 
    {
        finished = true;
        branch_point = next_branch_point;
        if(ow_reset(ow) == false) {
            num_found = 0; // no slaves present
            finished = true;
            break;
        }
        for(int i = 0; i < 8; i += 1) { // send search command as single bits
            ow_send(ow, command >> i);
        }
        for(index = 0; index < 64; index += 1) { // determine romcode bits 0..63
            uint a = ow_read(ow);
            uint b = ow_read(ow);
            if (a == 0 && b == 0) {
                if (index == branch_point) {
                    ow_send(ow, 1);
                    romcode |= (1ull << index);
                } else {
                    if (index > branch_point || (romcode & (1ull << index)) == 0) {
                        ow_send(ow, 0);
                        finished = false;
                        romcode &= ~(1ull << index);
                        next_branch_point = index;
                    } else {
                        ow_send(ow, 1);
                    }
                }
            } else if (a != 0 && b != 0) {
                num_found = -2;
                finished = true;
                break;
            } else {
                if (a == 0) {
                    ow_send(ow, 0);
                    romcode &= ~(1ull << index);
                } else {
                    ow_send(ow, 1);
                    romcode |= (1ull << index);
                }
            }
        }

        if (romcodes != NULL) {
            romcodes[num_found] = romcode;
        }
        num_found += 1;
    }

    onewire_sm_init(ow->pio, ow->sm, ow->offset, ow->gpio, 8);
    return num_found;
}