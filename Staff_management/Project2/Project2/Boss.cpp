#include"Boss.h"

Boss::Boss(int id, string name, int did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptid = did;
}

void Boss::showInfo()
{
	cout << "職工編號: " << this->m_id
		<< "\t職工姓名: " << this->m_name
		<< "\t崗位: " << this->getDeptName()
		<< "\t職責: 交付經理任務" << endl;

}
//獲取崗位名稱
string Boss::getDeptName()
{
	return string("老闆");
}