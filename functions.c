#ifndef INCLUDE_FUNCTIONS
#define INCLUDE_FUNCYIONS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

void replace(char* dom, int a, int b){
  //char temp[2];
  //strcpy(temp,"aaa");
  //printf("temp:%s\n",temp);
  dom[a] = dom[b];
  printf("dom[a]=%c\ndom[b]=%c\n",dom[a],dom[b]);
  //dom[b] = *temp;
}
#endif
