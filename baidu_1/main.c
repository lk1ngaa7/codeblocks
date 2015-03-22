#include <stdio.h>
#include <stdlib.h>
#define MAX 100000
/*
  数组 A 中任意两个相邻元素大小相差 1，现给定这样的数组 A 和目标整数 t，
找出 t 在数组 A 中的位置
*/

int binary_search(int array[],int n,int value)
{
    int left=0;
    int right=n-1;
    while (left<=right)
    {

        int middle = left + ((right-left)>>1);
        printf("i:%d\n",middle);
        if (array[middle]>value)
        {
            right =middle-1;
        }
        else if(array[middle]<value)
        {
            left=middle+1;
        }
        else
            return middle;
    }
    return -1;
}

int binarySearch(int *a ,int t,int length){
  int middle;
  middle = (length-1) >> 1;

  while(middle != 0 && middle != length){
      printf("i:%d\n",middle);
      if(a[middle] < t)
        middle += middle >> 1;
      else if(a[middle] > t)
        middle = middle >> 1;
      else
        return middle;
   }
  return -1;
}
int main()
{
   /* int *a = (int *)malloc(sizeof(int)*MAX);
    int t,i;
    for(i = 0;i<MAX;i++){
            a[i] = i;
    }
    srand(12);
    t = rand();

    printf("t : %d\nindex:%d\n",t,binary_search(a,MAX,t));
    //printf("t : %d\nindex:%d",t,binarySearch(a,t,MAX));
    free(a);
    */
    int i= -1;
    printf("%d",i>>10);
    return 0;
}
