#include "stdio.h"
#include "stdlib.h"
typedef struct htNode{
       int weight;
       char E;
       int Lchild,Rchild,parent;
}HtNode,*HT;
int main(){
     HT h;

}
int Input(HT &h){
     int n,i;
     printf("input the number of data:\nElement,\tWeight");
     scanf("%d",&n);
     h = (HT)calloc((2*n-1),sizeof(HtNode));
     for(i=0;i<n;i++)
        scanf("%c,%d",h[i]->E,h[i]->weight);
     return n;
}
bool HuffmanCoding(HT &H){
      int Minb,Mins,i,j=0;
      int n = Input(H);
      for(i=n;i<2*n;i++){
            Mins = H[i-1];
            j = 0;
         while(j<i){
            int temp;
             if(Mins>=H[j]&&H[j]->parent==0)
               Mins = H[j];
             j++;
          }
            j = 0;
      }
}
