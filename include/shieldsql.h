#ifndef _SHIELDSQL
#define _SHIELDSQL

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#define TRUE	0
#define FALSE 	1

typedef unsigned long long ullong;

typedef struct UserInfo
{
	char id[20];
	char pw[20];
	char name[20];
	char perm[20];
	int groupid;
	int fd;
} UserInfo;

int connectDB(MYSQL** db, char* serverip, char* user, char* pass, char* databaseName);
int sendQuery(MYSQL** db, char* query);
ullong getQueryDataNum(MYSQL** db, char* query, MYSQL_RES** res);
int getQueryDataRow(MYSQL_RES** res, UserInfo* data);
void closeDB(MYSQL** db, MYSQL_RES** res);

void display(MYSQL_RES** res, UserInfo* data);

#endif
