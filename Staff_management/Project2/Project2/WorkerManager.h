#pragma once
#include<iostream>	//包含輸入輸出流頭文件
#include"Worker.h"
#include"employee.h"
#include"manager.h"
#include"Boss.h"

#include<fstream>
#define FILENAME "empFile.txt"
using namespace std;

class WorkerManager
{
public:
	WorkerManager();

	void print_menu();//顯示菜單
	void Exitsystem();//退出系統

	
	int m_EmpNum;		//紀錄職工人數
	worker** m_EmpArray;	//職工數組指針

	void add_Emp();		//添加職工

	void save();		//保存文件

	bool m_FileEmpty;	//文件是否為空

	int get_EnpNum();	//統計文件中的人數

	void init_Emp();	//初始化員工

	void Show_Emp();	//顯示職工

	void Del_Emp();		//刪除職工

	int IsExist(int id);//判斷職工是否存在

	void Mod_Emp();		//修改職工

	void Find_Emp();	//查找職工

	void Sort_Emp();	//排序

	void Clean_File();	//清空文件

	~WorkerManager();
};