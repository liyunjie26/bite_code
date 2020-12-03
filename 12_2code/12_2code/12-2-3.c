#include<stdio.h>
#include<assert.h>
void find_singal(int *arr, int size)
{
	int i, j;
	int count = 0;
	for (i = 0; i < size ; ++i)
	{
		count = 0;
		if (arr[i] == 0)
			continue;
		for (j = i + 1; j < size; ++j)
		{
			if (arr[i] == arr[j])
			{
				count++;
				arr[i] = 0;
				arr[j] = 0;
			}
			
		}
		if (count == 0)
		{
			printf("单身狗是：%d\n", arr[i]);
		}
	}
}
	int main(){
	
	
		int arr[12] = { 1, 5, 6, 9, 8, 1, 4, 5, 6, 8, 3,4 };
		int size = sizeof(arr) / sizeof(arr[0]);
		find_singal(arr, size);
		return 0;
	}

/*char *my_strncpy(char *strDest, const char *strSource, size_t count)
{
	assert(strDest != NULL&&strSource != NULL);
	char* pd = strDest;
	while (count--)
	{
		*pd++ = *strSource++;
	}
	*pd = '\0';
	return strDest;
}


/*char *my_strncat(char *strDest, const char *strSrc, size_t count)
{
	
	assert(strDest != NULL && strSrc != NULL);
	char *d= strDest;
	const char *s = strSrc;
	while (*d != '\0')//查找连接尾部
		d++;
	while (count-- > 0)
	{
		*d++ = *s++;
	}
	*d = '\0';
return strDest;
}


/*int main()
{
	int* pl = NULL;
	int size;
	printf("请输入你所想要数组元素的个数");
	scanf("%d", &size);
	pl = (int*)malloc(size*sizeof(int));
	if (NULL != pl)
	{
		int i = 0;
		for (; i < size; ++i)
		{
			*(pl + i) = i;
		}
	}
	free(pl);
	pl = NULL;
	return 0;


}*/