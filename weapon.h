#pragma once
#include <iostream>
#include <string>
#include <queue>

using namespace std;

//������
class Weapon
{
private:
	string name;//��������
	int power;//����ս����
public:
	Weapon();
	Weapon(string _name, int _power);
	string get_name();//������������
	int get_power();//��������ս����
	bool operator<(const Weapon &other)const;//����С�ں��������������ս�����Ƚ�
	bool operator>(const Weapon &other)const;//���ش��ں��������������ս�����Ƚ�
};
typedef priority_queue<Weapon, vector<Weapon> >Weapons;//���������ȼ����У�
ostream & operator << (ostream &cout, Weapon &weapon);//���ز�����<< ���������������