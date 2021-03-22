#include"weapon.h"

Weapon::Weapon()
{
}
Weapon::Weapon(string _name, int _power) :name(_name), power(_power)
{
}
string Weapon::get_name()//返回武器名字
{
	return name;
}
int Weapon::get_power()//返回武器战斗力
{
	return power;
}
bool Weapon::operator< (const Weapon &other)const//重载小于号运算符——武器战斗力比较
{
	return (this->power < other.power);
}
bool Weapon::operator>(const Weapon &other)const//重载大于号运算符——武器战斗力比较
{
	return (this->power > other.power);
}
ostream &operator<<(ostream &cout, Weapon &weapon)//重载输出流
{
	cout << weapon.get_name() << "(战斗力:" << weapon.get_power() << ")";
	return cout;
}