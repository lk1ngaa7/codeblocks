#include "stdio.h"
#include "stdlib.h"
/******
    结合邻接矩阵和邻接链表的对图的表示方法
    使用动态申请数组空间（realloc() 扩展）的
    方式来存储顶点之间的关系，这样既减少了
    邻接矩阵对固定存储空间的浪费，也增加了
    邻接链表对不连续存储空间的命中率。使用realloc
    可能会对效率有所降低，但可以针对图的稀疏程度
    动态变化每次增加的数组长度，从而减少对realloc函数
    的使用次数

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
