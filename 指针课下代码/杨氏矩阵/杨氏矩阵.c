#include<stdio.h>
#define	ROW 4
#define CLO 4
int Young_matrix(int arr[][CLO], int *row, int *clo, int find_n)
{
	int i = 0;
	int j = CLO-1;
	if (find_n<**arr || find_n>*((arr+ROW-1)[CLO - 1]))
		return 0;
	while (j >= 0 && i <= ROW - 1)
	{
		if (find_n == (*(arr + i))[j])
		{
			*row = i;
			*clo = j;
			return 1;
		}
		else if (find_n > (*(arr+i))[j])
		{
			++i;
		}
		else
		{
			--j;
		}

	}
	return 0;
}
int main()
{
	int arr[ROW][CLO] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16 } };
	int row, clo, find_n, flag;
	printf("please input number you want to find:>");
	scanf("%d", &find_n);
	flag = Young_matrix(arr, &row, &clo, find_n);
	if (flag == 1)
	{
		printf("success find:%d––£¨%d¡–\n", row + 1, clo + 1);
	}
	else
	{
		printf("we have not find \n");

	}
}