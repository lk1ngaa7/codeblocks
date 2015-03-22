#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char* friend (char* s)
{
    char *str;
    int num  = strlen(s);
    int i = num;
    str = (char *)malloc(sizeof(char)*(num+1));
    strcpy();
    printf("%d",num);

    while(s[i--]=='0');
    ++i;
    s[i]=s[i]-'1',s[i-1]=s[i-1]+'2';
  return s;
}
//start 提示：自动阅卷起始唯一标识，请勿删除或增加。
int main()
{
    printf("%s",friend("222"));
}
//end //提示：自动阅卷结束唯一标识，请勿删除或增加。
