#include"Boss.h"

Boss::Boss(int id, string name, int did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptid = did;
}

void Boss::showInfo()
{
	cout << "¾�u�s��: " << this->m_id
		<< "\t¾�u�m�W: " << this->m_name
		<< "\t�^��: " << this->getDeptName()
		<< "\t¾�d: ��I�g�z����" << endl;

}
//����^��W��
string Boss::getDeptName()
{
	return string("����");
}