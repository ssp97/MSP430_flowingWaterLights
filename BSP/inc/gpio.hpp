#ifndef __GPIO_HPP_
#define __GPIO_HPP_

#include "bsp.hpp"

#ifdef  USE_ASSERT
  #include <assert.h>
#else
  #define assert(expr) ((void)0)
#endif


enum IO_STATE {
  IO_IN = 0,
  IO_OUT = 1,
};

class SIMPLE_GPIO{
protected:
  uint8_t Bit;
  volatile uint8_t *PxDIR,*PxOUT,*PxIN;
public:
  SIMPLE_GPIO(uint8_t px,uint8_t port,IO_STATE IoState,uint8_t State=1);
  void write(uint8_t state);
  uint8_t read();
};


#endif