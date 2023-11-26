#include"manager.h"

Manager::Manager(int id, string name, int did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptid = did;
}

void Manager::showInfo()
{
	cout << "職工編號: " << this->m_id
		<< "\t職工姓名: " << this->m_name
		<< "\t崗位: " << this->getDeptName()
		<< "\t職責: 完成老闆交付的任務" << endl;

}
//獲取崗位名稱
string Manager::getDeptName()
{
	return string("經理");
}