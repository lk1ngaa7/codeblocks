#include <stdio.h>
#include <stdlib.h>
void quickSort(int *a,int length,int start,int last){
     int index;
     if(start == last)
         return ;
     index = Partion(a,length,start,last);
     if(index > start)
        quickSort(a,length,start ,index-1);
     if(index < last)
        quickSort(a,length,index+1,last);
}
void Swap(int *b,int *c){
      *c= *c + *b;
      *b= *c - *b;
      *c= *c - *b;
}
int randomData(int start,int last){
    int range =last - start;
    return start + (312%range);
}
int Partion(int *a,int length,int start,int last){
        int index;
        int small;
        index = randomData(start,last);
        Swap(&a[index],&a[last]);

        small  = start - 1;

        for(index = start;index < last; index++){

           if(a[index] < a[last]){
                    small++;
                if(small != index){
                   Swap(&a[small],&a[index]);
                }

           }

        }
      small++;
      Swap(&a[small],&a[last]);
      return small;

}
int main()
{
    int s[13] = {4,23,1,86,75,2,6,45,13,2,25,8,6};
    int i;
    quickSort(s,13,0,12);
    for(i = 0;i< 13;i++)
        printf("%d\n",s[i]);
    return 0;
}
