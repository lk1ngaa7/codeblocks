#include <stdio.h>
#include <stdlib.h>
#define MAX 100000
/*
  ���� A ��������������Ԫ�ش�С��� 1���ָ������������� A ��Ŀ������ t��
�ҳ� t ������ A �е�λ��
*/
int findInArray(int array[],int target,int length){
   int index = array[0] - target;
   index =index >0?index:-index;
   if(index > length)
     return -1;
   if(array[index] == target)
    return index;
   else
    return -1;
}
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

int main()
{
    int *a = (int *)malloc(sizeof(int)*MAX);
    int t,i;
    for(i = 0;i<MAX;i++){
            a[i] = i;
    }
    srand(12);
    t = rand();

    printf("t : %d\nindex:%d\n",t,binary_search(a,MAX,t));
    printf("t : %d\nindex:%d\n",t,findInArray(a,t,MAX));
    free(a);
    return 0;
}
