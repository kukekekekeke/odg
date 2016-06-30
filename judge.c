//judge.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "webstruct.h"
#include "MTrand.h"
#include "judge.h"

double assignP();
double builderP(int builder);
int judgelinker(int builder);


#define talphaMIN 0.70
#define talphaMAX 0.95
#define falphaMIN 0.00
#define falphaMAX 0.40
#define tbetaMIN 0.80
#define tbetaMAX 0.95
#define fbetaMIN 0.00
#define fbetaMAX 0.02


void judge(Web *purl,Web *curl, int c){

  double alpha,beta,gamma,delta;
  int tempran = MTrand();
  double ran,bias;
  int builder = (purl -> build);

  if (builderP(builder) >= MTrand()){
    return;
  }//ビルダーによるリンク判定

  //if(purl -> domain == curl -> domain){
 /* 
  if(strcmp(purl -> domain, curl -> domain) == 0){
    alpha = assignP(MTrand(),talphaMIN,talphaMAX);
  }else{
    alpha = assignP(MTrand(),falphaMIN,falphaMAX);
  }
  */
  //ドメインの判定文とりあえず消す20160630

  //if(purl -> lang == curl -> lang){
  if(strcmp(purl -> lang, curl -> lang) == 0){
    beta = assignP(MTrand(),tbetaMIN,tbetaMAX);
  }else{
    beta = assignP(MTrand(),fbetaMIN,fbetaMAX);
  }
  
  gamma = (purl -> method + curl -> method) / 2;
  
  delta = ((/*alpha +*/ beta + gamma) * bias) / 3 ;
  
  //printf("alpha:%lf\nbeta:%lf\ngamma:%lf\ndelta:%lf\n",alpha,beta,gamma,delta);
  //printf("testassign:%lf\n",assignP(MTrand(),0,1));

  if(delta > assignP(MTrand(),0.00000,1.000000)){
    purl->link[c] = curl;
    //printf("linked\n");
    }else{
    //printf("don't linked\n");
  }

/*
  if(delta > assignP(MTrand(),0,1)){
    return 1;
  }else{
    return 0;
  }
*/

}

double assignP(int ran, double MIN, double MAX){
  
  double dran = ran;
  double pro;

  pro = ((dran /10000) * (MAX-MIN)) + MIN;
  //printf("testpro:%lf\n",pro);
  return pro;

}

void link(Web *purl,Web *curl,int c){
  int result;

  result = MTrand()%2;//judge(purl,curl);
	if(result==1){
	  purl->link[c] = curl;
          //printf("linked");
	}else{
	  //printf("don't link");
	}
}

double builderP(int builder){
  double P;
  if (builder == 2) {
    P = assignP(MTrand(),0.500000,9.000000);
    }else if (builder == 1){
      P = assignP(MTrand(),0.100000,0.500000);
    }else{
      P = assignP(MTrand(),0.000000,0.1000000);
  }

  return P;

}//ビルダーに夜リンク率を作る

int judgelinker(int builder){
  double P = assignP(MTrand(),0.000000,1.000000);
  if(builder == 2){
    if(P <= 0.900000){
      return 1;
      }else if(builder == 1){
	if(P <= 0.500000){
	  return 1;
	  }
      }
  }
  return 0;
}//リンクが意識的リンクか無意識的リンクかを判定ページビルダーによって確率が異なる
