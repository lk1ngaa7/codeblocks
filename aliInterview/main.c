#include <stdio.h>
#include <stdlib.h>
void quickSort(int* nums,int Begin,int End){
    int i = Begin;
    int j = End;
    int temp = nums[Begin];
    if(i < j){
        while(i<j){
            while(i<j && nums[j]>temp)
                j--;
            if(i<j)
                nums[i++] = nums[j];
            while(i<j && nums[i]<temp)
                i++;
            if(i<j)
                nums[j--] = nums[i];
        }
        nums[i] = temp;
        quickSort(nums,Begin,j-1);
        quickSort(nums,i+1,End);
    }
}
int binarySearch(int *nums,int target,int Begin,int End){

    while(End > Begin){
        int middle = Begin + (End - Begin)/2;
        if(nums[middle] > target){
            Begin = middle+1;
        }else if(nums[middle] < target){
            End = middle-1;
        }else{
            return middle;
        }

    }
    return -1;

}
int twoSum(int* nums, int numsSize, int target) {
    if(nums == NULL){
        return 0;
    }
    quickSort(nums,0,numsSize-1);
    int i;
    int *result = (int*)malloc(sizeof(int)*2);
    for(i = 0;i < numsSize;i++){
       if(nums[i] < target ){
           int temp = target - nums[i];
           int index2 = binarySearch(nums,temp,0,numsSize);
           if(index2 == -1){
               continue;
           }else{
             return 1;
           }

       }

    }
        return 0;
}
int main(){
   int data[4]  = {4,2,1,3};
   int isExisted = 0;
   isExisted = twoSum(data,4,2);
   if(isExisted == 0)
       printf("Not Exists");
   else{
       printf("Yes it's here");
   }
}
