#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct student
{
	char num[10];
	char name[12];
	char ch;
	int age;
	char adress[30];
	struct student * next;
};

typedef struct student STU;

STU * creat(void);
void show(STU *, int);

int main()
{
	int m, i;
	char l[2];
	STU * lisptr = NULL;
    lisptr = creat();
	printf("请输入输出第几位学生的信息:\n");
	scanf("%d", &m);
	if(m <0 || m > lisptr ->age)
		printf("输入错误！\n");
	else
		show(lisptr, m);
	printf("是否输出全部? y/n:");
	scanf("%s", &l);
	if(strcmp("y", l) == 0)
	{
		for(i=1; i<=lisptr ->age; i++)
			show (lisptr, i);
	}
	return 0;
}

//建立链表；
STU * creat(void)
{
	STU * head, * currentptr, * newptr;
	int i=0;
	printf("输入“*”键结束！\n");
	newptr = (STU *)malloc(sizeof(STU));
	head = newptr;
	currentptr = head;
	newptr = (STU *)malloc(sizeof(STU));
	printf("请输入第%d位学生的学号:\n", i+1);
    scanf("%s", newptr ->num);
	for(; strcmp("*", newptr ->num) != 0; i++)
	{
		printf("请输入第%d位学生的姓名，性别，年龄，住址:\n", i+1);
		scanf("%s %c %d %s", newptr ->name, &newptr ->ch, &newptr ->age, newptr ->adress);
		currentptr ->next = newptr;
		currentptr = currentptr ->next;
		newptr = (STU *)malloc(sizeof(STU));
		printf("请输入第%d位学生的学号:\n", i+2);
		scanf("%s", newptr ->num);
	}
	free(newptr);
	head ->age = i;
	currentptr ->next = NULL;
	return head;
}

//输出链表；
void show(STU * head, int i)
{
	STU * pp;
	pp = head ->next;
	int j;
	for(j=1; j<i; j++)
	{
		pp = pp ->next;
	}
	if (pp == NULL)
		printf("it's empty!");
	else
		printf("%4s %4s %4c %4d %4s\n", pp ->num, pp ->name, pp ->ch, pp ->age, pp ->adress);
}
