#pragma once
#include<iostream>
#include<string>
#include"Worker.h"
using namespace std;

class Employee :public worker
{
public:
	//�c�y���
	Employee(int id, string name, int did);
	//��ܭӤH�H��
	virtual void showInfo();
	//����^��W��
	virtual string getDeptName();
};