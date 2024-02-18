
/* WARNING: Unknown calling convention */

int main(void)

{
  gpio_init(0xf);
  IOPORT.GPIO_OE_SET = 0x8000;
  do {
    IOPORT.GPIO_OUT_SET = 0x8000;
    sleep_ms(1000);
    IOPORT.GPIO_OUT_CLR = 0x8000;
    sleep_ms(1000);
  } while( true );
}

