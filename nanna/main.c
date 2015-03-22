#include <stdio.h>
#include <conio.h>
int main(){
	float F,M,Y,C,X;
	char gender;  // 表示性别
	printf("请输入父亲身高：\n");
	scanf("%f",&M);
	printf("请输入母亲身高：\n");
	scanf("%f",&F);
	getchar();
	printf("请输入您的性别(m==男，f==女):\n");
	scanf("%c",&gender);
	printf("q请输入您的身高:\n");
	scanf("%f",&X);

	if (gender == 'm')
		Y=(F+M)*1.08/2;
	if (gender == 'f')
		Y=(F*0.923+M)/2;
    C=Y-X;


	printf("母亲身高：%f\n,父亲身高：%f\n,计算身高：%f\n,您的身高：%f\n,误差：%f\n",F,M,Y,X,C);
}
