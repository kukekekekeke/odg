#ifndef INCLUDE_LSE
#define INCLUDE_LSE

#include <stdio.h>
#include <stdlib.h>
#include "lse.h"
//#include "functions.h"


char *lse(int rani,char* lse){
  char cd[5][9]={"en","ja","zh","ko","hi"};/*ccTLDの種類*/
  char *temp=malloc(sizeof(char)*2);/*返り値*/
  double p[5]={0.4000,0.3000,0.2000,0.0700,0.0300};/*確率分布*/
  double s[5];/*累積確率分布*/
  int np = 5;/*分布表サイズ*/
  int ip = 0;/*分布表カウンタ*/
  double rand = rani;/*少数乱数:0<=rand<10000*/
  double rn = rand / 10000;/*実際に使用する乱数*/
  
  //replacetest
  //printf("test::::%s\n",cd[0]);
  //printf("replacetest\ncd[1]:%s----cd[2]%s\n",cd[1],cd[2]);
  //replace(*cd,1,2);
  //printf("result\ncd[1]%s----cd[2]%s\n",cd[1],cd[2]);

  /*累積確率表の作成*/
  s[0] = p[0];
  for(ip=0;ip<np;ip++){
    s[ip] = s[ip-1]+p[ip];
  }
  
  /*lseを確率的に選択*/
  for(ip=0;ip<np;ip++){
    if(s[ip]>rn) break;
  }
  sprintf(temp,"%s",cd[ip]);
  lse = temp;
  
  return lse;
}

#endif
