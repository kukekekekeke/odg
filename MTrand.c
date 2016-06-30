//MTrand.c

#ifndef INCLUDE_MTRAND
#define INCLUDE_MTRAND

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "MTrand.h"
#include "MT.h"

int idling(void){
  
  int i;
  
  init_genrand((unsigned)time(NULL));
  
  for(i=0;i<1000;i++){
    genrand_int32();
  }

  return 0;

}


int MTrand(void){
  int num;
  int MIN,MAX;
  MIN = 0;
  MAX = 10000;
 
  num = genrand_int32()%(MAX-MIN+1)+MIN;
  

  return num;

}

int linker(int ws){
  int num;
  int MIN, MAX;
  MIN = 1;
  MAX = ws;
  
  num = genrand_int32()%(MAX-MIN+1)+MIN;

  return num;

}

#endif
