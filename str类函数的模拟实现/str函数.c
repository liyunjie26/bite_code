#include<stdio.h>
#include<assert.h>
char *my_strcat(char *strD, const char *strS)
{
	assert(strD != NULL && strS != NULL);
	char* strd = strD;
	const char* strs = strS;
	while (*strd != '\0')
	{
		strd++;
	}
	while (*strs != '\0')
	{
		*strd++ = *strs++;
	}
	*strd = '\0';
	return strD;

}
int my_strcmp(const char *str1, const char *str2)//strcmp的模拟实现
{
	assert(str1 != NULL && str2 != NULL);
	const char* s1 = str1;
	const char* s2 = str2;
	int result;
	while (*s1 != '\0' || *s2 != '\0')
	{
		if (*s1 - *s2 != 0)
			break;
		s1++;
		s2++;
	}
	result = *s1 - *s2;
	return result;
}
int my_strlen(const char *str)//strlen的模拟实现
{
	const char *str_c = str;//保护指针
	int count = 0;
	assert(str != NULL);//断言，保证指针不为空
	while (*str_c != '\0')
	{
		count++;
		str_c++;
	}
	return count;
}
char *my_strcpy(char *strD, const char *strS)
{
	assert(strD != NULL && strS != NULL);
	char* strd = strD;
	const char* strs = strS;
	while (*strs != '\0')
	{
		*strd++ = *strs++;
	}
	*strd = '\0';
	return strD;
}
char *my_strstr(const char *str1, const char *strf)//模拟strstr
{
	assert(str1 != NULL && strf != NULL);
	const char* str1_1 = str1;
	const char* strf_f = strf;
	char *pl = NULL;
	while (*str1_1 != '\0')
	{
		if (*str1_1 != *strf_f)
		{
			str1_1++;
		}
		else{
			pl = str1_1;
			while (*strf_f != '\0')
			{
				str1_1++;
				strf_f++;
				if (*str1_1 != *strf_f)
					break;
			}
			if (*strf_f == '\0')
				return pl;
			else
			{
				str1_1 = pl + 1;
				*pl = NULL;
				strf_f = strf;

			}
		}
	}
	return pl;
}
void *my_memmove(void *dest, const void *src, size_t count)//模拟memmove
{
	assert(dest != NULL && src != NULL);
	char* de = (char*)dest;
	char* sr = (char*)src;
	if (de < sr + count)//发生内存重叠
	{
		de = de + count - 1;
		sr = sr + count - 1;
		while (count-->0)
		{
			*de-- = *sr--;
		}

	}
	else
	{
		while (count-- > 0)
		{
			*de++ = *sr++;
		}
	}
	return dest;

}
void *my_memcpy(void *dest, const void *src, size_t count)//模拟memcpy
{
	assert(dest != NULL && src != NULL);
	char* de = (char*) dest;
	char* sr = (char*) src;
	
		while (count-- > 0)
		{
			*de++ = *sr++;
		}
	
	return dest;

}
int main()
{
	char str1[] = "liyunjie zhenshuai";
	char *str2 = "*******";
	printf("the string after change is: %s\n", my_memcpy(str1, str2, sizeof(char)* 4));
	return 0;
}
/*int main()
{
	char str[100] = "liyunjie ai xuexi ";
	char str1[] = "and bite";
	printf("the str after my_strcat is : %s\n", my_strcat(str, str1));

	return 0;
}
/*int main()
{
char str[] = "liyunjie ai xuexi hhhhh";
char str1[] = "liyunjie ai bite";
int res = my_strcmp(str, str1);
if (res > 0)
printf("str>str1\n");
else if (res < 0)
printf("str<str1\n");
else
printf("str=str1\n");
return 0;
}*/
/*int main()
{
char str[] = "liyunjie ai xuexi hhhhh";
char str1[] = "liyunjie ai bite";
printf("the str after strcpy is %s\n", my_strcpy(str,str1));
return 0;
}*/
/*
int main()
{
char *str = "liyunjie ai xuexi hhhhh";
printf("str\'s length is %d", my_strlen(str));
return 0;
}*/
