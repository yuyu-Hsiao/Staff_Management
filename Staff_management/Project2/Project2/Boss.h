#pragma once
#include<iostream>
#include<string>
#include"Worker.h"
using namespace std;

class Boss :public worker
{
public:
	//�c�y���
	Boss(int id, string name, int did);
	//��ܭӤH�H��
	virtual void showInfo();
	//����^��W��
	virtual string getDeptName();
};
