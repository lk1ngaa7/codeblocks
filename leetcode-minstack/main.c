#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int *data;
    int top;
    int dataNum;
    int Min;
    int isInit;
} MinStack;

void minStackCreate(MinStack *stack, int maxSize) {
            if(maxSize <=0 )
                return;
            else{
                stack->data = (int*)malloc(sizeof(int)*maxSize);
                stack->dataNum = maxSize;
                stack->top = 0;
                stack->isInit = 1;
            }
}

void minStackPush(MinStack *stack, int element) {
         if(stack->isInit != 0 ||stack->isInit != 1){
            minStackCreate(stack,10000);
         }
         if(stack->top >= stack->dataNum)
            return;
         stack->data[stack->top++] = element;
         if(stack->isInit == 1){
                stack->Min = element;
                stack->isInit = 0;
         }else{
                 if(stack->Min > element){
                        stack->Min = element;
                 }
         }
}

void minStackPop(MinStack *stack) {
      if(stack->top != 0){
           stack->top--;
      }
}

int minStackTop(MinStack *stack) {
    if(stack->isInit != 1){
        return stack->data[stack->top - 1];
    }else{
       return NULL;
    }
}

int minStackGetMin(MinStack *stack) {
      if(stack->isInit == 1)
         return NULL;
      return stack->Min;
}

void minStackDestroy(MinStack *stack) {
        free(stack);
}
int main()
{
    MinStack s;
    minStackPush(&s,-1);
    minStackPop(&s);
    printf("%d\n",minStackTop(&s));
    printf("%d\n",minStackGetMin(&s));
    return 0;
}
