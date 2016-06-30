#ifndef INCLUDE_WEBSTRUCT
#define INCLUDE_WEBSTRUCT


/*構造体型struct Webの宣言*/
typedef struct webtag{
  char *domain;/*ウェブページの国*/
  char *lang;/*主要言語，言語コード*/
  int method;/*作る方法:機械的:0 人為的:1*/
  int name;/*ウェブページの名前*/
  int build;//--------ウェブ生成方法------------//0:人1:ビルダー2:ショップ


  //G追加分
  struct webtag *next;
  struct webtag** link;


  //int kind;/*ウェブページの種類*/
  //int population;/*ウェブページのある国の人口*/
}Web;

Web *createweb(char *c,char *lse, int m, int nop, int b);
char *ccTLD(int rani,char* domp);

#endif
