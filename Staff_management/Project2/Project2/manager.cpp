#include"manager.h"

Manager::Manager(int id, string name, int did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptid = did;
}

void Manager::showInfo()
{
	cout << "¾�u�s��: " << this->m_id
		<< "\t¾�u�m�W: " << this->m_name
		<< "\t�^��: " << this->getDeptName()
		<< "\t¾�d: ���������I������" << endl;

}
//����^��W��
string Manager::getDeptName()
{
	return string("�g�z");
}