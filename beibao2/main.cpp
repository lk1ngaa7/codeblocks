#include "stdio.h"
#include "stdlib.h"
#define INT_MAX 32676
/**
 Dijkstra 算法是用来计算图中一个
          顶点到 其余的所有顶点的
          最短距离的算法
*/
/***
     -1 表示两点之间距离是无限大
     path[v] 表示的这个数组代表了Vx到 v 的最短路径
     路径 = path[v][0],v,path[v][1],path[v][2]
     直到一个path[v][x] == -1

     Length[v] 代表了Vx到 v 的最短长度：权之和

**/
typedef struct graph{
    int **p;
    int vertNum;
    int arcNum;
}*Graph,g;
typedef struct l{
   int* le;
   bool* isIn;
}*Le;
int VETNUM=6;
void init(Le &L,int **&P,Graph &G);
void Dijikstra(Le &L,int **&P,Graph &G,int &V);
void myprint(Le &L,int**&p,int Begin);
void pathGen(int **&Path, int pre,int later);
int main(){
   Le Length; // 某个顶点到其余所有顶点的最短距离
   int **Path;  // 路径
   int Vx;     //   某个顶点
   Graph G;    // 图
   init(Length,Path,G);
   printf("Enter the begin vertex:\n");
   scanf("%d",&Vx);
   Dijikstra(Length,Path,G,Vx);
   myprint(Length,Path,Vx);
}
void myprint(Le &L,int**&p,int Begin){
    int i,j;
    for(i=0;i<6;i++){
        if(L->le[i]==-1)
        {
            printf("最短路径长度是 无限长 最短路径: 无\n");
            continue;
        }
        printf("最短路径长度是:%d 最短路径是:\t%d\t",L->le[i],Begin);
        if(p[i][0]==-1){
            printf("%d\n",i);
            continue;
        }
        for(j=0;j<6;j++){
                if(p[i][j]==-1)
                break;
            printf("%d\t",p[i][j]);
            }
        printf("\n");

    }
}
void init(Le &L,int **&P,Graph &G){
    //测试数据1
     int data[6][6] ={{-1,-1,10,-1,30,100},{-1,-1,5,-1,-1,-1},
                 {-1,-1,-1,50,-1,-1},{-1,-1,-1,-1,-1,10},
                 {-1,-1,-1,20,-1,60},{-1,-1,-1,-1,-1,-1}};
     //测试数据2
     int data1[6][6] = {{-1,1,20,80,-1,400},{2,-1,-1,-1,-1,700},
                        {40,6,-1,4,-1,100},{-1,-1,-1,-1,4,-1},
                        {-1,-1,-1,-1,-1,3},{-1,-1,-1,-1,-1,-1}};
     int vextnum = 6;
     int i,j;
     G = (Graph)calloc(sizeof(g),1);
     G->p = (int**)malloc(sizeof(int*)*6);
     P = (int**)malloc(sizeof(int*)*6);
     L = (Le)calloc(sizeof(struct l),1);
     L->le = (int*)calloc(sizeof(int),6);
     L->isIn = (bool*)calloc(sizeof(bool),6);
     for(i=0;i<6;i++){
        G->p[i] = (int*)malloc(sizeof(int)*6);
        P[i] = (int *)calloc(sizeof(int),6);
     }
     G->vertNum = 6;
     for(i=0;i<vextnum;i++) g-="" j="0;j<vextnum;j++)">p[i][j] = data[i][j],P[i][j]= -1;
}
void Dijikstra(Le &L,int **&P,Graph &G,int &V){
   int Vk;
   int i,j;
   int Min;
   int check=0;
   /**
      首先将L初始化  在这里面必有一条
      V 到其他顶点的最小值
   **/
   for(i=0;i<g->vertNum;i++){
       L->le[i] = G->p[V][i];
       //printf("%d\t",L->le[i]);
       if(L->le[i] > -1)
        check =1;
  }
  if(check==0)
    printf("Error!!"),exit(0);
   for(i=1;i<g->vertNum;i++){
        Min = INT_MAX;
      for(j=0;j<g->vertNum;j++)
       if(!L->isIn[j])
       {
           if(L->le[j]!=-1&&L->le[j]<min) min="L-" vk="j,">le[j];
           }
       }
      L->isIn[Vk] = true;          //  将距离Vx最近的点加入到另外一个集合中
                                   //  也就是说下一次不要比较

    for(j=0;j<g->vertNum;j++){

           if((G->p[Vk][j]!=-1)&&!L->isIn[j]
              &&(Min+G->p[Vk][j]<l->le[j]))
           {
                 L->le[j] = Min+G->p[Vk][j];
                  pathGen(P,Vk,j);
           }
           if(L->le[j]==-1&&(G->p[Vk][j]!=-1))
           {
                L->le[j] = Min+G->p[Vk][j];
                 pathGen(P,Vk,j);
           }

           }


     }


 }
 // 用来生成路径的函数
 // 根据不同的情况，在path二维数组中插入数据
void pathGen(int **&Path,int pre,int later){
  int i;
  if(Path[pre][0]==-1){
    Path[later][0] = pre;
    Path[later][1] = later;
  }else{
      for(i=0;Path[pre][i]!=-1;i++)
          Path[later][i] = Path[pre][i];
    Path[later][i] = later;
  }

}

