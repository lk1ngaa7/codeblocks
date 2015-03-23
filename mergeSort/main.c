#include <stdio.h>
#include <stdlib.h>
void mergeSort(int *a,int length){
     int i,j,middle;
     int *b;
     int *c;
     if(length > 1){
      middle = length/2;
      b =(int *)malloc(sizeof(int)*middle);
      for(i = 0;i < middle;i++){
         b[i] = a[i];
      }
      c = (int *)malloc(sizeof(int)*(length - middle));
      j = 0;
      for(i = middle;i < length;i++){
        c[j++] = a[i];
      }
         mergeSort(b,middle);
         mergeSort(c,length - middle);
         Merge(a,b,c,middle,length - middle);
     }
}
void Merge(int *A,int *B,int *C,int lb,int lc){
    int a = 0,b = 0,c = 0;
    while(b < lb && c < lc){
       if(B[b] >= C[c] ){
           A[a] = B[b];
           b++;
       }else{
           A[a] = C[c];
           c++;
       }
       a++;


    }
    if(b < lb){
       while(b < lb)
         A[a++] = B[b++];
    }
    if(c < lc){
     while(c < lc)
       A[a++] = C[c++];
    }

}
int main()
{
    int i;
    int a[10] = {13,26,84,6,11,6,3,48,4,3};

    mergeSort(a,10);

    for(i = 0;i< 10;i++)
      printf("%d\n",a[i]);

    return 0;
}
