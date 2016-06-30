#ifndef INCLUDE_WEBSTRUCT
#define INCLUDE_WEBDTRUCT

#include <stdlib.h>
#include "webstruct.h"



Web *createweb(char *c,char *lse, int m, int nop, int b){
  Web *newweb;

  newweb = malloc(sizeof(Web));
  newweb -> domain = c;
  newweb -> lang = lse;
  newweb -> method = m;
  newweb -> build = b;
  newweb -> name = nop;
  newweb -> next = NULL;


  return newweb;

}

#endif
