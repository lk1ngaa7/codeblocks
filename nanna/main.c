#include <stdio.h>
#include <conio.h>
int main(){
	float F,M,Y,C,X;
	char gender;  // ��ʾ�Ա�
	printf("�����븸����ߣ�\n");
	scanf("%f",&M);
	printf("������ĸ����ߣ�\n");
	scanf("%f",&F);
	getchar();
	printf("�����������Ա�(m==�У�f==Ů):\n");
	scanf("%c",&gender);
	printf("q�������������:\n");
	scanf("%f",&X);

	if (gender == 'm')
		Y=(F+M)*1.08/2;
	if (gender == 'f')
		Y=(F*0.923+M)/2;
    C=Y-X;


	printf("ĸ����ߣ�%f\n,������ߣ�%f\n,������ߣ�%f\n,������ߣ�%f\n,��%f\n",F,M,Y,X,C);
}
