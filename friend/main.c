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
//start ��ʾ���Զ��ľ���ʼΨһ��ʶ������ɾ�������ӡ�
int main()
{
    printf("%s",friend("222"));
}
//end //��ʾ���Զ��ľ����Ψһ��ʶ������ɾ�������ӡ�
