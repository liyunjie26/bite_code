#include<stdio.h>

#pragma pack(2)
typedef struct ASS
{
	char a;     //1字节+1字节（在2与4中取2对齐） .....一共2字节
	int b;    //4字节 （在2与8中取2对齐）   .....一共6字节
	double c;   //8字节       .....一共14字节
	short d;     //2字节              .....一共16字节
	int f;		//4字节      .......一共20字节（是2的倍数不用往8的倍数靠）
}ASS;
int main()
{
	printf("%d", sizeof(ASS));
}
/*#pragma pack(4)
typedef struct ASS
{
	char a;     //1字节+1字节（与2对齐而不是与4对齐） .....一共2字节
	int b;    //4字节    .....一共6字节
	double c;      //8字节         .....一共14字节
	char d;     //1字节+1字节         .....一共16字节
}ASS;
int main()
{
	printf("%d", sizeof(ASS));
}
/*typedef struct Test
{
	char a;
	short b;
	int c;
	long d;
}Test;*/
/*#pragma pack(2)
typedef struct ASS
{
	char a;     //1字节+1字节（与2对齐而不是与4对齐） .....一共2字节
	int b;    //4字节    .....一共6字节
	double c;      //8字节         .....一共14字节
	char d;     //1字节+1字节         .....一共16字节
}ASS;
int main()
{
	printf("%d", sizeof(ASS));
}*/