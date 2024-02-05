/**
 * Decompiled version of blink_pin.elf, trying to reconstruct and see if we can 
 * recompile based on direct register defines
 * Add extra todo lines for each missing or wrongly set line
*/

//TODO: missing any imports
#include "pico/stdlib.h"
//#include "hardware/structs/sio.h"
//#include "hardware/regs/sio.h"

//TODO: original source code had a define for the led pin although this should not be vital

//TODO: main signature should not accept a void?
int main(void)

{
  //TODO: 0xf = 15
  gpio_init(0xf);
  // TODO: not sure where the IOPORT came from
  //IOPORT.GPIO_OE_SET = 0x8000;
 // *(volatile uint32_t *)(SIO_BASE + SIO_GPIO_OE_SET_OFFSET) |= 0x8000;
  *(volatile uint32_t *)(SIO_BASE.gpio_set) |= 0x8000;
  //gpio_set_dir(15,1);
  // test writing directly to hardcoded addresses
  //*(volatile uint32_t *) 0xd0000024 |= 0x8000;
  do {
    *(volatile uint32_t *) 0xd0000014 |= 0x8000;
    //*(volatile uint32_t *)(SIO_BASE + SIO_GPIO_OUT_SET_OFFSET) |= 0x8000;
    //IOPORT.GPIO_OUT_SET = 0x8000;
    //gpio_put(15, 1);
    sleep_ms(1000);
    *(volatile uint32_t *) 0xd0000018 |= 0x8000;
    //*(volatile uint32_t*)(SIO_BASE + SIO_GPIO_OUT_CLR_OFFSET) |= 0x8000;
    //IOPORT.GPIO_OUT_CLR = 0x8000;
    //gpio_put(15, 0);
    sleep_ms(1000);
  } while( true );
}
