#include <stdio.h>
#include <stdlib.h>
struct ListNode {
    int val;
     struct ListNode *next;
};
int  getNum(struct ListNode *head){
    int num = 0;
    struct ListNode *p = head;
    while(p!=NULL){
      num++;
      p = p->next;
    }
    return num;
}
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
         int a = getNum(headA);
         int b = getNum(headB);
         int diff = a>b?a-b:b-a;
         struct ListNode *longer = a>b?headA:headB;
         struct ListNode *shorter = a>b?headB:headA;
         while(diff--)
            longer = longer->next;
         while(longer!=NULL){
               if(longer->val == shorter->val)
                 return longer;
               else{
                  longer = longer->next;
                  shorter = shorter->next;
               }

         }
         return NULL;
}
int main()
{
    printf("Hello world!\n");
    return 0;
}
