#include<stdio.h>
char* friend (char* s)
{
    return "Test";
}
//start 提示：自动阅卷起始唯一标识，请勿删除或增加。
int main()
{
    printf("%s",friend("222"));
}
//end //提示：自动阅卷结束唯一标识，请勿删除或增加。
