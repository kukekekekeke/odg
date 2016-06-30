//webmake.c

#ifndef INCLUDE_WEBMAKE
#define INCLUDE_WEBMAKE

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "webmake.h"
#include "webstruct.h"
#include "MTrand.h"
#include "lse.h"
#include "linkmethod.h"

/*main関数の引数[1:生成するURLの数]*/
Web* make(int ws){
  int nop = 0;//ページ番号
  int i = 0;//カウンタ
  int num,met,builder;//乱数
  char *con,*lan;
  char *ctemp,*ltemp;
  Web *temp,*pos;
  Web *newweb;
  Web *web_header;

/*
  Web *webheader;

  webheader = createweb("jp","ja",0,nop);
  nop ++;
  printf("ccTLD:%s\nISO 639-1:%s\nmethod%d\nname%d\n",webheader -> domain,webheader -> lang,webheader -> method, webheader -> name);

*/


  for(i=0;i<ws;i++){ 
    //printf("%d\n",i);
    num = MTrand();
    //printf("testnum:%d\n",num);
    con = ccTLD(num,ctemp);
    num = MTrand();
    lan = lse(num,ltemp);
    builder = MTrand() % 3;
    printf("buildertest%d",builder); 
    met = howlink();
    //printf("testhow:%d\n",met);
    //printf("lsetest:%s\n",lan);

    newweb = createweb(con,lan,met,nop,builder);
    newweb->link = (Web**)calloc(ws,sizeof(Web*));
    if(i==0){
      web_header = newweb;
      temp=web_header;
      nop++;
      continue;
      }else{
      temp->next=newweb;
      temp=newweb;
      nop++;
      }
    }


    /* for(i=0,temp=web_header;temp != NULL;i++,temp=temp->next){ */
    /*   printf("ccTLD:%s\nISO 639-1:%s\nmethod%d\nname%d\n",temp -> domain,temp -> lang,temp -> method, temp -> name); */
		/* } */

  return web_header;
}

#endif
