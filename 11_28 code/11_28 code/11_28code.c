#include<stdio.h>

#pragma pack(2)
typedef struct ASS
{
	char a;     //1�ֽ�+1�ֽڣ���2��4��ȡ2���룩 .....һ��2�ֽ�
	int b;    //4�ֽ� ����2��8��ȡ2���룩   .....һ��6�ֽ�
	double c;   //8�ֽ�       .....һ��14�ֽ�
	short d;     //2�ֽ�              .....һ��16�ֽ�
	int f;		//4�ֽ�      .......һ��20�ֽڣ���2�ı���������8�ı�������
}ASS;
int main()
{
	printf("%d", sizeof(ASS));
}
/*#pragma pack(4)
typedef struct ASS
{
	char a;     //1�ֽ�+1�ֽڣ���2�����������4���룩 .....һ��2�ֽ�
	int b;    //4�ֽ�    .....һ��6�ֽ�
	double c;      //8�ֽ�         .....һ��14�ֽ�
	char d;     //1�ֽ�+1�ֽ�         .....һ��16�ֽ�
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
	char a;     //1�ֽ�+1�ֽڣ���2�����������4���룩 .....һ��2�ֽ�
	int b;    //4�ֽ�    .....һ��6�ֽ�
	double c;      //8�ֽ�         .....һ��14�ֽ�
	char d;     //1�ֽ�+1�ֽ�         .....һ��16�ֽ�
}ASS;
int main()
{
	printf("%d", sizeof(ASS));
}*/