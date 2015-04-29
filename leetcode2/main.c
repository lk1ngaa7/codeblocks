#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
void rotate(int nums[], int n, int k) {
    if(k>n)
        k = k%n;
    printf("%d\n",k);
    int *temp  = (int*)malloc(sizeof(int)*k);
    int i  = n,j = k-1;
    for(;j>=0;){
        temp[j--] = nums[--i];
    }
    for(i = n-1;i >=k;i--){
        nums[i] = nums[i-k];
    }
    for(i=0;i<k;i++){
        nums[i] = temp[i];
    }
}
char* convertToTitle(int n) {
    int level = getLevel(n);
    char *s = (char *)malloc(sizeof(char)*level);
    printf("%d\n",level);
    level--;
    setTitle(s,n,&level);
    return s;
}
void setTitle(char *s,int target,int *level){
      char base = 'A';
      if(target > 27){
         char c = base + (target%27);
         target /= 27;
         *(s+*level) = c;
         *level -= 1;
         setTitle(s,target,level);
      }else{
         *(s+*level) = base + target;
         *level--;
      }
}
int getLevel(int target){
    int i;
    for(i = 1;target > 26;){
         target/=26;
         i++;
    }
    return i;
}
int main()
{
    /*int nums[6] = {1,2,3,4,5,6};
    int i;
    rotate(nums,6,11);
    for(i = 0;i<6;i++)
        printf("%d\n",nums[i]);
    */
    printf("%s",convertToTitle(52));
    return 0;
}
