#include "stdio.h"
#include "stdlib.h"
#define len 30
/*
  引用就是某一变量（目标）的一个别名
  ，对引用的操作与对变量直接操作完全一样。
  声明引用时，必须同时对其进行初始化。
  ***********
  传统的c中，函数在调用时参数是通过值来传递的，
  这就是说函数的参数不具备返回值的能力。
  1、传递可变参数
  2、给函数传递大型对象
*/
typedef union{
     float num;
     char Op;
}NdNode;
typedef struct{
    char *op;
    int top;
    int pear;
    int length;
}Oper;
typedef struct{
    float *o;
    int top;
    int pear;
    int length;
}OpNd;
int Pop(OpNd &s,float &n);
int Pop(Oper &s,char &o);
int init(OpNd &s);
int init(Oper &s);
int Push(OpNd &s,float n);
int Push(Oper &s,char o);
int print(OpNd &s);
int print(Oper &s);
char GetTop(Oper &s);
char precede(char pri,char pear);
float operating(float a,char op,float b);
int main(){
    OpNd N;
    Oper O;
    NdNode s;
    char c,temp,operater;
    float a,b;
    s.Op = '*';
    init(N);
    init(O);
    Push(O,'#');
    c = getchar();
    while(c!='#'||GetTop(O)!='#'){
        if(!(c=='+'||c=='-'||c=='*'||c=='/'||c==')'||c=='(')){
             Push(N,1.0*(c-'0'));
             c = getchar();
        }else{
           switch(precede(GetTop(O),c)){
            case '<':
            Push(O,c);
            c=getchar();
            break;
            case '=':
            Pop(O,temp);
            c=getchar();
            break;
            case '>':
               Pop(O,operater);
               Pop(N,a),Pop(N,b);
              Push(N,operating(a,operater,b));
               break;
           }
        }

    }
    printf("%f",Pop(N,a),a);
    return 0;
}
char GetTop(Oper &s){
     return s.op[s.top-1];
}
float operating(float a,char op,float b){
        float result;
        switch(op){
            case '+': result = a+b;break;
            case '-': result = a-b;break;
            case '*': result = a*b;break;
            case '/': result = a/b;break;
            default:printf("Error");exit(1);
        }
        return result;
}
char precede(char pri,char pear){
    char E[][7]={{'>','>','<','<','<','>','>'},{'>','>','<','<','<','>','>'}
               ,{'>','>','>','>','<','>','>'},{'>','>','>','>','<','>','>'}
               ,{'<','<','<','<','<','=','!'},{'>','>','>','>','!','>','>'},
               {'<','<','<','<','<','!','='}};
    char w[]={'+','-','*','/','(',')','#'};
    int i=-1,j=-1;
    while(i++,w[i]!=pri);
    while(j++,w[j]!=pear);
    if(E[i][j] == '!'){
        exit(0);
    }
    return E[i][j];
}
int init(OpNd &s){
    s.o = (float *)malloc(len * sizeof(float));
    if(!s.o)
        return 0;
    s.pear = s.top = 0;
    s.length = len;
    return 1;
}
int init(Oper &s){
    s.op = (char *)malloc(len* sizeof(char));
    if(!s.op)
        return 0;
    s.pear = s.top = 0;
    s.length = len;
    return 1;
}
int Pop(Oper &s,char &o){
      if(s.top == s.pear)
        return 0;
      o = s.op[s.top-1];
      s.top--;
      return 1;
}
int Pop(OpNd &s,float &n){
      if(s.top == s.pear)
        return 0;
      n = s.o[s.top-1];
      s.top--;
      return 1;
}
int Push(OpNd &s,float n){
   if(s.top == len - 1)
     return -2;
   s.o[s.top] = n;
   s.top++;
   return 1;
}
int Push(Oper &s,char o){
    if(s.top == len - 1)
     return -2;
   s.op[s.top] = o;
   s.top++;
   return 1;
}
int print(OpNd &s){
    int i;
    if(s.top == s.pear)
        return 0;
    for(i=0;i<s.top;i++){

            printf("%f",s.o[i]);

    }
   return 1;
}
int print(Oper &s){
     int i;
    if(s.top == s.pear)
        return 0;
    for(i=0;i<s.top;i++){
        printf("%c",s.op[i]);
    }
    return 1;
}

