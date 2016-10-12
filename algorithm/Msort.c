
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 2000

void data_generate();
void TopDownMergeSort(int A[], int B[], int n);
void TopDownSplitMerge(int A[], int iBegin, int iEnd, int B[]);
void TopDownMerge(int A[], int iBegin, int iMiddle, int iEnd, int B[]);
void CopyArray(int B[], int iBegin, int iEnd, int A[]);

int main()
{
	FILE *f1,*f2;
	double duration;
	clock_t  finish, start;
	int i, data[N], work[N],c = 0;
	data_generate();
	
	if ((f1 = fopen("MSdata.txt", "r")) == NULL)
		printf("The file 'MSdata.txt' was not opened\n");
	printf("The file 'MSdata.txt' was opened\n");
	for (i = 0; i < N; i++)
	{
		fscanf(f1, "%d", &data[i]);
	}
	fclose(f1);
	
	start = clock();
	TopDownMergeSort(data, work, N);
	finish = clock();

	if ((f2 = fopen("resultMS.txt", "wt+")) == NULL)
		printf("The file 'resultMS.txt' was not opened\n");
	printf("The file 'resultMS.txt' was not opened\n");
	
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("\nThe CPU time is %2.6f seconds:\n", duration);
	for (i = 0; i < N; i++)
	{
		c++;
		fprintf(f2, "%6d", data[i]);
		if (c == 20)
		{
			fprintf(f2,"\n");
			c = 0;
		}
	}
	//printf("%d,%d\n", data[0], data[N - 1]);
	fclose(f2);

	return 0;
}

void data_generate()//随机生成测试数据，放到文件data.txt中，其中数据是2000个0到10000的数值
{
	int i, j,count = 0;
	FILE* fp;
	if ((fp = fopen("MSdata.txt", "wt+")) == NULL)
		printf("The file 'MSdata.txt' was not opened\n");
	else
		printf("The file 'MSdata.txt' was opened\n");
	srand(time(0));
	for (i = 0; i < N; i++)
	{
		count++;
		j = rand() % 10001;
		fprintf(fp, "%6d ", j);
		if (count == 20)
		{
			fprintf(fp,"\n");
			count = 0;
		}
	}
	if (fclose(fp))
		printf("The file 'MSdata.txt' was not closed\n");
}

void TopDownMergeSort(int A[], int B[], int n)
{
	TopDownSplitMerge(A, 0, n, B);
}

void TopDownSplitMerge(int A[], int iBegin, int iEnd, int B[])
{
	int iMiddle;
	if (iEnd - iBegin < 2)          // 如果只有1个待排元素，返回。
		return;
	// recursively split runs into two halves until run size == 1,
	// then merge them
	iMiddle = (iEnd + iBegin) / 2;     // 划分
	TopDownSplitMerge(A, iBegin, iMiddle, B);
	TopDownSplitMerge(A, iMiddle, iEnd, B);
	TopDownMerge(A, iBegin, iMiddle, iEnd, B);  // 合并；元素放到数组B中。
	CopyArray(B, iBegin, iEnd, A);              // copy the merged runs back to A
}

void TopDownMerge(int A[], int iBegin, int iMiddle, int iEnd, int B[])
{
	int i0 = iBegin, i1 = iMiddle, j;

	// While there are elements in the left or right runs
	for (j = iBegin; j < iEnd; j++) {
		// If left run head exists and is <= existing right run head.
		if (i0 < iMiddle && (i1 >= iEnd || A[i0] <= A[i1])) {
			B[j] = A[i0];
			i0 = i0 + 1;
		}
		else {
			B[j] = A[i1];
			i1 = i1 + 1;
		}
	}
}

void CopyArray(int B[], int iBegin, int iEnd, int A[])
{
	int k;
	for (k = iBegin; k < iEnd; k++)
		A[k] = B[k];
}
