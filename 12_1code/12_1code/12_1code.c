#include<stdio.h>
//�亯������Ҫ�����ǽ�һ���ַ���ת����һ��������������ô�����ַ���Ϊ��ʱ����Ϊ���쳣�ַ�ʱ
//������ֵΪ0������ֵ���󳬳���ʾ��Χʱ�����-1
int my_atoi(char *string)
{
	char* s = string;
	if (NULL == s)
		return 0;
	long num = 0;
	int flag = 0;
	while (*s != NULL)//�����ҵ���һ���Ϸ��ĵ�ַ������λΪ�������
	{
		if (*s != '0' || *s != ' ')
			break;
		s++;
	}
	if (*s == '-')//�ж��Ƿ������
	{
		flag = 1;
		++s;

	}
	while ((*s >= 48) && (*s <= 57))//��Ҫ�жϵ���ǰ��ָ��ֵΪ������Χʱ������ֵ������Ϊ�ջ�����С���������ֵ����ѭ��
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

