#include <stdio.h>
#include <stdlib.h>
struct ListNode {
    int val;
struct ListNode *next;
 };
 struct ListNode* MyInsert(struct ListNode *head,struct ListNode *node){
     if(head == NULL)
         return head;
     struct ListNode* now = head;
     struct ListNode* later;
     if(node->val > now->val){
         while(now->next != node){
            now = now->next;
         }
         now->next = node->next;
         node->next = head;
         head = node;
         return head;
     }
     while(now->next != node){
         later = now->next;
         if(node->val < now->val && node->val > later->val){

            while(now->next != node){
                  now = now->next;
            }
            now->next = node->next;

            now->next = node;
            node->next = later;
            return head;
         }
         now = now->next;
     }
     now->next = node;
     return head;
}
struct ListNode *insertionSortList(struct ListNode *head) {
    if(head == NULL)
       return head;
    struct ListNode* ptr = head->next;
    while( ptr != NULL ){
        //struct ListNode* temp = ptr->next;
        head = MyInsert(head,ptr);
        ptr = ptr->next;
    }
    return head;
}
struct ListNode* create1(int *d,int num){
    int i;
    struct ListNode *temp;
    struct ListNode *head;
    struct ListNode *now;
     temp = (struct ListNode*)malloc(sizeof(struct ListNode));
     temp->val = d[0];
     head = temp;
     now = temp;
    for(i = 1;i<num;i++){
         temp = (struct ListNode*)malloc(sizeof(struct ListNode));
         temp->val = d[i];
         now->next = temp;
         now = now->next;
    }
    now->next = NULL;
    return head;
}
struct intWithIndex{
    int val;
    int index;
};
struct intWithIndex* create(int *nums,int numsSize){
    int i;
    struct intWithIndex* data = (struct intWithIndex*)malloc(sizeof(struct intWithIndex)*numsSize);
    for(i = 0;i < numsSize;i++){
            data[i].index = i;
            data[i].val = nums[i];
    }
  return data;
}
void quickSort(struct intWithIndex* nums,int Begin,int End){
    int i = Begin;
    int j = End;
    struct intWithIndex temp = nums[Begin];
    if(i < j){
        while(i<j){
            while(i<j && nums[j].val>temp.val)
                j--;
            if(i<j)
                nums[i++] = nums[j];
            while(i<j && nums[i].val<temp.val)
                i++;
            if(i<j)
                nums[j--] = nums[i];
        }
        nums[i] = temp;
        quickSort(nums,Begin,j-1);
        quickSort(nums,i+1,End);
    }
}
int binarySearch(struct intWithIndex *nums,int target,int Begin,int End){

    while(End >= Begin){
        int middle = Begin + (End - Begin)/2;
        if(nums[middle].val > target){
            End = middle-1;
        }else if(nums[middle].val < target){
            Begin = middle+1;
        }else{
            return middle;
        }

    }
    return -1;

}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    if(nums == NULL){
        *returnSize = 0;
        return NULL;
    }
    struct intWithIndex *data = create(nums,numsSize);
    quickSort(data,0,numsSize-1);
    int i;
    int *result = (int*)malloc(sizeof(int)*2);
    for(i = 0;i < numsSize;i++){

           int temp = target - data[i].val;
           int index2 = binarySearch(data,temp,i+1,numsSize);
           if(index2 == -1){
               continue;
           }else{
             *returnSize = 2;
             result[0] = data[i].index + 1;
             result[1] = data[index2].index + 1;
             if(result[0] > result[1]){
                result[0] = result[0] + result[1];
                result[1] = result[0] - result[1];
                result[0] = result[0] - result[1];
             }
             return result;
           }



    }
        *returnSize = 0;
        return NULL;
}
int main(){
   int data[5]  = {-1,-2,-3,-4,-5};
   /*struct ListNode *head = create(data,4);
   insertionSortList(head);
   */
   int *r;
   int returnSize;
   r = twoSum(data,5,-8,&returnSize);
   if(returnSize != 0)
    printf("%d\n%d\n%d",r[0],r[1],returnSize);
}
