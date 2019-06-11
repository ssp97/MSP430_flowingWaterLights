#include "bsp.hpp"

/*
LED:
  LED R P40 LOW
  LED G P12 LOW
  LED B P20 LOW
*/

SIMPLE_GPIO LED_R(P4,0,IO_OUT);
SIMPLE_GPIO LED_G(P1,2,IO_OUT);
SIMPLE_GPIO LED_B(P2,0,IO_OUT);

int main( void )
{
  WDTCTL = WDTPW + WDTHOLD;//¹Øµô¿´ÃÅ¹·

  while(1){
    LED_R.write(0);
    delay_ms(1000);
    LED_R.write(1);
    delay_ms(1000);
    LED_G.write(0);
    delay_ms(1000);
    LED_G.write(1);
    delay_ms(1000);
    LED_B.write(0);
    delay_ms(1000);
    LED_B.write(1);
    delay_ms(1000);
  }
  return 0;
}
