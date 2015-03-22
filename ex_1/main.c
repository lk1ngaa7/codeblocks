#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 90000
void dataGen(){
   FILE* fo;
   int i;
   fo = fopen("d:/data.txt","r+");
   if(!fo){
       printf("file open Error!");
       exit(1);
   }
   for(i = 0;i<N;i++){
        srand((i)%5+(i*i));
        fprintf(fo,"%d\n",rand());
  }

}
int* getData(int* data){
  FILE* fo;
  int i;
   fo = fopen("d:/data.txt","r+");
   if(!fo){
       printf("file open Error!");
       exit(1);
   }
   for(i=0;i<N;i++){
      fscanf(fo,"%d\n",&data[i]);
   }
  return data;
}
void quickSort(int s[], int l, int r)
{

    if (l < r)
    {
        int i = l, j = r, x = s[l];
        while (i < j)
        {
            while(i < j && s[j] >= x)
                j--;
            if(i < j)
                s[i++] = s[j];

            while(i < j && s[i] < x)
                i++;
            if(i < j)
                s[j--] = s[i];
        }
        s[i] = x;
        quickSort(s, l, i - 1);
        quickSort(s, i + 1, r);
    }
}
void Swap(int* a,int* b){
  int temp;
  temp = *a ;
  *a  = *b;
  *b = temp;
}
void InsertSort(int a[])
{
	int i, j;
	for (i = 1; i < N; i++)
		for (j = i - 1; j >= 0 && a[j] > a[j + 1]; j--)
			Swap(&a[j], &a[j + 1]);
}
int main()
{   int* data;
    int i;
    clock_t start, finish;
    dataGen();
    data = (int *)malloc(sizeof(int)*N);
      data = getData(data);
      start = clock();
    quickSort(data,0,N);
      finish = clock();
      printf("quickSort needs %lf\n",(double)(finish - start)/CLOCKS_PER_SEC);
    data = getData(data);
    start = clock();
    InsertSort(data);
    finish = clock();
    printf("insertSort needs %lf\n",(double)(finish - start)/CLOCKS_PER_SEC);

    return 0;
}
