#include<iostream>
#include<fstream>  //�Y��󪺥]�t
#include<string>

#include"WorkerManager.h"
#include"Worker.h"
#include"employee.h"
#include"manager.h"
#include"Boss.h"



using namespace std;

int main()
{


	//��Ҥƺ޲z�̹�H
	WorkerManager wm;

	int choice = 0;	//�����Τ᪺�ﶵ
	while (true)
	{
		wm.print_menu();

		cout << "��J�z�����" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0:		//	�h�X�t��
			wm.Exitsystem();
			break;
		case 1:		//	�W�[¾�u
			wm.add_Emp();
			break;
		case 2:		//	���¾�u
			wm.Show_Emp();
			break;
		case 3:		//	�R��¾�u
			wm.Del_Emp();
			break;
		case 4:		//	�ק�¾�u
			wm.Mod_Emp();
			break;
		case 5:		//	�d��¾�u
			wm.Find_Emp();
			break;
		case 6:		//	�Ƨ�
			wm.Sort_Emp();
			break;
		case 7:		//	�M��
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