#include"weapon.h"

Weapon::Weapon()
{
}
Weapon::Weapon(string _name, int _power) :name(_name), power(_power)
{
}
string Weapon::get_name()//������������
{
	return name;
}
int Weapon::get_power()//��������ս����
{
	return power;
}
bool Weapon::operator< (const Weapon &other)const//����С�ں��������������ս�����Ƚ�
{
	return (this->power < other.power);
}
bool Weapon::operator>(const Weapon &other)const//���ش��ں��������������ս�����Ƚ�
{
	return (this->power > other.power);
}
ostream &operator<<(ostream &cout, Weapon &weapon)//���������
{
	cout << weapon.get_name() << "(ս����:" << weapon.get_power() << ")";
	return cout;
}