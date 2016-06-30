#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "webstruct.h"
#include "webmake.h"
#include "MTrand.h"
#include "judge.h"
//gittest
int main(int argc, char *argv[]){
  int i;//カウンタ
  int num;//乱数
  int ws = atoi(argv[1]);//ウェブ空間
  double pro;//probability：確率
  char *ccTLD;
  Web *web_header,*temp,*pos;
  
  idling();//MTrand空回し
  //printf("debug\n");
  num = MTrand();//乱数生成 
  pro = num;
  pro /= 10000;//確率
  //printf("randtest:%lf\n",pro);//乱数テスト
  
  
  web_header = make(ws);

  for(temp=web_header;temp != NULL;temp=temp->next){
    for(i=0,pos=web_header;pos != NULL;pos=pos->next){
      if(temp==pos) continue;
        //printf("name%d,",pos->name);
        //link(temp,pos,i);
        judge(temp,pos,i);//リンク判定
	if(temp->link[i] != 0) i++;
        }
      //printf("\n");
  }
  
  //printf("-------------\n");
  //printf("linkertest%d\n",linker(ws));
  
  for(temp=web_header;temp != NULL;temp=temp->next){
    printf("[");
    for(i=0,pos=web_header;pos != NULL;pos=pos->next){
      if(temp==pos) continue;
	if(temp->link[i] != 0){
	  printf("name%d,",temp->link[i]->name);
	  i++;
	}
    }

    printf("]\n");
  }
  
  return 0;
  
}
