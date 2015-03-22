/* Note:Your choice is C IDE */
#include "stdio.h"
void Bubble_sort(int n);
int *a;
void main()
{
        int i,n;
            printf("请输入n的值：");
            scanf("%d",&n);
            a = (int *)malloc(sizeof(int)*n);
            for(i=0;i<n;i++)
            {
                scanf("%d",&a[i]);
            }
            Bubble_sort(n);
            printf("奇数:\n");
           for(i = 0;i<n;i++)
            if(a[i]%2)
              printf("%d\n",a[i]);
            printf("偶数:\n");
           for(i = 0;i<n;i++)
            if(a[i]%2==0)
              printf("%d\n",a[i]);
}
void Bubble_sort(int n){
    int i,j;
    for(i=0;i < n;i++){
        for(j= 1;j< n-i;j++){
           if(a[j-1]>a[j]){
              int temp;
              temp = a[j-1];
              a[j-1] = a[j];
              a[j] = temp;
           }

        }

    }
}



