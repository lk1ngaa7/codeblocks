#include<stdio.h>
#define N 4

int x[N];

int w[N];
int w1;
int w2;
int c1;
int c2;
int ok;

void output()
{
    int i;
	printf("c1: ");
	for( i = 0 ; i < N ; i++)
	{
		if(x[i] != 0)
		{
			printf("%d\t",i+1);
		}
	}
	printf("\n");
}

//装载第i个物品,基于零的
void load(int i)
{
	if(i >= N)
	{
		ok = 1;
		output();
		return;
	}
	if(ok == 1)
	{
		return;
	}

	//w[i]装载c1上
	x[i] = 1;
	w1 += w[i];
	if(w1 <= c1)
		load(i+1);
	w1 -= w[i];

	//w[i]装载c2上
	x[i] = 0;
	w2 += w[i];
	if(w2 <= c2)
		load(i+1);
	w2 -= w[i];
}

void main()
{   int i;
	c1 = 5;
	c2 = 6;
	for(i = 0 ; i < N ; i++)
	{
		w[i] = i+1;
	}
	load(0);
}

