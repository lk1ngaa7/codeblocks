#include "stdio.h"
#include "stdlib.h"
#define  STACKSIZE  20
#define  QUEUESIZE  20
typedef  struct stO{
        int  *E;
        int top;
}*stackOrder;
typedef struct S{
        int E;
        struct S *next;
}stackNode;
typedef  struct stL{
         stackNode  *top,*head;
         int stackSize;
}*stackList;
typedef  struct q{
        int *E;
        int  head;
        int  pear;
        int exceed;
}*QUEUE;
bool init(stackOrder &So);
bool init(stackList &Sl);
bool init(QUEUE &Q);
bool  push(stackOrder &So,int e);
bool  push(stackList &Sl,int e);
bool  push(QUEUE &Q,int e);
int    pop(stackOrder &So);
int    pop(stackList &Sl);
int    pop(QUEUE &Q);
int main(){
     stackOrder so;
     stackList   sl;
     QUEUE q;
     int i=0;
     //  初始化
     init(so),init(sl),init(q);
     //   插入数据
     while(++i<9)
     push(so,i),push(sl,i),push(q,i);
     //  输出数据
     printf("orderStack,listStack,queue\n");
     while(--i)
     printf("\t%d\t%d\t%d\n",pop(so),pop(sl),pop(q));
}
bool init(stackOrder &So){
        So = (stackOrder)malloc(sizeof(struct stO));
         So->E = (int *)malloc(sizeof(int)*STACKSIZE);
         if(!So->E)
            return false;
            So->top = 0;
            return true;
}
bool init(stackList &Sl){
         Sl = (stackList)malloc(sizeof(struct stL));
         Sl->stackSize = 0;
         return true;
}
bool init(QUEUE &Q){
         Q  = (QUEUE)malloc(sizeof(struct q));
          Q->E = (int *)malloc(sizeof(int)*QUEUESIZE);
          if(!Q)
            return false;
            Q->head = 0;
            Q->pear = 0;
            Q->exceed =0;
            return true;
}
bool  push(stackOrder &So,int e){
             if(!So||!So->E)
                 return false;
              So->E[So->top++] = e;
              return true;
}
bool  push(stackList &Sl,int e){
       if(!Sl)
          return false;
         if(Sl->stackSize==0){
         Sl->top  = (stackNode*)malloc(sizeof(stackNode));
         Sl->head = Sl->top;
         Sl->top->E = e;
         Sl->stackSize++;
         }
         Sl->top->next = (stackNode*)malloc(sizeof(stackNode));
         Sl->top = Sl->top->next;
          Sl->top->E = e;
          Sl->stackSize++;
          return true;
}
bool  push(QUEUE &Q,int e){
       if(!Q||!Q->E)
       return false;
       if(Q->exceed == QUEUESIZE)
             return false;
        if(Q->pear == QUEUESIZE-1)
            Q->pear = 0;
        Q->E[Q->pear++] = e;
        Q->exceed++;
        return true;
}
int  pop(stackOrder &So){
      if(!So)
         return 0;
      return So->E[--So->top];
}
int   pop(stackList &Sl){
    int re;
    stackNode *temp = Sl->head;
       if(!Sl)
          return 0;
          while(temp->next!=Sl->top)
              temp = temp->next;
      re = Sl->top->E;
      Sl->top = temp;
      return re;
}
int  pop(QUEUE &Q){
       if(!Q)
          return 0;
          if(Q->head==Q->pear)
          return 0;
       return Q->E[Q->head++];
}
