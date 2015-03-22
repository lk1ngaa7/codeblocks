#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 64;
    printf("%d\n",n&(n-1)?0:1);
    return 0;
}
