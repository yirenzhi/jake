#include "sqlite/sqlite3.h"
#include <iostream>
#include <string>
typedef std::string STRING;
void  insertData(sqlite3*db,std::string sql);	//插入数据

void getTable(sqlite3*db,std::string sql);	//查询数据

void  deleteData(sqlite3*db,std::string sql);	//删除数据
void testSqlite()
{
	sqlite3 *pdb = NULL;
	std::string path = "./save.db";

	std::string sql;
	int result;
	//创建数据库
	result = sqlite3_open(path.c_str(),&pdb);
	if (result!=SQLITE_OK)
	{
		printf("open failed,number %d\n",result);
	}

	//创建表
	sql = "create table student(ID integer primary key autoincrement, name text,sex text)";
	result = sqlite3_exec(pdb,sql.c_str(),NULL,NULL,NULL);
	if (result!=SQLITE_OK)
	{
		printf("create table failed,number %d\n",result);
	}

	//插入数据

	for (int i=1;i<=4;i++)
	{
		char sqlc[128];
		sprintf_s(sqlc,"insert into student values(%d,'student%d','male')",i,i);
		insertData(pdb,STRING(sqlc));
	}


	//查询数据
	sql = "select * from student";
	getTable(pdb,sql);

	//删除数据
	sql = "delete from student where ID=1";
	deleteData(pdb,sql);

	//查询数据
	sql = "select * from student";
	getTable(pdb,sql);


	//关闭数据库
	sqlite3_close(pdb);
}

void getTable(sqlite3*db,std::string sql)	//查询数据
{
	char **re;		//查询结果
	int r,c;		//行，列
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