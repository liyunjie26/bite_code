#include<stdio.h>
#include<stdbool.h>
int Add(int op1, int op2)
{
	return op1 + op2;
}
int Sub(int op1, int op2)
{
	return op1 - op2;
}
int Mul(int op1, int op2)
{
	return op1*op2;
}
int Div(int op1, int op2)
{
	return op1 / op2;
}
int Mod(int op1, int op2)
{
	return op1 % op2;
}
void main()
{
	int select = 1;
	int op1, op2, result;
	/////////////////////////////
	//界面设计
	system("title 简易计算器");
	system("mode con cols=29 lines=15");
	system("color F0");
	////////////////////////////
	while (select)
	{
		
		printf("***************************\n");
		printf("*     简 易 计 算 器      *\n");
		printf("*[1]Add         [2]Sub    *\n");
		printf("*[3]Mul         [4]Div    *\n");
		printf("*[5]Mod         [6]Quit   *\n");
		printf("***************************\n");
		printf("请选择:>");
		scanf("%d", &select);
		if (select == 0)
			break;
		printf("请输入op1和op2：>");
		scanf("%d %d", &op1, &op2);

		switch (select)
		{
		case 1:
			result = Add(op1, op2);
			break;
		case 2:
			result = Sub(op1, op2);
			break;
		case 3:
			result = Mul(op1, op2);
			break;
		case 4:
			result = Div(op1, op2);
			break;
		case 5:
			result = Mod(op1, op2);
			break;
		default:
			printf("输入的cmd有误，请重新输入......\n");
			break;
		}
		printf("result =%d\n", result);
		system("pause");
		system("cls");
	}
	printf("系统退出。\n");

}