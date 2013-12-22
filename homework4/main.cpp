/**
        p43
        ����m*n�ľ����д���һ��Ԫ��A[i]��
        �����㣺A[i,j]�ǵ�i��Ԫ���е���Сֵ��
        ���ǵ�j��Ԫ���е����ֵ����ƾ���A�а��㡣
        ��дһ���㷨���ҳ�����A��һ�����㣬�������ڰ��㣬
        �򷵻�ĳ����Ϣ
*/
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#define matrixRowNum 8    // ��
#define matrixLineNum 8    // ��
int findMaAn(int **&p);
int initMatrix(int **&p);
int setDataToMatrix(int **&p);
void printMatrix(int **&p);
int main(){
   int **M;
   int i=0;
   initMatrix(M);
   setDataToMatrix(M);
   printMatrix(M);
   findMaAn(M);
   return 1;
}
/**
     Ѱ������
     �㷨��
        ����һ������� �ҵ���Сֵ֮�� ������һ����
        �����ҵ����ֵ ������ֵ������Сֵ  ���ҵ���ֵ
        Ȼ�����
*/
int findMaAn(int **&p){
  int i=0;
  int j=0,k = 0,l = 0;
  int Min = 0;
  int Max = 0;
  while(j < matrixRowNum){
    int temp=0;
    Min = *(*(p+j));
    while(i < matrixLineNum){
        if(Min > *(*(p+j)+i)){
            Min = *(*(p+j)+i);
            k=i;
        }
        i++;
      }
      Max = *(*(p+temp)+k);
    while(temp < matrixRowNum){
        if(Max < *(*(p+temp)+k)){
            Max = *(*(p+temp)+k);
            l= temp;
        }
        temp++;
    }
    if(Max == Min){
        printf("������%d location is R---%d,L is L----%d",Max,l+1,k+1);
        return 1;
    }
    i=0;
    j++;
  }

  return 0;
}
/**
     ��ʼ������
*/
int initMatrix(int **&p){
      int i=0;
      p = (int**)malloc(sizeof(int*)*matrixRowNum);
      while(i< matrixRowNum){
        *(p+i) = (int *)malloc(sizeof(int)*matrixLineNum);
         if(*(p+i)==NULL)
            return 0;
            i++;
      }
      return 1;
}
/**
    ���������������ֵ
**/
int setDataToMatrix(int **&p){
       int i=0;
       int j=0;
       while(j < matrixRowNum){
         while(i < matrixLineNum){
            srand((j+1)*8+i+1);//  �������ӵõ������
            *(*(p+j)+i) = rand();
            i++;
           }
           i=0;
           j++;
       }
       return 1;
}
/**
      ��ӡ����
*/
void printMatrix(int **&p){
    int j,i;
    i = j = 0;
    while(i< matrixRowNum){
        while(j<matrixLineNum){
            printf("%d\t",*(*(p+i)+j));
            j++;
        }
        j=0;
        i++;
        printf("\n");

    }
}
