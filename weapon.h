#pragma once
#include <iostream>
#include <string>
#include <queue>

using namespace std;

//武器类
class Weapon
{
private:
	string name;//武器名字
	int power;//武器战斗力
public:
	Weapon();
	Weapon(string _name, int _power);
	string get_name();//返回武器名字
	int get_power();//返回武器战斗力
	bool operator<(const Weapon &other)const;//重载小于号运算符——武器战斗力比较
	bool operator>(const Weapon &other)const;//重载大于号运算符——武器战斗力比较
};
typedef priority_queue<Weapon, vector<Weapon> >Weapons;//武器（优先级队列）
ostream & operator << (ostream &cout, Weapon &weapon);//重载操作符<< 简便地输出武器对象