#include<stdio.h>
/*�����Σ�˼·�������һ��*/
void guess()
{
	int A, B, C, D, E;
	for (A = 1; A <= 5; ++A)
	{
		for (B = 1; B <= 5; ++B)
		{
			for (C = 1; C <= 5; ++C)
			{
				for (D = 1; D <= 5; ++D)
				{
					for (E = 1; E <= 5; ++E)
					{
						if (((B == 2) + (A == 3) == 1) && ((B == 2) + (E == 4) == 1) && ((C == 1) + (D == 2) == 1) && ((C == 5) + (D == 3) == 1) && ((E == 4) + (A == 1) == 1)&&(A*B*C*D*E==120))
						{
							printf("A ��%d;\nB ��%d;\nC ��%d;\nD ��%d;\nE ��%d;\n", A, B, C, D, E);
							break;
						}
					}
				}
			}
		}
	}

}
int main()
{
	guess();
	return 0;
}
/*
�����֣����ĸ������˷ֱ���мٶ�
��ĳ�������ֵ������������Ϊ������Ϊ�ٵ����
��Ϊ����
*/
/*
int main()
{
	char trust = 'A';
	for (; trust <= 'D'; ++trust)
	{
		if ((trust != 'A') + (trust == 'C') + (trust == 'D') + (trust != 'D') == 3)
		{		
			printf("the trust murder is %c\n", trust);
			break;
		}
	}
	return 0;
}
/*#define N 20
void Pascal(int pascal[][N], int n)//�������ʵ�ֺ���
{
	int i, j;
	for (i = 0; i < n; ++i)//��βΪ1�ȸ���ֵ
	{
		pascal[i][0] = 1;
		pascal[i][i] = 1;
	}
	for (i = 2; i < n; ++i)
	{
		for (j = 1; j < i; ++j)
		{
			pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
		}
	}
	for (i = 0; i < n; ++i)//��ӡ���
	{
		for (j = 0; j <= i; ++j)
		{
			printf("%d ", pascal[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	int pascal[N][N];
	int n;
	printf("please input the line your want to print:>");
	scanf("%d", &n);
	Pascal(pascal, n);
	return 0;
}*/