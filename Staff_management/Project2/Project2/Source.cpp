#include<iostream>
#include<fstream>  //頭文件的包含
#include<string>

#include"WorkerManager.h"
#include"Worker.h"
#include"employee.h"
#include"manager.h"
#include"Boss.h"



using namespace std;

int main()
{


	//實例化管理者對象
	WorkerManager wm;

	int choice = 0;	//紀錄用戶的選項
	while (true)
	{
		wm.print_menu();

		cout << "輸入您的選擇" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0:		//	退出系統
			wm.Exitsystem();
			break;
		case 1:		//	增加職工
			wm.add_Emp();
			break;
		case 2:		//	顯示職工
			wm.Show_Emp();
			break;
		case 3:		//	刪除職工
			wm.Del_Emp();
			break;
		case 4:		//	修改職工
			wm.Mod_Emp();
			break;
		case 5:		//	查找職工
			wm.Find_Emp();
			break;
		case 6:		//	排序
			wm.Sort_Emp();
			break;
		case 7:		//	清空
			wm.Clean_File();
			break;
		default:
			system("cls");
			break;
		}


	}


	system("pause");
	return 0;
}