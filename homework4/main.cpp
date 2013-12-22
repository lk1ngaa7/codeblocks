/**
        p43
        若在m*n的矩阵中存在一个元素A[i]，
        并满足：A[i,j]是第i行元素中的最小值，
        且是第j列元素中的最大值，则称矩阵A有鞍点。
        试写一个算法，找出矩阵A的一个鞍点，若不存在鞍点，
        则返回某种信息
*/
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#define matrixRowNum 8    // 行
#define matrixLineNum 8    // 列
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
     寻找马鞍点
     算法：
        现在一行里遍历 找到最小值之后 再在这一列里
        遍历找到最大值 如果最大值等于最小值  则找到马鞍值
        然后输出
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
        printf("马鞍数是%d location is R---%d,L is L----%d",Max,l+1,k+1);
        return 1;
    }
    i=0;
    j++;
  }

  return 0;
}
/**
     初始化矩阵
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
    利用随机数给矩阵赋值
**/
int setDataToMatrix(int **&p){
       int i=0;
       int j=0;
       while(j < matrixRowNum){
         while(i < matrixLineNum){
            srand((j+1)*8+i+1);//  设置种子得到随机数
            *(*(p+j)+i) = rand();
            i++;
           }
           i=0;
           j++;
       }
       return 1;
}
/**
      打印矩阵
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
