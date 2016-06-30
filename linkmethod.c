#ifndef INCLUDE_LSE
#define INCLUDE_LSE

#include <stdio.h>
#include <stdlib.h>
#include "linkmethod.h"
#include "MTrand.h"

int howlink(void){

  int boo = MTrand();
  //printf("testboo:%d\n",boo);

  if(boo<5000){
    boo = 0;
  }else{
    boo = 1;
  }

  return boo;

}
#endif
