/* Note:Your choice is C IDE */
#include "stdio.h"
#include "math.h"
 void main()
 {
 int a,i,sushu(n);
 /* isSucced 是一个 标志位 用来表示 是否这个书可以被分解*/
 int isSucced = 0;
 printf("请输入一个偶数：");
 scanf("%d",&a);
 for(i=0;i<=(a/2);i++)
  {
  	if(sushu(i)&&sushu(a-i))
 	 {
 	   printf("可分解为两个素数分别是：%d %d\n",i,a-i);
 	   /*
 	      isSucced 赋值 1
 	   */
 	   isSucced  = 1;
 	 }
  }
  if(!isSucced)
    printf("这个数无法分解！！！！");
 }

int sushu(int n)
{
	int i;double k;
	k=sqrt(n);
   for(i=2;i<k;i++)
  {
    /*
       修改返回条件，如果找到一个非1和他本身的数
       就证明他不是 素数 所以返回0
    */
     if(n%i==0)
 	  return 0;
  }
    /*
       循环结束后 函数还没有返回 就说明这个数是素数
       所以返回 1
    */
     return 1;
 }

