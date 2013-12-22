#include "stdio.h"
#include "stdlib.h"
/**
二叉排序树的定义：或者是一棵空树；或者是具有下列性质的二叉树：
（1）	若它的左子树不空，则左子树上所有结点的值均小于根结点的值；
（2）	若它的右子树不空，则右子树上所有结点的值均大于根结点的值；
（3）	它的左、右子树也分别为二叉排序树。
*/
/**
     课堂要求：
       老师要求学习链表的顺序查询和折半查询
*/
/**
     代码说明：
          因为顺序查询不需要链表有顺序故对LS型的链表进行顺序查询
             折半查询需要链表带有顺序故使用了orderlist型链表在输入时进行顺序输入从而得到顺序链表
          函数说明：
               1 input 函数  对函数进行重载分别对LS型和orderlist型的链表输入
               2 output 函数 输出链表
               3 orderSearch 函数  对orderlist型的链表进行顺许查询
               4 halfSearch  函数  对 LS 型的顺许链表进行折半查询
*/
typedef   struct{
     int key;
}Node,*LS;
typedef struct{
    int data[50];
    int datalength;
}orderList;
typedef struct node{               //结点类型
    int key;                       //关键字项
    struct node *lchild,*rchild;   //左右孩子指针
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
 @param LS   L    顺序表( 这种顺序表中第1个元素储存数据个数)
                search    搜索目标
                result    存储顺序表中已查到的数据的下表，查找不到返回0
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
   @param orderList L     有序顺序表(降序排序 第一个元素最小)
                search    搜索目标
                result    存储顺序表中已查到的数据的下表，查找不到返回0

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
