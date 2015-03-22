#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int *x;
int main()
{
    int n;
    printf("请输入皇后的数目：\n");
    scanf("%d",&n);
    x = (int*)malloc(sizeof(int)*(n+1));
    Queue(n);
}
void Queue(int n){
   int i,k;
   for( i = 1; i<n;i++)
    x[i] = 0;
   k = 1;
   while(k >= 1){
    x[k] = x[k] +1;
    while(x[k]<=n && Place(k) == 0)
     x[k] = x[k]+1;
     if(x[k] <= n && k ==n){
        for( i =1;i <=n ;i++){
            printf("第 %d 行的第 %d 列放置皇后\n",i,x[i]);
        }
       return;
     }else if( x[k] <=n && k<n)
        k++;
     else{
       x[k] = 0;
       k--;
     }
   }
}
int  Place(int k){
    int i;
   for( i = 1;i<k;i++)
    if(x[k] == x[i] || abs(k-i) == abs(x[k] - x[i]))
     return 0;
   return 1;
}
