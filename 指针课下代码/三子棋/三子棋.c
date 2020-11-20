#include<stdio.h>
#include<Windows.h>
#include<stdbool.h>
#include <time.h>
//三字棋规则：3*3的棋盘，1,0.当存在三个连续且相同时，则表示有一方胜利，如果没有位置下了则表示平局

void init(char array[][3], int x, int y)
{
	for (int i = 0; i < x; ++i)
	{
		for (int j = 0; j < y; ++j)
		{
			array[i][j] = ' ';
		}
	}
	return;
}void face(char array[][3],int x,int y)//3*3的棋盘
{
	system("cls");
	printf("   | 1 | 2 | 3 |\n");
	for (int i = 0; i < x; ++i)
	{
		printf("-------------\n");
		printf(" %d | %c | %c | %c |\n", i+1,array[i][0], array[i][1], array[i][2]);
	}
}
bool is_lagel(int x,int y)//判断位置的合法性
{
	if ((x>0)&&(x<4)&&(y>0)&&(y<4))
		return true;
	return false;
}
void introduction(char arr[][3], int x, int y)
{
	void gamer_input(char arr[][3]);
	if (arr[x - 1][y - 1] == ' ')
		arr[x - 1][y - 1] = 'X';
	else
	{
		printf("your place is full,please again\n");
		gamer_input(arr);
	}

}
void com_input(char arr[][3])//电脑输入
{
	int x = rand() % 3;
	int y = rand() % 3;
	if (arr[x][y] == ' ')
		arr[x][y] = 'Y';
	else
		com_input(arr);
}
void gamer_input(char arr[][3])//玩家位置的输入
{
	int x, y;
	printf("please input your place:>");
	scanf("%d%d", &x, &y);
	if (is_lagel(x, y))
	{
		introduction(arr, x, y);
	}
	else
	{
		printf("the place is not in legal,please input again\n");
		face(arr, 3, 3);
		gamer_input(arr);

	}
}
void end_game(char choice)//输出函数
{
	switch (choice)
	{
	case 'X':
		printf("your win\n");
		break;
	case 'Y' :
		printf("the computer is win\n");
		break;
	case 'p' :

		printf("no win\n");
	}
	return 0;
}
int is_continue(char arr[][3], int x, int y, int count)//判断是否存在赢得情况，判断是否继续
{
	for (int i = 0; i < 3; ++i)
	{
		if ((arr[i][0] == arr[i][1]) && (arr[i][1] == arr[i][2]) && (arr[i][0]!=' '))
		{
			end_game(arr[i][0]);
			return 0;
		}
	}
	for (int i = 0; i < 3; ++i)
	{
		if ((arr[0][i] == arr[1][i]) && (arr[1][i] == arr[2][i]) && (arr[0][i] != ' '))
		{
			end_game(arr[0][i]);
			return 0;
		}
	}
	if ((arr[1][1] == arr[2][2]) && (arr[2][2] == arr[0][0]) && (arr[1][1] != ' '))
	{
		end_game(arr[1][1]);
		return 0;
	}
	if ((arr[1][1] == arr[0][2]) && (arr[0][2] == arr[2][0]) && (arr[1][1] != ' '))
	{
		end_game(arr[1][1]);
		return 0;
	}
	if (count == 0)
	{
		face(arr, 3, 3);
		end_game('p');
		return 0;
	}
return 1;	
}
int main()
{
	srand((unsigned)time(NULL));
	char array[3][3]; 
	int flag=1,count = 9;
	init(array, 3, 3);
	face(array, 3, 3);
	while (flag)
	{
		gamer_input(array);
		count--;
		flag = is_continue(array, 3, 3, count);
		if (flag == 0)
		{
			break;
		}
		face(array, 3, 3);
		Sleep(1000);
		com_input(array);
		face(array, 3, 3);
		count--;
		flag = is_continue(array, 3, 3, count);
		if (flag == 0)
			break;
		}
	return 0;
}