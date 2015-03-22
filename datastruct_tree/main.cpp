#include "stdio.h"
#include "stdlib.h"
typedef struct Tree{
     char  E;
     struct Tree *Lchild;
     struct Tree *Rchild;
}treeNode,*BTree;
typedef struct Stack_tree{
     BTree s[20];
     int top;
}St;
int Create_Pre(BTree &T);
BTree Pop(St *&S);
BTree Push(St *&S);
BTree getTop(St *&S);
BTree exchange(BTree &T);
bool check(char *&input);
/**  非递归前序遍历  ***/
bool TraPre(BTree &T);
/***  非递归中序遍历 **/
bool TraMid(BTree &T);
/**  非递归后序遍历 ***/
bool TraPost(BTree &T);
/*** 递归前序遍历  **/
void TraPre_re(BTree &T);
/**  递归中序遍历  ***/
void TraMid_re(BTree &T);
/** 递归后序遍历  ***/
void TraPost_re(BTree &T);
/**  计算二叉树深度  */
int Compute_tree(BTree &T);
/**   计算二叉树节点数目  */
int ComputeNode(BTree &T);
int main(){
    BTree t;
    //St* s = calloc(sizeof(St),1);
    int num=0;
    // 按前序的规则生成一棵二叉树
    if(!Create_Pre(t)||t==NULL)
        exit(0);
    /*
    printf("\nPreview Traverse\n");
    TraPre(t);

    exchange(t);

    printf("\nPreview Traverse after exchange\n");
    TraPre(t);
    */
    printf("\nNumbers:%d\n",ComputeNode(t));
}
int Compute_tree(BTree &T){
       if(T == NULL)
        return 0;
       else{
        int l = Compute_tree(T->Lchild);
        l++;
        int r = Compute_tree(T->Rchild);
        r++;
        return l>=r?l:r;

       }
}
/****
   算法描述：
   1. 一棵树的节点数等于左右两棵子树的节点数之和
   2. 空树的节点数为0

*/
int ComputeNode(BTree &T){
    if(T == NULL)
        return 0;
    else
        return ComputeNode(T->Lchild) + ComputeNode(T->Rchild) + 1;

}
BTree getTop(St *&S){
    if(S->top == 0)
        return NULL;
    return S->s[S->top-1];
}
bool check(char *&input){
     int pause = 0,ch = 0;
     int i = 0;
     while(input[i]){
            i++;
        if(input[i]=='@'){
            pause++;
            continue;
        }
      ch++;
     }
     if(ch!= pause)
        return false;
     return true;
}
BTree Pop(St *&S){
    if(S->top == 0)
        return NULL;
    return S->s[--S->top];
}
BTree Push(St *&S,BTree e){
      return S->s[S->top++]= e;
}
int Create_Pre(BTree &T){
     St *st;
     char *str= (char*)malloc(sizeof(char)*40);
     int i=1;
     bool isCreateR = false;
     BTree pop,temp;
     st = (St*)calloc(sizeof(St),1);
     st->top = 0;
     printf("Input a string with preorder (end with '*') :\n");
     gets(str);
     // check() 函数检查输入的数据是否正确
     if(!check(str)){
        printf("ERROR!!\n");
        return 0;
       }
      if(str[0]=='@'&&st->top==0){
        return 0;
        T = NULL;
      }
      T = (BTree)calloc(sizeof(treeNode),1);
      T->E = str[0];
      Push(st,T);
     while(str[i]!='*'){
        if(str[i]=='@'){
                //   终端节点 = 度为2的节点 + 1
              if(st->top == 0){
                     printf("creating success!!!");
                     return 1;
                }
                pop = Pop(st);
                isCreateR = true;
                //st->s[--st->top]->Lchild == NULL;
         }else{
                temp =(BTree)calloc(sizeof(treeNode),1);
                temp->E = str[i];
             if(isCreateR){
                 pop->Rchild = temp;
                 Push(st,temp);
                 isCreateR = false;
             }else{
               st->s[st->top-1]->Lchild = temp;
               Push(st,temp);
             }
        }
        i++;
  }
  printf("error!!\n");
  return 0;
}
bool TraPre(BTree &T){
       St *st = (St*)malloc(sizeof(St));
       BTree pop = T;
       st->top = 0;
       while(pop){
        printf("%c\t",pop->E);
        if(pop->Rchild)
            Push(st,pop->Rchild);
        if(pop->Lchild)
            pop = pop->Lchild;
        else{
            pop=Pop(st);
         }
       }
    return true;
}
bool TraMid(BTree &T){
       St *st = (St*)malloc(sizeof(St));
       BTree pop = T;
       st->top = 0;
       if(!T)
        return false;
       while(pop||st->top){
            while(pop){
                Push(st,pop);
                pop = pop->Lchild;
            }
            pop = Pop(st);
            printf("%c\t",pop->E);
            pop = pop->Rchild;
        }

   return true;
}
bool TraPost(BTree &T){
       St *st = (St*)malloc(sizeof(St));
       BTree pop = T;
       bool isOut = false;
       st->top = 0;
        if(!T)
        return false;
       while(pop||st->top){
            if(isOut){
                 pop = Pop(st);
                 printf("%c\t",pop->E);
                 isOut = false;
                 if(!getTop(st))
                    break;
                 if(pop == getTop(st)->Rchild)
                       isOut = true;
                 else
                    pop = getTop(st)->Rchild;

               }else{
                        if(pop){
                          Push(st,pop);
                          pop = pop->Lchild;
                        }
                         else{
                                pop = getTop(st)->Rchild;
                            if(! pop){
                                isOut = true;
                                }

                        }
            }

   }
   return true;
}
/*
   递归交换左右子树
*/
BTree exchange(BTree &T){
    BTree temp=NULL;
    if(T->Lchild||T->Rchild){
        if(T->Lchild){
           temp = T->Rchild;
           T->Rchild = exchange(T->Lchild);
        }
        if(temp){
            T->Lchild = exchange(temp);
        }else{
            T->Lchild = NULL;
        }
    }
    return T;
}
void TraPre_re(BTree &T){
      if(T){
        printf("%c\t",T->E);
       TraPre_re(T->Lchild);
       TraPre_re(T->Rchild);

      }
}
void TraMid_re(BTree &T){
      if(T){
        TraMid_re(T->Lchild);
        printf("%c\t",T->E);
       TraMid_re(T->Rchild);

      }
}
void TraPost_re(BTree &T){
      if(T){
        TraPost_re(T->Lchild);
        TraPost_re(T->Rchild);
        printf("%c\t",T->E);
    }
}
