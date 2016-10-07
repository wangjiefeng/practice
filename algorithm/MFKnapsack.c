#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>

#define N 100  //number 
#define M 100  //weight
int v[N][M];
int P[N];
int Weights[N];
int Value[N];

int max(int x,int y);
int MFKnapsack(int a, int b);
void find(int a,int b);
int main()
{
	int i, j, val = 0;
	int count, w;
	printf("��������Ʒ��������");
	scanf("%d", &count);
	printf("�����뱳�����أ�");
	scanf("%d", &w);
	printf("��������Ʒ�ļ�ֵ������:\n");
	for (i = 1; i <= count; i++)
	{
		scanf("%d %d", &Value[i], &Weights[i]);
	}
	for (i = 0; i <= count; i++)
	{
		for (j = 0; j <= w; j++)
		{
			if (i == 0 || j == 0)
			{
				v[i][j] = 0;
			}
			else
				v[i][j] = -1;
		}
	}

	val = MFKnapsack(count, w);
	printf("���ż�ֵΪ:%d\n", val);

	FILE *fp;
	fp = fopen("data.txt", "wt");
	for (i = 1; i <= count; i++)
	{
		for (j = 1; j <= w; j++)
		{
			fprintf(fp, "%d ", v[i][j]);
		}
		fprintf(fp, "\n ");
	}
	find(count,w);
	//�����ѡ�����Ʒ��
	printf("\nѡ�����ƷΪ��\n");
	for (i = 1; i <= count; i++)
	{
		if (P[i])
			printf("%d ",i);
	}
	printf("\n");
	
	return 0;
}

int max(int x,int y)
{
	return x>y?x:y;
}

void find(int a, int b)
{
	int i = a, j = b;
	while (i&&j)
	{
		if (v[i][j] == v[i - 1][j - Weights[i]] + Value[i])
		{
			P[i] = 1;
			j -= Weights[i];
		}
		else
			i--;
	}
}

int MFKnapsack(int a, int b)
{
	int value;
	if (v[a][b] < 0)
	{
		if (b < Weights[a])
		{		
			value = MFKnapsack(a - 1, b);
		}
		else
		{
			value = max(MFKnapsack(a - 1, b), Value[a] + MFKnapsack(a - 1, b - Weights[a]));
		}
		v[a][b] = value;
	}
	return v[a][b];

}