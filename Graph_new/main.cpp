#include "stdio.h"
#include "stdlib.h"
/******
    ����ڽӾ�����ڽ�����Ķ�ͼ�ı�ʾ����
    ʹ�ö�̬��������ռ䣨realloc() ��չ����
    ��ʽ���洢����֮��Ĺ�ϵ�������ȼ�����
    �ڽӾ���Թ̶��洢�ռ���˷ѣ�Ҳ������
    �ڽ�����Բ������洢�ռ�������ʡ�ʹ��realloc
    ���ܻ��Ч���������ͣ����������ͼ��ϡ��̶�
    ��̬�仯ÿ�����ӵ����鳤�ȣ��Ӷ����ٶ�realloc����
    ��ʹ�ô���

*******/
typedef struct successors{
              int len;         //    length of array
              int dataLen;  //   number of data
              int *S;           //   pointer to  a flexible space to store the relationships of different vertices
}Successors;
typedef struct graph{
      char *vertices;
      int verticesNum;     //  number of vertices
      int edges;      //    number of edges
      char type;      //    'D'  directed graph  or 'N'
      Successors *s;
}Graph;
int main(){
   Graph g;
   int n;
}
void initGraph(Graph &G,int n,char type){
       int i;
       if(!G = (Graph*)calloc(sizeof(Graph),1))
           exit(1);
           G->vertices = (char *)calloc(sizeof(char),n);nb
       G->type = type;
       G->verticesNum = n;
       G->s = (Successors*)calloc(sizeof(Successors),n);
       for(i=0;i<n;i++){
           //  apply a space of n/3 (maxinum is n-1) for each vertice
           //  the number 'n/3' could be changed
           G->s[i].S = (int *)calloc(sizeof(int),n/3);
           G->s[i].len = n/3;
       }
}
void input(Graph &G){
              int i;
              printf("Input the data (type == char)\n");
              for(i=0;i<G->verticesNum;i++){
                     scanf("%c",&G->vertices[i]);
              }
}
//   add  an edge from begin to end
void add_edges(Graph &G,int Begin,int End){
             if(Begin > G->verticesNum|| End > G->verticesNum)
                   exit(1);
                   if(G->s[Begin].dataLen >= G->s[Begin].len)

             if(G->type == 'N'){
                     if(G->)
             }
}
