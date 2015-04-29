#include <stdio.h>
#include <stdlib.h>
typedef struct  TreeNode{
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};
void CT(struct TreeNode **root){
    char val;
    printf("input the data:\n");
    scanf("%c",&val);
    getchar();
    if(val == '#')
        *root = NULL;
    else{
        *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        (*root)->val = val - '0';
        CT(&(*root)->left);
        CT(&(*root)->right);
    }

}
void preOrder(struct TreeNode *T){
      if(T == NULL)
        printf("#\t");
      else{
         printf("%d\t",T->val);
         preOrder(T->left);
         preOrder(T->right);
      }
}
int *rightSideView(struct TreeNode *root, int *n) {
     if(root == NULL){
        return NULL;
        *n = 0;
    }
    struct TreeNode *p  = root;
    int num = 0,j = 0;
    int *re = (int *)malloc(sizeof(int));
   do{
        if(j == 1){
             realloc(re,sizeof(int)*(num+1));
             j = 0;
        }
        re[num++] = p->val;
        j++;
        p = p->right?p->right:p->left;

    }while(p != NULL);
    *n = num;
    return re;
}
int main()
{
    struct TreeNode *T;
    int num;
    int *re;
    int i;
    CT(&T);
    //preOrder(T);
    re = rightSideView(T,&num);
    printf("%d\n",num);
    for(i = 0;i< num;i++)
        printf("%d\t",re[i]);
}
