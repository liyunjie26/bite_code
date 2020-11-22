#include<stdio.h>
#include<assert.h>
/*char *my_strcpy(char *a1,const char *a2)//模拟strcpy功能
{
	if (*a2 == '\0')
	{
		*a1 = *a2;
		return *a2;
	}
		
	*a1 = *a2; 
	my_strcpy(++a1, ++a2);
}*/
char *my_strcpy(char *strDest, const char *strSrc)//模拟strcpy功能修改
{
	assert(strDest != NULL && strSrc != NULL);
	char *res = strDest;
	while (*strSrc != '\0')
	{
		*res = *strSrc;
		res ++ ;
		strSrc++;
	}
	*res ='\0';
	return strDest;
}
int main()
{
	char arr[20] = "hello";
	char* arr2 = "bit";
	char *a=my_strcpy(arr, arr2);
	printf("%s\n", arr);
}
/*
int main()
{
	char *c[] = { "ENTER", "NEW", "POINT", "FIRST" };
	char**cp[] = { c + 3, c + 2, c + 1, c };
	char***cpp = cp;
	printf("%s\n", **++cpp);
	printf("%s\n", *--*++cpp + 3);
	printf("%s\n", *cpp[-2] + 3);
	printf("%s\n", cpp[-1][-1] + 1);
	return 0;
}*/