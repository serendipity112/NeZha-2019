#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "weapon.h"
using namespace std;

//人物——基类（抽象类）
class Actor
{
private:
	string name;//人物姓名
	string place;//人物所在地
	int power;//人物战斗力
	int life;//人物生命力
public:
	Actor();
	~Actor();
	Actor(string _name,int _power,int _life,string _place);
    void set_place(string place);//设定所在地
	string get_place(void);//获取所在地
	string get_name(void);//获取姓名
	int get_power(void);//获取战斗力	
	void add_power(int _power);//增加战斗力
	void sub_power(int _power);//减少战斗力
	int get_life(void);//获取生命力	
	void set_life(int life);//设定生命力
	Actor &operator+=(int life);//重载+= 增加生命力值
	Actor &operator-=(int life);//重载-= 减少生命力值
	virtual void print_attribute()=0;//显示人物属性
	virtual void get_weapons_information(void)=0;//显示全部武器的信息
	virtual Weapon get_best_weapon()=0;//获取最厉害的武器
	virtual Actor &operator<<(Weapon weapon)=0;//重载<< 添加一个武器
	virtual Actor &operator>>(Weapon &weapon)=0;//重载>> 取出威力最大武器
	virtual void on_lose(Actor &winner, Weapons &weapons)=0;//战斗失败
	virtual void on_win(Actor &loser, Weapons &weapons)=0;//战斗胜利
	virtual void on_killed(Actor &winner)=0;//被杀死
	virtual Weapons &get_weapons(void)=0;//获取所有武器
	virtual void cure_life()=0;//治愈（生命力值恢复到满格）
	virtual void success_practice(int add_num)=0;//修炼成功
	virtual void fail_practice(int sub_num)=0;//修炼失败
};

//战斗NPC——人物派生类（公有继承自Actor）
class Combat_actor :public Actor
{
private:
	int num_of_weapon;//武器数目	
	int initial_power;//初始战斗力
	int initial_life;//初始生命力
public:
	Weapons weapons;//人物佩戴兵器列表——优先级队列
	Combat_actor();
	~Combat_actor();
	Combat_actor(string _name, int _power, int _life, string _place);
	int get_num_of_weapon();//获取武器数目
	void set_num_of_weapon();//设定武器数目
	void get_weapons_information(void);//显示全部武器的信息
	Weapon get_best_weapon();//获取最厉害的武器
	Actor &operator<<(Weapon weapon);//重载<< 添加一个武器
	Actor &operator>>(Weapon &weapon);//重载>> 取出威力最大武器
	void on_lose(Actor &winner, Weapons &weapons);//战斗失败
	void on_win(Actor &loser, Weapons &weapons);//战斗成功
	void on_killed(Actor &winner);//被杀死
	Weapons &get_weapons(void);//获得所有武器
	virtual void print_attribute();//显示属性
	void cure_life();//治愈（生命值恢复到满格）
	void success_practice(int add_num);//修炼成功
	void fail_practice(int sub_num);//修炼失败
	int get_initial_power();//获得初始战斗力
	void set_initial_power(int power);//设定初始战斗力
	int get_initial_life();//获得初始生命力
	void set_initial_life(int life);//设定初始生命力
};
ostream &operator<<(ostream &cout, Combat_actor &actor);//重载操作符<< 简便地输出人物对象

//玩家可操控角色——人物派生类（公有继承自Combat_actor）
class Nezha :public Combat_actor
{
private:int relationship;//哪吒友谊值
		string good[10] = {"0","0","0","0","0","0","0","0","0","0"};//哪吒物品（如【指点江山笔】）
		int num_of_good = 0;//物品数量
public: ~Nezha();
		Nezha();
		Nezha(string _name, int _power, int _life, string _place, int _relationship);
		int get_relationship();//获取友谊值
		void add_relationship(int num);//增加友谊值
		void print_attribute();//显示哪吒属性
		int get_num_of_good();//获得物品数量
		void set_good(string _good);//存入物品
		string get_good(int num);//获得物品
		void print_good();//输出物品
		bool find_pen();//找到笔(【指点江山笔】)
		void write_file_actor(Nezha &actor);//人物存档
		void read_file_actor(Nezha &actor);//人物读档
		void write_file_weapon(Weapon &weapon, ofstream &file);//武器存档
		void read_file_weapon(Combat_actor &actor);//武器读档
};