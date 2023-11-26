#include"WorkerManager.h"
WorkerManager::WorkerManager()
{
	//1.文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);	//讀文件
	if (!ifs.is_open())
	{
		//cout << "文件不存在" << endl;
		//初始化
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileEmpty = true;	//初始化文件是否為空
		ifs.close();
		return;
	}
	//2.文件存在但沒有紀錄
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//文件為空
		//cout << "文件為空" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileEmpty = true;	//初始化文件是否為空
		ifs.close();
		return;
	}

	//3.當文件存在 並且記錄數據
	int num = this->get_EnpNum();
	//cout << "人數為:" << num << endl;
	this->m_EmpNum = num;
	this->m_EmpArray = new worker * [this->m_EmpNum];	//開闢空間
	this->init_Emp();	//將文件中的數據存到數組中


}

void WorkerManager::print_menu()
{
	cout << "******************" << endl;
	cout << "歡迎來到職工管理系統" << endl;
	cout << "0.退出管理程序" << endl;
	cout << "1.添加職工信息" << endl;
	cout << "2.顯示職工信息" << endl;
	cout << "3.刪除離職員工" << endl;
	cout << "4.修改職工信息" << endl;
	cout << "5.查找職工信息" << endl;
	cout << "6.按照編號排序" << endl;
	cout << "7.清空所有文檔" << endl;
	cout << "******************" << endl;
}

//退出系統
void WorkerManager::Exitsystem()
{
	cout << "歡迎下次再使用" << endl;
	system("pause");
	exit(0);	//退出程序
}

//添加員工
void WorkerManager::add_Emp()
{
	cout << "請輸入添加職工數量" << endl;

	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		//添加
		//計算添加空間大小
		int newSize = this->m_EmpNum + addNum;	//原有人數加上新加的人數 開闢新的堆區空間
		//開闢新空間
		worker** newspace=new worker* [newSize];
		//將原來空間的數據拷貝到新空間下
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newspace[i] = this->m_EmpArray[i];
			}
		}

		//添加新數據
		int ret = this->m_EmpNum;
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect = 0;
			cout << "請輸入第" << i + 1 << "個職工編號" << endl;

			int temp = -1;
			while (true)
			{
				cin >> id;
				for (int i = 0; i < ret; i++)
				{
					if (newspace[i]->m_id == id)	//職工id存在
					{
						cout << "此id已存在，請重新輸入id" << endl;
						temp = 0;
						break;
					}
					else
					{
						temp = -1;
					}
				}
				if (temp == -1)
				{
					break;
				}
			}
			ret++;

			

			cout << "請輸入第" << i + 1 << "個職工姓名" << endl;
			cin >> name;
			cout << "請選擇工作崗位" << endl;
			cout << "1.普通員工" << endl;
			cout << "2.經理" << endl;
			cout << "3.老闆" << endl;
			while (true)
			{
				if (dSelect == 0) {
					cin >> dSelect;
				}
				else if (dSelect == 3 || dSelect == 2 || dSelect == 1)
				{
					break;
				}
				else
				{
					cout << "請輸入正確崗位編號" << endl;
					dSelect = 0;
				}
			}
			

			worker* worker01 = NULL;
			switch (dSelect)
			{
			case 1:
				worker01 = new Employee(id, name, 1);
				break;
			case 2:
				worker01 = new Manager(id, name, 2);
				break;
			case 3:
				worker01 = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			//將創建職工的職責,保存到數組中
			newspace[i + this->m_EmpNum] = worker01;
		}
		//釋放原本的空間
		delete[] this->m_EmpArray;
		//更新新空間的指向
		this->m_EmpArray = newspace;
		//更新新的職工人數
		this->m_EmpNum = newSize;
		//更新職工不為空標誌
		this->m_FileEmpty = false;

		this->save();
		cout << "成功添加" << addNum << "名新職工" << endl;
		
	}
	else
	{
		cout << "輸入有誤" << endl;
	}
	system("pause");
	system("cls");
}

//保存文件
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);	//用輸出方式打開文件--寫文件
	for (int i=0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_id << " "
			<< this->m_EmpArray[i]->m_name << " "
			<< this->m_EmpArray[i]->m_deptid << endl;
	}
	ofs.close();
}

//統計文件中的人數
int WorkerManager::get_EnpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);	//打開文件--讀文件

	int id;
	string name;
	int did;

	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		num++;
	}
	ifs.close();
	return num;
}

//初始化員工
void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int did;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		worker* worker01 = NULL;
		if (did == 1)	//員工
		{
			worker01 = new Employee(id, name, did);
		}
		else if (did == 2)	//經理
		{
			worker01 = new Manager(id, name, did);
		}
		else	//老闆
		{
			worker01 = new Boss(id, name, did);
		}
		this->m_EmpArray[index] = worker01;
		index++;
	}
	ifs.close();
}


//顯示職工
void WorkerManager::Show_Emp()
{
	if (this->m_FileEmpty)
	{
		cout << "紀錄為空" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			//利用多態調用程序接口
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

//刪除職工
void WorkerManager::Del_Emp()
{
	if (this->m_FileEmpty)
	{
		cout << "紀錄為空" << endl;
	}
	else
	{
		cout << "請輸入想要刪除職工編號: " << endl;
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);

		if (index != -1)	//職工存在，並刪除此位置的職工
		{
			//數據前移
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;	//更新樹組人員個數
			this->save();
			cout << "刪除成功" << endl;
		}
		else
		{
			cout << "刪除失敗，未找到該職工" << endl;
		}
		system("pause");
		system("cls");
	}
}

//判斷職工是否存在,存在返回職工所在數組的位置
int WorkerManager::IsExist(int id)
{
	int index = -1;

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_id == id)
		{
			//找到職工
			index = i;
			break;
		}
	}
	return index;
}

//修改職工
void WorkerManager::Mod_Emp()
{
	if (this->m_FileEmpty)
	{
		cout << "紀錄為空" << endl;
	}
	else
	{
		cout << "請輸入修改職工的編號" << endl;
		int id = 0;
		cin >> id;

		int ret = this->IsExist(id);
		if (ret != -1)
		{
			delete this->m_EmpArray[ret];

			int newid = 0;
			string newname = "";
			int dSelect = 0;

			cout << "查到: " << id << "號職工，請輸入新職工號: " << endl;
			while (true)
			{
				cin >> newid;
				int temp = this->IsExist(newid);
				if (temp != -1)		//新輸入的id和舊的重複
				{
					cout << "新輸入的id和舊的重複" << endl;
				}
				else
				{
					break;
				}
			}
			cout << "請輸入新的姓名" << endl;
			cin >> newname;
			cout << "請輸入新的崗位" << endl;
			cout << "1.普通員工" << endl;
			cout << "2.經理" << endl;
			cout << "3.老闆" << endl;
			while (true)
			{
				cin >> dSelect;
				if (dSelect == 3 || dSelect == 2 || dSelect == 1)
				{
					break;
				}
				else
				{
					cout << "崗位編號輸入錯誤" << endl;
				}
			}
			worker* worker01 = NULL;
			switch (dSelect)
			{
			case 1:
				worker01 = new Employee(newid, newname, 1);
				break;
			case 2:
				worker01 = new Manager(newid, newname, 2);
				break;
			case 3:
				worker01 = new Boss(newid, newname, 3);
				break;
			default:
				break;
			}
			//更新數據
			this->m_EmpArray[ret] = worker01;

			cout << "修改成功!" << endl;

			this->save();
		}
		else
		{
			cout << "修改失敗，未找到該職工" << endl;
		}	
	}
	system("pause");
	system("cls");
}

//查找職工
void WorkerManager::Find_Emp()
{
	if (this->m_FileEmpty)
	{
		cout << "文件為空" << endl;
	}
	else
	{
		cout << "選擇查找方式" << endl;
		cout << "1.由職工id查詢" << endl;
		cout << "2.由職工姓名查詢" << endl;
		int select = 0;
		cin >> select;

		if (select == 1)
		{
			int id;
			cout << "輸入查詢id" << endl;
			cin >> id;

			int ret = this->IsExist(id);
			if (ret != -1)
			{
				cout << "查詢成功，職工資料如下: " << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "查詢失敗，查無此人 " << endl;
			}
		}
		else if (select == 2)
		{
			string name;
			cout << "輸入查詢名字" << endl;
			cin >> name;

			bool flag =false;

			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_name == name)
				{
					cout << "查詢成功，編號" <<this->m_EmpArray[i]->m_id
						<<"的資料如下"<< endl;
					flag = true;
					this->m_EmpArray[i]->showInfo();
				}
			}
			if (flag == false)
			{
				cout << "查無此人" << endl;
			}
		}
		else
		{
			cout << "輸入選項有誤" << endl;
		}
	}
	system("pause");
	system("cls");
}

//排序
void WorkerManager::Sort_Emp()
{
	if (this->m_FileEmpty)
	{
		cout << "紀錄為空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "選擇排序方式" << endl;
		cout << "1.職工id升序排列" << endl;
		cout << "2.職工id降序排列" << endl;

		int select = 0;
		cin >> select;

		for (int i = 0; i < this->m_EmpNum; i++)
		{
			int minorMax = i;
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (select == 1)	//升序
				{
					if (this->m_EmpArray[minorMax]->m_id > this->m_EmpArray[j]->m_id)
					{
						minorMax = j;	//求出最小id的下標
					}
				}
				else
				{
					if (this->m_EmpArray[minorMax]->m_id < this->m_EmpArray[j]->m_id)
					{
						minorMax = j;	//求出最大id的下標
					}
				}
				
			}
			if (i != minorMax)
			{
				worker* temp = m_EmpArray[i];
				m_EmpArray[i] = m_EmpArray[minorMax];
				m_EmpArray[minorMax] = temp;
			}
		}
		cout << "排序成功，結果為下" << endl;
		this->save();		//排序後結果保存到文件中
		this->Show_Emp();	//展示結果
	}
}

//清空文件
void WorkerManager::Clean_File()
{
	cout << "確定清空嗎?" << endl;
	cout << "1.確定" << endl;
	cout << "2.返回" << endl;

	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//清空文件
		ofstream ofs(FILENAME, ios::trunc);	//刪除文件後再重新創建
		ofs.close();
		if (this->m_EmpArray != NULL)
		{
			//刪除堆區的每個職工對象
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				delete this->m_EmpArray[i];
			}

			//刪除推區指針數組
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileEmpty = true;
		}
		cout << "清空成功" << endl;
	}
	system("pause");
	system("cls");
}

WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				delete this->m_EmpArray[i];
				m_EmpArray[i] = NULL;
			}
		}
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}