
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 20000

//��������Ԫ��
void swap(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void data_generate()
{
	int i, j, c = 0;
	FILE* fp;
	if ((fp = fopen("QSdata.txt", "wt+")) == NULL)
		printf("The file 'QSdata.txt' was not opened\n");
	else
		printf("The file 'QSdata.txt' was opened\n");
	srand(time(0));
	for (i = 0; i < N; i++)
	{
		c++;
		j = rand() % 10001;
		fprintf(fp, "%6d ", j);
		if (c == 25)
		{
			c = 0;
			fprintf(fp,"\n");
		}
	}
	if (fclose(fp))
		printf("The file 'QSdata.txt' was not closed\n");
}
int partition(int *A, int begin, int end)
{
	int i, j,x;
	x = end;
	i = begin - 1;
	for (j = begin;j < end;j++)
	{
		if (A[j] <= A[x])
		{
			i++;
			swap(&A[i],&A[j]);
		}
	}
	swap(&A[i + 1], &A[x]);
	return i + 1;
}

void quicksort(int *A, int begin, int end)
{
	int p;
	if (begin < end)
	{
		p = partition(A, begin, end);
		quicksort(A, begin, p - 1);
		quicksort(A, p + 1, end);
	}
}

int main()
{
	FILE *f1,*f2;
	double duration;
	clock_t  finish, start;
	int i, data[N],count = 0;
	data_generate();

	if ((f1 = fopen("QSdata.txt", "r")) == NULL)
		printf("The file 'QSdata.txt' was not opened\n");
	printf("The file 'QSdata.txt' was opened\n");
	for (i = 0; i < N; i++)
	{
		fscanf(f1, "%d", &data[i]);
	}
	fclose(f1);
	if ((f2 = fopen("resultQS.txt", "wt+")) == NULL)
		printf("The file 'resultQS.txt' was not opened\n");
	printf("The file 'resultQS.txt' was opened\n");

	start = clock();
	quicksort(data, 0, N - 1);
	finish = clock();

	for (i = 0; i < N; i++)
	{
		count++;
		fprintf(f2, "%6d", data[i]);
		if (count == 25)
		{
			fprintf(f2,"\n");
			count = 0;
		}
	}
	//printf("data[0] = %d,data[1999] = %d\n", data[0], data[N - 1]);
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("\nThe CPU time is %2.6f seconds:\n", duration);
	fclose(f2);
	return 0; 
}
