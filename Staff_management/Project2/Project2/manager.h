#pragma once
#include<iostream>
#include<string>
#include"Worker.h"
using namespace std;

class Manager :public worker
{
public:
	//�c�y���
	Manager(int id, string name, int did);
	//��ܭӤH�H��
	virtual void showInfo();
	//����^��W��
	virtual string getDeptName();
};