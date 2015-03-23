#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
   char data;
   struct Node *L;
   struct Node *R;
}N;
typedef struct binaryTree{
   struct Node* head;
   int height;
   int weight;
   int nodeNum;
}T;

typedef struct stackNode{
     N *data;
     struct stackNode *pre;
}sn;
typedef struct stack{
    int nodeNum;
    sn* top;
}S;

void push(S* s,N node){
  sn* newSn = (sn*)malloc(sizeof(sn));
  if(s->top == NULL){
      newSn->pre = NULL;
  }else{
      newSn->pre = s->top;
  }
  newSn->data = &node;
  s->nodeNum++;
  s->top = newSn;

}
void pop(S* s){
   sn* oldSn = s->top;
   s->top = oldSn->pre;
   free(oldSn);
}
// @param  扩展先序遍历序列
T generateBinaryTree(char *a,int length){

    int i;
    S* stack =(S*)malloc(sizeof(S));
    T t;
    if(a[0] == '#')
        return t;
    for(i = 0;i<length;i++){
          N node = (node)malloc(sizeof(node));
         if(a[i]!='#'){
            node.data =a[i];

            if(stack->top->data->L == NULL)
                stack->top->data->L = &node;
            else if(stack->top->data->R == NULL)
                stack->top->data->R = &node;
             if(stack->top->data->L != NULL && stack->top->data->R != NULL)
                    pop(stack);
                    push(stack,node);
         }else{
            if(stack->top->data->L == NULL)
                stack->top->data->L = '#';
            else if(stack->top->data->R == NULL)
                stack->top->data->R = '#';
             if(stack->top->data->L != NULL && stack->top->data->R != NULL)
                    pop(stack);

        }

    }
    t.head = stack->top->data;
}
int main()
{

    printf("Hello world!\n");
    return 0;
}
