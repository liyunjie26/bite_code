#include<stdio.h>
#include<limits.h>
#include<vld.h>


/*
void main()//¶¯Ì¬¿ª±Ù
{
	int **arr = (int**)malloc(sizeof(int *)* 5);
	if (NULL == arr)
	return;
	for (int i = 0; i < 5; ++i)
	{
	*(arr + i) = (int *)malloc(sizeof(int)* 5);
	}
	for (int i = 0; i < 5; ++i)
	{
	for (int j = 0; j < 5; ++j)
	{
	*(*(arr + i) + j) = i + j;
	}
	}
	for (int i = 0; i < 5; ++i)
	{
	for (int j = 0; j < 5; ++j)
	{
	printf("%d", *(*(arr + i) + j));
	}
	printf("\n");
	}
		for (int i = 0; i < 5; ++i)
		{
			free(arr[i]);
		}
		free(arr);
	}

/*void main()
{
	int n = 5;
	int* p = (int *)malloc(sizeof(int)*n);
	if (NULL == p)
		return;
	for (int i = 0; i < n; ++i)
	{
		p[i] = i + 1;

	}
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", p[i]);
	}
	free(p);


}*/