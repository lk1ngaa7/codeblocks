#include <stdio.h>
#include <stdlib.h>
int t(int &i);
int main()
{
    int q=4;
    printf("Hello world!%d\n",t(q));
    return 0;
}
int t(int &i){
    return *i;
}
