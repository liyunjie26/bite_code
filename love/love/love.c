#include<stdio.h>
#include<string.h>
#include<Windows.h>
int main()
{
	char a[] = "I LOVE YOU!";
	int leng = strlen(a);
	for (int i = 0; i < leng; ++i)
	{
		printf("%c", a[i]);
		Sleep(500);
	}
	system("pause");
}