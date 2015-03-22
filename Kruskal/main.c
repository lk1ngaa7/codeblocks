#include <stdio.h>
#include <stdlib.h>

#define MAX 100

/* �����(x,y)��ȨΪw */
typedef struct
{
	int x, y;
	int w;
}edge;

edge e[MAX];
/* rank[x]��ʾx���� */
int rank[MAX];
/* father[x]��ʾx�ĸ��ڵ� */
int father[MAX];
int sum;

/* �ȽϺ�������Ȩֵ(��ͬ��x����)�ǽ������� */
int cmp(const void *a, const void *b)
{
	if ((*(edge *)a).w == (*(edge *)b).w)
	{
		return (*(edge *)a).x - (*(edge *)b).x;
	}
	return (*(edge *)a).w - (*(edge *)b).w;
}

/* ��ʼ������ */
void Make_Set(int x)
{
	father[x] = x;
	rank[x] = 0;
}

/* ����xԪ�����ڵļ���,����ʱѹ��·�� */
int Find_Set(int x)
{
	if (x != father[x])
	{
		father[x] = Find_Set(father[x]);
	}
	return father[x];
}

/* �ϲ�x,y���ڵļ��� */
void Union(int x, int y, int w)
{
 	sum += w;
	if (x == y) return;
	/* ���Ƚ�С�������ӵ��Ƚϴ������ */
	if (rank[x] > rank[y])
	{
		father[y] = x;
	}
	else
	{
		if (rank[x] == rank[y])
		{
			rank[y]++;
		}
		father[x] = y;
	}
}

/* ������ */
int main()
{
	int i, n;
	int x, y;
	char chx, chy;

	/* ��ȡ�ߵ���Ŀ */
	scanf("%d", &n);
	getchar();

	/* ��ȡ����Ϣ����ʼ������ */
	for (i = 0; i < n; i++)
	{
		scanf("%c %c %d", &chx, &chy, &e[i].w);
		getchar();
		e[i].x = chx - 'A';
		e[i].y = chy - 'A';
		Make_Set(i);
	}

	/* �������� */
	qsort(e, n, sizeof(edge), cmp);

	sum = 0;

	for (i = 0; i < n; i++)
	{
		x = Find_Set(e[i].x);
		y = Find_Set(e[i].y);
		if (x != y || (!x && !y))
		{
			printf("%c - %c : %d\n", e[i].x + 'A', e[i].y + 'A', e[i].w);
			Union(x, y, e[i].w);
		}
	}

	printf("Total:%d\n", sum);
	system("pause");
	return 0;
}
