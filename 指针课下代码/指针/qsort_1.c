/*#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*int compare(const void *a,const void *b)
{
	return (*(int*)a) - (*(int*)b);
}
void change(void *a, void *b, int size)
{
	int i;
	for (i = 0; i < size; ++i)
	{
		char tm = *((char*)a + i);
		*((char*)a + i) = *((char*)b + i);
		*((char*)b + i) = tm;

	}
}
void my_qsort(void *base, size_t num, size_t width, int(*compare)(const void *elem1, const void *elem2))
{
	for (int i = 0; i < num - 1; ++i)
	{
		for (int j = 0; j < num - i - 1; ++j)
		{
			if (compare((char *)base + j*width, (char*)base + (j + 1)*width)>0)
				change((char *)base + j*width, (char*)base + (j + 1)*width, width);
		}
	}
}
void Print(int ar[], int n)
{
	for (int i = 0; i<n; ++i)
	{
		printf("%d ", ar[i]);
	}
	printf("\n");
}
int main()
{
	int a[9] = { 9, 56, 88, 55, 47, 12, 36, 54, 11 };
	int n = sizeof(a) / sizeof(a[0]);
	Print(a, n);
	my_qsort(a, n, sizeof(int), compare);
	Print(a, n);
	return 0;
}*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*typedef struct Student
{
	int grade;
	char name[10];
	int id;

}Student;
int compare(void *p1, void *p2)
{
	Student *a = (Student*)p1;
	Student *b = (Student*)p2;
	return((a->grade) - (b->grade));//	return((a->id) - (b->id));//	
	//return (strcmp(a->name, b->name));分别通过分数、ID、姓名进行排序
}
void main()
{
	Student a[] = { { 90, "小红", 1110 },
	{ 100, "小李", 1118 },
	{ 20, "小王", 1119 } };
	qsort(a, 3, sizeof(Student), compare);
}
*/
/*int compare(void *p1, void *p2)//测试整型数组
{
	int *a = (int*)p1;
	int *b = (int*)p2;
	return (*a - *b);
}
void main()
{
	int a[10] = { 2, 54, 1, 2, 36, 21, 58, 62, 36, 21 };
	qsort(a, 10, sizeof(int), compare);
}
*/
/*int compare(void *p1, void *p2)//测试字符型数组
{
	char *a = (char*)p1;
	char *b = (char*)p2;
	return (*a - *b);
}
void main()

{
	char a[10] = {'a','j','i','d','r','g','l','m','z','\0' };
	qsort(a, 9, sizeof(char), compare);
}
*/
int compare(const void *p1, const void *p2)//测试整型数组
{
	const char **a = (char**)p1;
	const char **b = (char**)p2;
	return (strcmp(*a,*b));
}
void main()
{
	char *a[] = { "asc", "asf", "aff", "avx", "qwf", "fbh", "yfx", "wqd", "caz", "fac" };
	int n = sizeof(a) / sizeof(a[0]);
	qsort(a, n, sizeof(char*), compare);
}
