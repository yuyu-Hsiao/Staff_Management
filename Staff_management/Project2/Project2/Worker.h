#pragma once
#include<iostream>
#include<string>
using namespace std;

//¾�u��H��
class worker
{
public:
	//��ܭӤH�H��
	virtual void showInfo() = 0;
	//����^��W��
	virtual string getDeptName() = 0;

	int m_id;		//¾�u�s��
	string m_name;	//¾�u�m�W
	int m_deptid;	//¾�u�����s��
};
