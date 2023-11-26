#pragma once
#include<iostream>
#include<string>
#include"Worker.h"
using namespace std;

class Manager :public worker
{
public:
	//構造函數
	Manager(int id, string name, int did);
	//顯示個人信息
	virtual void showInfo();
	//獲取崗位名稱
	virtual string getDeptName();
};