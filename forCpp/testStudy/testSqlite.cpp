#include "sqlite/sqlite3.h"
#include <iostream>
#include <string>
typedef std::string STRING;
void  insertData(sqlite3*db,std::string sql);	//��������

void getTable(sqlite3*db,std::string sql);	//��ѯ����

void  deleteData(sqlite3*db,std::string sql);	//ɾ������
void testSqlite()
{
	sqlite3 *pdb = NULL;
	std::string path = "./save.db";

	std::string sql;
	int result;
	//�������ݿ�
	result = sqlite3_open(path.c_str(),&pdb);
	if (result!=SQLITE_OK)
	{
		printf("open failed,number %d\n",result);
	}

	//������
	sql = "create table student(ID integer primary key autoincrement, name text,sex text)";
	result = sqlite3_exec(pdb,sql.c_str(),NULL,NULL,NULL);
	if (result!=SQLITE_OK)
	{
		printf("create table failed,number %d\n",result);
	}

	//��������

	for (int i=1;i<=4;i++)
	{
		char sqlc[128];
		sprintf_s(sqlc,"insert into student values(%d,'student%d','male')",i,i);
		insertData(pdb,STRING(sqlc));
	}


	//��ѯ����
	sql = "select * from student";
	getTable(pdb,sql);

	//ɾ������
	sql = "delete from student where ID=1";
	deleteData(pdb,sql);

	//��ѯ����
	sql = "select * from student";
	getTable(pdb,sql);


	//�ر����ݿ�
	sqlite3_close(pdb);
}

void getTable(sqlite3*db,std::string sql)	//��ѯ����
{
	char **re;		//��ѯ���
	int r,c;		//�У���
	sqlite3_get_table(db,sql.c_str(),&re,&r,&c,NULL);
	printf("row is %d,column is %d\n",r,c);
	for (int i=1;i<=r;i++)
	{
		for (int j=0;j<c;j++)
		{
			printf("%s\n",re[i*c+j]);
		}
	}
	sqlite3_free_table(re);

}

void  deleteData(sqlite3*db,std::string sql)
{
	int result=-1;
	result = sqlite3_exec(db,sql.c_str(),NULL,NULL,NULL);
	if (result!=SQLITE_OK)
	{
		printf("delete data failed,number %d\n",result);
	}

}
void  insertData(sqlite3*db,std::string sql)
{
	int result=-1;
	result = sqlite3_exec(db,sql.c_str(),NULL,NULL,NULL);
	if (result!=SQLITE_OK)
	{
		printf("insert data failed,number %d\n",result);
	}

}