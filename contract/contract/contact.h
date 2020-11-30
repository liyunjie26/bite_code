#ifndef _CONTACT_H_
#define _CONTACT_H_
#include"sysutil.h"
#define MAX_NAME_SIZE 10
#define MAX_SEX_SIZE 3
#define MAX_TEL_SIZE 12
#define MAX_ADDR_SIZE 256
#define MAX_CONTACT_SIZE 200
typedef enum ENUM_TYPE
{
	Quit = 0,
	ADD,
	DEL,
	FIND,
	SHOW,
	MOD,
	SORT,
	CLEAR,
	DESTROY

}ENUM_TYPE;
//定义个人信息
typedef struct PersonInfo_t
{
	char name[MAX_NAME_SIZE];
	char sex[MAX_SEX_SIZE];
	char tel[MAX_TEL_SIZE];
	char addr[MAX_ADDR_SIZE];
	int age;
}PersonInfo_t;
//定义通讯录结构
typedef struct Contact_t
{
	PersonInfo_t base[MAX_CONTACT_SIZE];//通讯录的存储空间
	size_t size;//表示通讯录中的信息条数
	size_t capacity;//容量
}Contact_t;
////////////////////////////////////////////////////
//函数的申明
void ContactInit(Contact_t *pct);
#endif/* _CONTACT_H_*/