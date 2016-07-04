#ifndef INCLUDE_CCTLD
#define INCLUDE_CCTLD

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double paretoP(int ws, int i);

char *ccTLD(int rani,char* domp,int ws){
  //char cd[5][9]={"us","jp","cn","kr","in"};/*ccTLDの種類*/
  char cd[5][9]={"ca","cb","cc","cd","ce"};/*ccTLDの種類*/
  char *domain=malloc(sizeof(char)*2);/*返り値*/
  double p[5]={0.4000,0.3000,0.2000,0.0700,0.0300};/*確率分布*/
  double s[5];/*累積確率分布*/
  int np = 5;/*分布表サイズ*/
  int ip = 0;/*分布表カウンタ*/
  double rand = rani;/*少数乱数:0<=rand<10000*/
  double rn = (rand / 10000)*ws;/*実際に使用する乱数*/
  
  for(int i=0;i<np;i++){
    p[i]=paretoP(ws,i);
  }
  /*累積確率表の作成*/
  s[0] = p[0];
  for(ip=0;ip<np;ip++){
    s[ip] = s[ip-1]+p[ip];
  }
  
  /*ccTLDを確率的に選択*/
  for(ip=0;ip<np;ip++){
    if(s[ip]>rn) break;
  }
  sprintf(domain,"%s",cd[ip]);
//  strcpy(domain,cd[ip]);
//  printf("%s\n",domain);
  domp = domain;
//  printf("%s\n",domp);

  return domp;

}

double paretoP(int ws,int i){
  
  double P;
  double  b=1.0000;
  i+=1;
  P = ws/pow(i,b);
  return P;
  
  }
#endif
