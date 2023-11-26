#pragma once
#include<iostream>	//�]�t��J��X�y�Y���
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

	void print_menu();//��ܵ��
	void Exitsystem();//�h�X�t��

	
	int m_EmpNum;		//����¾�u�H��
	worker** m_EmpArray;	//¾�u�Ʋի��w

	void add_Emp();		//�K�[¾�u

	void save();		//�O�s���

	bool m_FileEmpty;	//���O�_����

	int get_EnpNum();	//�έp��󤤪��H��

	void init_Emp();	//��l�ƭ��u

	void Show_Emp();	//���¾�u

	void Del_Emp();		//�R��¾�u

	int IsExist(int id);//�P�_¾�u�O�_�s�b

	void Mod_Emp();		//�ק�¾�u

	void Find_Emp();	//�d��¾�u

	void Sort_Emp();	//�Ƨ�

	void Clean_File();	//�M�Ť��

	~WorkerManager();
};