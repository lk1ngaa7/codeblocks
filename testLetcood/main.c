#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if(l1 == NULL && l2 != NULL){
        return l2;
    }else if(l1 != NULL && l2 == NULL){
        return l1;
    }else if(l1 == NULL && l2 == NULL){
        return NULL;
    }else{
        struct ListNode *head;

        if(l1->val < l2->val){
            head  = l1;
            l1  = l1->next;
        }else{
            head = l2;
            l2 = l2->next;
        }
        struct ListNode *ptr = head;
        while(l1 != NULL && l2 != NULL){
             if(l1->val < l2->val){
                 head->next = l1;
                 l1 = l1->next;
             }else{
                 head->next = l2;
                 l2 = l2->next;
             }
             head = head->next;
        }
        if( l2 != NULL){
            head->next = l2;
        }
        if(l1 != NULL ){
            head->next = l1;
        }
        return ptr;
    }
}
struct ListNode* create(int *nums,int num){
     int i;
     struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
     struct ListNode* result;
     head->val = nums[0];
     result = head;
     for(i = 1;i < num;i++){
           struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
           temp->val = nums[i];
           head->next = temp;
           head = head->next;
     }
     head->next = NULL;
     return result;
}
int main()
{
    int a1[1] = {5};
    int a2[4] = {1,2,3,4};
    struct ListNode *l1 = create(a1,1);
    struct ListNode *l2 = create(a2,4);
    struct ListNode *r = mergeTwoLists(l1,l2);
    while(r != NULL){
     printf("%d\n",r->val);
     r = r->next;
    }
    return 0;
}
