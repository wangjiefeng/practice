#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>

#define EDGE 10
#define VERTEX 7
#define MAX 10000

int minimum();
void dijkstra();
void find_path(int x);
void inputtofile(FILE *f,int d[]);

int mark[VERTEX];                       //������
int set[VERTEX];                        //��Դ����С�������Ķ��㼯
int graph[VERTEX][VERTEX] =             //Ȩֵ����
	{
		{0,0,0,0,0,0,0},
		{MAX,0,2,15,MAX,MAX,MAX},
		{MAX,20,0,MAX,MAX,10,30},
		{MAX,MAX,4,0,MAX,MAX,10},
		{MAX,MAX,MAX,MAX,0,MAX,MAX},
		{MAX,MAX,MAX,MAX,15,0,MAX},
		{MAX,MAX,MAX,MAX,4,10,0}
	};
int pathestimate[VERTEX];               //���������·��
int predecessor[VERTEX];                //����ĸ��ڵ�

int main()
{
	FILE *fp;
	memset(mark, 0, sizeof(mark));
	memset(pathestimate, MAX, sizeof(pathestimate));
	dijkstra(VERTEX);

	if ((fp = fopen("dijkstra-output0.txt", "wt")) == NULL)
		printf("Can't open dijkstra-output0.txt !");
	for (int i = 1; i <= VERTEX; i++)
	{
		for (int j = 1; j < VERTEX; j++)
		{
			fprintf(fp,"%-10d",graph[i][j]);
		}
		fprintf(fp, "\n");
	}
	fclose(fp);

	fp = fopen("dijkstra-output1.txt", "wt");
	inputtofile(fp, pathestimate);

	fp = fopen("dijkstra-output2.txt", "wt");
	inputtofile(fp,predecessor);

	//printf("*************************************\n");
	//printf("*finished by Wangjiefeng(2013211486)*\n");
	//printf("*************************************\n\n");

	int v; 
	printf("������Ҫ���ҵĶ��㣨-1�˳�����");
	scanf("%d",&v);
	while (v != -1)
	{
		find_path(v);
		printf("\n·������Ϊ��%d\n", pathestimate[v]);
		printf("*************************************\n");
		printf("������Ҫ���ҵĶ��㣨-1�˳�����");
		scanf("%d", &v);
	}

	return 0;
}

int minimum()
{
	int index = -1, min = MAX;
	for (int i = 1;i < VERTEX; i++)
	{
		if (!mark[i] && pathestimate[i] < min)
		{
			index = i;
			min = pathestimate[i];
		}
	}
	return index;
}

void dijkstra(int num_of_vertices)
{
	int count = 0;
	int u = 1;
	pathestimate[u] = 0;    //vertex1 is the source vertex!
	predecessor[u] = u;
	
	while (count < num_of_vertices)                         //set����δ��ʱѭ��
	{
		u = minimum();    //��Դ�㵽u�����·��
		if (u == -1)                    
			break;
		set[++count] = u;		                                // u���뵥Դ����С�������Ķ��㼯
		mark[u] = 1;
		for (int i = 1; i < num_of_vertices; i++)
		{
			if (graph[u][i] <MAX && mark[i] != 1)
			{	                                           // ����u��i�л����� ���� ����i��Դ������·����û��ȷ��
				if (pathestimate[i] > pathestimate[u] + graph[u][i])
				{
					pathestimate[i] = pathestimate[u] + graph[u][i];
					predecessor[i] = u;
				}
			}
		}
	}
}

void find_path(int x)
{
	if (predecessor[x] != x)
	{
		find_path(predecessor[x]);
	}
	printf("%d ",x);
}

void inputtofile(FILE *f,int d[])
{
	if ( f == NULL)
		printf("Can't open the file!");
	for (int i = 1; i < VERTEX; i++)
	{
		fprintf(f, "%3d", d[i]);
	}
	fclose(f);
}