#include "gpio.hpp"


SIMPLE_GPIO::SIMPLE_GPIO(uint8_t px,uint8_t port,IO_STATE IoState,uint8_t state){
  assert(px<=4);
  assert(port<=7);
  switch(px){
  case P1:
    PxDIR = &P1DIR; PxOUT = &P1OUT; PxIN = &P1IN; break;
  case P2:
    PxDIR = &P2DIR; PxOUT = &P2OUT; PxIN = &P2IN; break;
  case P3:
    PxDIR = &P3DIR; PxOUT = &P3OUT; PxIN = &P3IN; break;
  case P4:
    PxDIR = &P4DIR; PxOUT = &P4OUT; PxIN = &P4IN; break;
  }
  Bit = 1<<port;
  (IoState==IO_OUT)?*PxDIR|=Bit:*PxDIR&=~Bit;
  if(!state) write(0);
  else write(1);
}

void SIMPLE_GPIO::write(uint8_t state){
  state?*PxOUT|=Bit:*PxOUT&=~Bit; //x?1:0;
}

uint8_t SIMPLE_GPIO::read(){
  return ((*PxIN&Bit)==Bit);
}

