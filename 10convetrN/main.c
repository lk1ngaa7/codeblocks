/* Note:Your choice is C IDE */
#include "stdio.h"
#include "math.h"
 void main()
 {
 int a,i,sushu(n);
 /* isSucced ��һ�� ��־λ ������ʾ �Ƿ��������Ա��ֽ�*/
 int isSucced = 0;
 printf("������һ��ż����");
 scanf("%d",&a);
 for(i=0;i<=(a/2);i++)
  {
  	if(sushu(i)&&sushu(a-i))
 	 {
 	   printf("�ɷֽ�Ϊ���������ֱ��ǣ�%d %d\n",i,a-i);
 	   /*
 	      isSucced ��ֵ 1
 	   */
 	   isSucced  = 1;
 	 }
  }
  if(!isSucced)
    printf("������޷��ֽ⣡������");
 }

int sushu(int n)
{
	int i;double k;
	k=sqrt(n);
   for(i=2;i<k;i++)
  {
    /*
       �޸ķ�������������ҵ�һ����1�����������
       ��֤�������� ���� ���Է���0
    */
     if(n%i==0)
 	  return 0;
  }
    /*
       ѭ�������� ������û�з��� ��˵�������������
       ���Է��� 1
    */
     return 1;
 }

