#include<stdio.h>
char* friend (char* s)
{
    return "Test";
}
//start ��ʾ���Զ��ľ���ʼΨһ��ʶ������ɾ�������ӡ�
int main()
{
    printf("%s",friend("222"));
}
//end //��ʾ���Զ��ľ����Ψһ��ʶ������ɾ�������ӡ�
