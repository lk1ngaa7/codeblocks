#include "stdio.h"
#include "stdlib.h"
/**
�����������Ķ��壺������һ�ÿ����������Ǿ����������ʵĶ�������
��1��	���������������գ��������������н���ֵ��С�ڸ�����ֵ��
��2��	���������������գ��������������н���ֵ�����ڸ�����ֵ��
��3��	������������Ҳ�ֱ�Ϊ������������
*/
/**
     ����Ҫ��
       ��ʦҪ��ѧϰ�����˳���ѯ���۰��ѯ
*/
/**
     ����˵����
          ��Ϊ˳���ѯ����Ҫ������˳��ʶ�LS�͵��������˳���ѯ
             �۰��ѯ��Ҫ�������˳���ʹ����orderlist������������ʱ����˳������Ӷ��õ�˳������
          ����˵����
               1 input ����  �Ժ����������طֱ��LS�ͺ�orderlist�͵���������
               2 output ���� �������
               3 orderSearch ����  ��orderlist�͵��������˳���ѯ
               4 halfSearch  ����  �� LS �͵�˳����������۰��ѯ
*/
typedef   struct{
     int key;
}Node,*LS;
typedef struct{
    int data[50];
    int datalength;
}orderList;
typedef struct node{               //�������
    int key;                       //�ؼ�����
    struct node *lchild,*rchild;   //���Һ���ָ��
}BSTNode,*Tree;
BSTNode* initBSTNode(BSTNode *child){
    child = (BSTNode *)malloc(sizeof(BSTNode));
    child->key = 0;
    child->lchild = NULL;
    child->rchild = NULL;
    return child;
}
int insertBST(Tree &T,int data){
             return 1;
}
/**
 @param LS   L    ˳���( ����˳����е�1��Ԫ�ش������ݸ���)
                search    ����Ŀ��
                result    �洢˳������Ѳ鵽�����ݵ��±����Ҳ�������0
**/
int  orderSearch(LS &L,int Search, int &result){
          int i;
          for(i=0; i < L[0].key;i++){
               if(L[i].key == Search){
                       result = i+1;
                       return 1;
               }
          }
          result = 0;
          return 0;
}
/**
   @param orderList L     ����˳���(�������� ��һ��Ԫ����С)
                search    ����Ŀ��
                result    �洢˳������Ѳ鵽�����ݵ��±����Ҳ�������0

*/
int halfSearch(orderList &L,int Search, int &result){
    int Min = 0;
    int Max = L.datalength-1;
    int mid;
    while(L.data[Min]< L.data[Max]){
            mid = (Max + Min)/2;
            if(L.data[mid] == Search){
                 result = mid;
                 return 1;
            }else{
                     if(L.data[mid] < Search)
                            Min = mid;
                    else
                           Max = mid;
            }
    }
      result = 0;
      return 0;
}
int input(LS &L,int datalength){
       int i;
       L[0].key = datalength;
       for(i=1;i<= datalength;i++){
           srand(5*i);
           L[i].key= rand();
       }
       return 1;
}
int input(orderList &L,int datalength){
        int i;
        L.datalength = datalength;
        for(i=0;i<datalength;i++)
            L.data[i] = 3*i;
        return 1;
}
int outPut(orderList &L){
         int i = L.datalength;
         while(i--)
         printf("%d\t",L.data[i]);
         putchar('\n');
         return 1;
}
int outPut(LS &L){
      int i = L[0].key;
      while(i--){
        if(i==1)
        break;
        printf("%d\t",L[i]);
      }
      putchar('\n');
      return 1;
}
int main(){
    orderList W;
    int key;
    int location;
    LS S = (Node *)malloc(20 * sizeof(Node));
    input(S,20);
    input(W,40);
    printf("Now is S***********************\n");
    outPut(S);
    printf("Now is W***********************\n");
    outPut(W);
    printf("input the key  you want to search.........\n");
    scanf("%d",&key);
    if(orderSearch(S,key,location))
        printf("Location ----- %d\nkey------------- %d\n",location,S[location]);
    else
        printf("Oops  not find!!!\n");

    return 1;
}
