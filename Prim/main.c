#include <stdio.h>
#include <stdlib.h>

int main()
{

    int data[6][6] ={{-1,-1,10,-1,30,100},{-1,-1,5,-1,-1,-1},
                 {-1,-1,-1,50,-1,-1},{-1,-1,-1,-1,-1,10},
                 {-1,-1,-1,20,-1,60},{-1,-1,-1,-1,-1,-1}};
     int data1[6][6] ={{-1,10,-1,18,-1,-1},{10,-1,20,-1,-1,12},
                 {-1,20,-1,3,17,-1},{18,-1,3,-1,4,-1},
                 {-1,-1,17,4,-1,5},{-1,12,-1,-1,5,-1}};
    prim(data1);
    return 0;
}
void prim(int G_E[][6]){
   int V[6] = {0,0,0,0,0,0},E[5] = {0,0,0,0,0,0};
   int i,j = 0,p;
   //  Begin from the first V
   V[0] = 0;
 for(p = 0;p < 5;p++){
    int temp = 1000;
    int next = -1;

    for(j=0;j< p+1;j++){
       for(i=0;i<6;i++){
        if(G_E[V[j]][i] != -1){
          if(G_E[V[j]][i] < temp){
                temp = G_E[V[j]][i];
                next = i;
            }
       }
       }
    }
     int q;
     for(q=0;q<(p+1);q++){
       G_E[V[p]][next] = -1;
       G_E[next][V[p]] = -1;
   }
   E[p] = temp;
   V[p+1] = next;
 }
    printf("path\tweight\n");
    for(i = 0;i<5;i++){
     printf("%d -> %d\t%d\n",V[i],V[i+1],E[i]);

    }
}
