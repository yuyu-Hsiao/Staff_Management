#include"employee.h"

Employee::Employee(int id, string name, int did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptid = did;
}
//��ܭӤH�H��
void Employee::showInfo()
{
	cout << "¾�u�s��: " << this->m_id
		<< "\t¾�u�m�W: " << this->m_name
		<< "\t�^��: " << this->getDeptName()
		<< "\t¾�d: �����g�z��I������" << endl;

}
//����^��W��
string Employee::getDeptName()
{
	return string("���u");
}
