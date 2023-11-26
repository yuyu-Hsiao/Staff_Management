#include"WorkerManager.h"
WorkerManager::WorkerManager()
{
	//1.��󤣦s�b
	ifstream ifs;
	ifs.open(FILENAME, ios::in);	//Ū���
	if (!ifs.is_open())
	{
		//cout << "��󤣦s�b" << endl;
		//��l��
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileEmpty = true;	//��l�Ƥ��O�_����
		ifs.close();
		return;
	}
	//2.���s�b���S������
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//��󬰪�
		//cout << "��󬰪�" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileEmpty = true;	//��l�Ƥ��O�_����
		ifs.close();
		return;
	}

	//3.����s�b �åB�O���ƾ�
	int num = this->get_EnpNum();
	//cout << "�H�Ƭ�:" << num << endl;
	this->m_EmpNum = num;
	this->m_EmpArray = new worker * [this->m_EmpNum];	//�}�P�Ŷ�
	this->init_Emp();	//�N��󤤪��ƾڦs��Ʋդ�


}

void WorkerManager::print_menu()
{
	cout << "******************" << endl;
	cout << "�w��Ө�¾�u�޲z�t��" << endl;
	cout << "0.�h�X�޲z�{��" << endl;
	cout << "1.�K�[¾�u�H��" << endl;
	cout << "2.���¾�u�H��" << endl;
	cout << "3.�R����¾���u" << endl;
	cout << "4.�ק�¾�u�H��" << endl;
	cout << "5.�d��¾�u�H��" << endl;
	cout << "6.���ӽs���Ƨ�" << endl;
	cout << "7.�M�ũҦ�����" << endl;
	cout << "******************" << endl;
}

//�h�X�t��
void WorkerManager::Exitsystem()
{
	cout << "�w��U���A�ϥ�" << endl;
	system("pause");
	exit(0);	//�h�X�{��
}

//�K�[���u
void WorkerManager::add_Emp()
{
	cout << "�п�J�K�[¾�u�ƶq" << endl;

	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		//�K�[
		//�p��K�[�Ŷ��j�p
		int newSize = this->m_EmpNum + addNum;	//�즳�H�ƥ[�W�s�[���H�� �}�P�s����ϪŶ�
		//�}�P�s�Ŷ�
		worker** newspace=new worker* [newSize];
		//�N��ӪŶ����ƾګ�����s�Ŷ��U
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newspace[i] = this->m_EmpArray[i];
			}
		}

		//�K�[�s�ƾ�
		int ret = this->m_EmpNum;
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect = 0;
			cout << "�п�J��" << i + 1 << "��¾�u�s��" << endl;

			int temp = -1;
			while (true)
			{
				cin >> id;
				for (int i = 0; i < ret; i++)
				{
					if (newspace[i]->m_id == id)	//¾�uid�s�b
					{
						cout << "��id�w�s�b�A�Э��s��Jid" << endl;
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

			

			cout << "�п�J��" << i + 1 << "��¾�u�m�W" << endl;
			cin >> name;
			cout << "�п�ܤu�@�^��" << endl;
			cout << "1.���q���u" << endl;
			cout << "2.�g�z" << endl;
			cout << "3.����" << endl;
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
					cout << "�п�J���T�^��s��" << endl;
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
			//�N�Ы�¾�u��¾�d,�O�s��Ʋդ�
			newspace[i + this->m_EmpNum] = worker01;
		}
		//����쥻���Ŷ�
		delete[] this->m_EmpArray;
		//��s�s�Ŷ������V
		this->m_EmpArray = newspace;
		//��s�s��¾�u�H��
		this->m_EmpNum = newSize;
		//��s¾�u�����żлx
		this->m_FileEmpty = false;

		this->save();
		cout << "���\�K�[" << addNum << "�W�s¾�u" << endl;
		
	}
	else
	{
		cout << "��J���~" << endl;
	}
	system("pause");
	system("cls");
}

//�O�s���
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);	//�ο�X�覡���}���--�g���
	for (int i=0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_id << " "
			<< this->m_EmpArray[i]->m_name << " "
			<< this->m_EmpArray[i]->m_deptid << endl;
	}
	ofs.close();
}

//�έp��󤤪��H��
int WorkerManager::get_EnpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);	//���}���--Ū���

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

//��l�ƭ��u
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
		if (did == 1)	//���u
		{
			worker01 = new Employee(id, name, did);
		}
		else if (did == 2)	//�g�z
		{
			worker01 = new Manager(id, name, did);
		}
		else	//����
		{
			worker01 = new Boss(id, name, did);
		}
		this->m_EmpArray[index] = worker01;
		index++;
	}
	ifs.close();
}


//���¾�u
void WorkerManager::Show_Emp()
{
	if (this->m_FileEmpty)
	{
		cout << "��������" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			//�Q�Φh�A�եε{�Ǳ��f
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

//�R��¾�u
void WorkerManager::Del_Emp()
{
	if (this->m_FileEmpty)
	{
		cout << "��������" << endl;
	}
	else
	{
		cout << "�п�J�Q�n�R��¾�u�s��: " << endl;
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);

		if (index != -1)	//¾�u�s�b�A�çR������m��¾�u
		{
			//�ƾګe��
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;	//��s��դH���Ӽ�
			this->save();
			cout << "�R�����\" << endl;
		}
		else
		{
			cout << "�R�����ѡA������¾�u" << endl;
		}
		system("pause");
		system("cls");
	}
}

//�P�_¾�u�O�_�s�b,�s�b��^¾�u�Ҧb�Ʋժ���m
int WorkerManager::IsExist(int id)
{
	int index = -1;

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_id == id)
		{
			//���¾�u
			index = i;
			break;
		}
	}
	return index;
}

//�ק�¾�u
void WorkerManager::Mod_Emp()
{
	if (this->m_FileEmpty)
	{
		cout << "��������" << endl;
	}
	else
	{
		cout << "�п�J�ק�¾�u���s��" << endl;
		int id = 0;
		cin >> id;

		int ret = this->IsExist(id);
		if (ret != -1)
		{
			delete this->m_EmpArray[ret];

			int newid = 0;
			string newname = "";
			int dSelect = 0;

			cout << "�d��: " << id << "��¾�u�A�п�J�s¾�u��: " << endl;
			while (true)
			{
				cin >> newid;
				int temp = this->IsExist(newid);
				if (temp != -1)		//�s��J��id�M�ª�����
				{
					cout << "�s��J��id�M�ª�����" << endl;
				}
				else
				{
					break;
				}
			}
			cout << "�п�J�s���m�W" << endl;
			cin >> newname;
			cout << "�п�J�s���^��" << endl;
			cout << "1.���q���u" << endl;
			cout << "2.�g�z" << endl;
			cout << "3.����" << endl;
			while (true)
			{
				cin >> dSelect;
				if (dSelect == 3 || dSelect == 2 || dSelect == 1)
				{
					break;
				}
				else
				{
					cout << "�^��s����J���~" << endl;
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
			//��s�ƾ�
			this->m_EmpArray[ret] = worker01;

			cout << "�ק令�\!" << endl;

			this->save();
		}
		else
		{
			cout << "�ק異�ѡA������¾�u" << endl;
		}	
	}
	system("pause");
	system("cls");
}

//�d��¾�u
void WorkerManager::Find_Emp()
{
	if (this->m_FileEmpty)
	{
		cout << "��󬰪�" << endl;
	}
	else
	{
		cout << "��ܬd��覡" << endl;
		cout << "1.��¾�uid�d��" << endl;
		cout << "2.��¾�u�m�W�d��" << endl;
		int select = 0;
		cin >> select;

		if (select == 1)
		{
			int id;
			cout << "��J�d��id" << endl;
			cin >> id;

			int ret = this->IsExist(id);
			if (ret != -1)
			{
				cout << "�d�ߦ��\�A¾�u��Ʀp�U: " << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "�d�ߥ��ѡA�d�L���H " << endl;
			}
		}
		else if (select == 2)
		{
			string name;
			cout << "��J�d�ߦW�r" << endl;
			cin >> name;

			bool flag =false;

			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_name == name)
				{
					cout << "�d�ߦ��\�A�s��" <<this->m_EmpArray[i]->m_id
						<<"����Ʀp�U"<< endl;
					flag = true;
					this->m_EmpArray[i]->showInfo();
				}
			}
			if (flag == false)
			{
				cout << "�d�L���H" << endl;
			}
		}
		else
		{
			cout << "��J�ﶵ���~" << endl;
		}
	}
	system("pause");
	system("cls");
}

//�Ƨ�
void WorkerManager::Sort_Emp()
{
	if (this->m_FileEmpty)
	{
		cout << "��������" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ܱƧǤ覡" << endl;
		cout << "1.¾�uid�ɧǱƦC" << endl;
		cout << "2.¾�uid���ǱƦC" << endl;

		int select = 0;
		cin >> select;

		for (int i = 0; i < this->m_EmpNum; i++)
		{
			int minorMax = i;
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (select == 1)	//�ɧ�
				{
					if (this->m_EmpArray[minorMax]->m_id > this->m_EmpArray[j]->m_id)
					{
						minorMax = j;	//�D�X�̤pid���U��
					}
				}
				else
				{
					if (this->m_EmpArray[minorMax]->m_id < this->m_EmpArray[j]->m_id)
					{
						minorMax = j;	//�D�X�̤jid���U��
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
		cout << "�ƧǦ��\�A���G���U" << endl;
		this->save();		//�Ƨǫᵲ�G�O�s����
		this->Show_Emp();	//�i�ܵ��G
	}
}

//�M�Ť��
void WorkerManager::Clean_File()
{
	cout << "�T�w�M�Ŷ�?" << endl;
	cout << "1.�T�w" << endl;
	cout << "2.��^" << endl;

	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//�M�Ť��
		ofstream ofs(FILENAME, ios::trunc);	//�R������A���s�Ы�
		ofs.close();
		if (this->m_EmpArray != NULL)
		{
			//�R����Ϫ��C��¾�u��H
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				delete this->m_EmpArray[i];
			}

			//�R�����ϫ��w�Ʋ�
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileEmpty = true;
		}
		cout << "�M�Ŧ��\" << endl;
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