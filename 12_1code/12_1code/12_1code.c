#include<stdio.h>
//其函数的主要功能是将一个字符串转换成一个整整型数，那么当该字符串为空时或者为带异常字符时
//传出的值为0；当数值过大超出表示范围时则输出-1
int my_atoi(char *string)
{
	char* s = string;
	if (NULL == s)
		return 0;
	long num = 0;
	int flag = 0;
	while (*s != NULL)//首先找到第一个合法的地址，即首位为非零的数
	{
		if (*s != '0' || *s != ' ')
			break;
		s++;
	}
	if (*s == '-')//判断是否带负号
	{
		flag = 1;
		++s;

	}
	while ((*s >= 48) && (*s <= 57))//主要判断当当前所指的值为正常范围时进行求值，当其为空或者是小数点等其他值均出循环
	{
		num = num * 10 + (long)((*s) - 48);
		++s;
	}
	if ((*s == NULL) || (*s == '.'))
	{
		if (flag == 0)
		{
			if (num <= 32767)
				return (int)num;
			else
				return -1;
		}
		if (flag == 1)
		{
			if (num <= 32768)
				return (0 - (int)num);
			else
				return -1;
		}
	}
	else
		return 0;
}
int main()
{
	char *str = "-1234.0";
	int num = my_atoi(str);
	printf("%d\n", num);
}

