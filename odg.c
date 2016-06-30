#include<stdio.h>
#include<stdlib.h>

int* bubbleSort(int*,int);//プロトタイプ宣言

int main(int argc, char *argv[ ]){
	
	char filename[20];//解析するファイル名
	char ld[20];
	int c,c2;//c:読み込む文字、c:2前回読み込んだ文字
	int cc = 0;//cc:カンマカウンター
	int len = 0;//行数
	int i = 0;//
	int ccMax = 0;//PURLに対する最大外向きリンク数	
	FILE *f;//解析するファイルのポインタ
	FILE *fp;//解析データ書き出し用ファイルポインタ
	

	f=fopen(argv[1],"r");
	fp=fopen(".linkdata.txt","w+");  

	if(f==NULL){
		printf("%s can't open this file\n",filename);
		return 0;
	}//ポインタエラー判定

	if(fp==NULL){
		printf("%s can't open this file\n",ld);
		return 0;
	}//ポインタエラー判定

	while((c=fgetc(f))!=EOF){
		if(c==',')cc++;
		if(c==']'&&c2=='['){
			fprintf(fp,"0\n");
			cc = 0;
			len++;
		}else if(c=='n'&&c2=='\n'){
			fprintf(fp,"0\n");
			cc = 0;
			len++;
		}else if(c==']'){
			fprintf(fp,"%d\n",cc);
			if(cc>=ccMax){
				ccMax=cc;
			}
			cc = 0;
			len++;
		}

		c2=c;

	}//URLカウント、書き出し

	fclose(f);
	fclose(fp);
	
	f=fopen(argv[1],"r");
	fp=fopen(".linkdata.txt","r");  
	
	
	int n[ccMax];
	
	while(i<=ccMax){		
	
		n[i]=0;
		i++;
		
	}
	
	i=0;
	
	while((c=fgetc(f))!=EOF){
		if(c==',')cc++;
		if(c==']'&&c2=='['){
			cc = 0;
			n[0]++;
		}else if(c=='n'&&c2=='\n'){
			cc = 0;
			n[0]++;
		}else if(c==']'){
			n[cc]++;
			cc = 0;
		}

		c2=c;

	}//URLカウント、書き出し
	
	
	while(i<=ccMax){
				
		if(n[i]==0){
		}else{
			printf("%d,%d\n",i,n[i]);
		}
		i++;
	}
	/*
	while((fgets(buf,len,fp))!=NULL){
		n[cc]=atoi(buf);
		cc++;
		
	}

	bubbleSort(n,len);
	
	cc=1;

	while(i<=len){		
		if(n[i]==n[i-1]){
			cc++;
		}else{
			printf("%d,%d\n",n[i-1],cc);
			cc=1;
		}
		i++;
		
	}
	*/
	
	fclose(f);
	fclose(fp);
	return 0;

}

int* bubbleSort(int* N, int len){	
	int i,j,temp;
	for(i=0; i<len; i++){
		for(j=len-1; j>i; j--){
			if(N[j] < N[j-1]){
				temp = N[j];
				N[j] = N[j-1];
				N[j-1] = temp;
				}
			}
		}

	return N;
}
