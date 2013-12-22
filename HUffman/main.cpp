#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define MAX 32000
typedef struct htNode{
       int weight;
       char E;
       int Lchild,Rchild,parent;
}HtNode,*HT;
bool HuffmanCoding(HT &H,int &n);
int Input(HT &h);
void Translation(HT &H,char*&S,int n,char*&result);
int main(){
     HT h;
     int n;
     char *s = (char*)malloc(sizeof(char)*100);
     char *re = (char*)malloc(sizeof(char)*20);
     HuffmanCoding(h,n);
     printf("Input the encoded string:\n");
     fflush(stdin);
     s=gets(s);
     Translation(h,s,n,re);
     puts(re);
}
void Translation(HT &H,char*&S,int n,char*&result){
     int i = 2*n-2,j=0,m=0;
     while(S[j]){

         while(!H[i].E){
             if(S[j] == '1')
                i = H[i].Rchild;
             else
                i= H[i].Lchild;
            j++;
        }
         result[m++] = H[i].E;
        i = 2*n-2;
}
     result[strlen(result)] = '\0';
}
int** Traverse(int n,HT &h){
          int i,j,q,l;
          int num=0;
          int **t= (int**)malloc(sizeof(int*)*n);
          for(i=0;i<n;i++)
            t[i] = (int*)calloc(sizeof(int),(n+1));
          for(i=0;i<n;i++){
           // printf("%c\t------:",h[i].E);
            j=i;
            q=1;
            num=0;
            while(h[j].parent !=0){
                  if(h[h[j].parent].Lchild == j)
                    t[i][q++] = 1;
                  else
                    t[i][q++] = 2;
                  j = h[j].parent;
                  num++;
             }
             t[i][0] = num;
         }
      return t;
}
int Input(HT &h){
     int n,i;
     printf("input the number of data:\n");
     scanf("%d",&n);
     printf("Element\tWeight\n");
     h = (HtNode*)calloc(sizeof(HtNode),(2*n-1));
     for(i=0;i<n;i++){
            getchar();
        scanf("%c,%d",&h[i].E,&h[i].weight);
        h[i].Lchild = -1;
        //printf("%d\n",i);
     }
     return n;
}
bool HuffmanCoding(HT &H,int &n){
      int Minb,Mins,i,j=0;
      int sum,s=0,b=0;
      int **T;
      n = Input(H);
      for(i=n;i<2*n-1;i++){
            Mins = MAX,s = i-1;
            Minb = MAX,b = i-1;
            j = 0;
         while(j<i){
             if(Mins>=H[j].weight&&H[j].parent==0)
               Mins = H[j].weight,s = j;
             j++;
          }
          H[i].Lchild = s;
          H[s].parent = i;
            j = 0;
        while(j<i){
             if(Minb>=H[j].weight&&H[j].parent==0)
               Minb = H[j].weight,b = j;
             j++;
          }
          sum = Mins + Minb;
          H[i].weight = sum;
          H[i].Rchild = b;
          H[b].parent = i;
      }
        T = Traverse(n,H);
        for(i=0;i<n;i++){
            int temp,h;
            j = T[i][0];
             for(temp = 1;temp<= j/2;temp++){
                h=T[i][temp];
                T[i][temp] = T[i][j-temp+1];
                T[i][j-temp+1] = h;
             }
          }
          printf("Ç°×º±àÂëÊÇ£º\n");
          for(i=0;i<n;i++){
                j=1;
                printf("%c:\t",H[i].E);
        while(T[i][j]==1||T[i][j]==2)
            printf("%d\t",T[i][j]-1),j++;
            printf("\n");
          }
      return true;
}
