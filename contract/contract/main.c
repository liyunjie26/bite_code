#include"contact.h"
int main(int argc, char* argv[])
{
	Contact_t cont;
	ContactInit(&cont);
	int select = 1;
	while (select)
	{
		printf("******************************************\n");
		printf("* [1] AssContact      [2]DelContact      *\n");
		printf("* [3] FindContact     [4]ShowContact     *\n");
		printf("* [5] ModContact      [6]SortContact     *\n");
		printf("* [7] AssContact      [8]DestroyContact  *\n");
		printf("* [0] Exit System                        *\n");
		printf("******************************************\n");
		printf("ÇëÑ¡Ôñ£º>");
		scanf("%d", &select);
		if (select == 0)
			break;
		switch (select)
		{
		case ADD:
			break;
		case DEL:
			break;
		case FIND:
			break;
		case SHOW:
			break;
		case MOD:
			break;
		case SORT:
			break;
		case CLEAR:
			break;
		case DESTROY:
			break;
		}
	}
	return 0;
}