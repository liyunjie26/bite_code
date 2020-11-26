#include<stdio.h>
typedef struct{
	int a;
	char b;
	short c;
	short d;
}AA_t;
int main()
{
	AA_t u1;
	printf("the struct AA_t's size is %d\n", sizeof(u1));
	return 0;
}