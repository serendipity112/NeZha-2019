#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "weapon.h"
using namespace std;

//��������ࣨ�����ࣩ
class Actor
{
private:
	string name;//��������
	string place;//�������ڵ�
	int power;//����ս����
	int life;//����������
public:
	Actor();
	~Actor();
	Actor(string _name,int _power,int _life,string _place);
    void set_place(string place);//�趨���ڵ�
	string get_place(void);//��ȡ���ڵ�
	string get_name(void);//��ȡ����
	int get_power(void);//��ȡս����	
	void add_power(int _power);//����ս����
	void sub_power(int _power);//����ս����
	int get_life(void);//��ȡ������	
	void set_life(int life);//�趨������
	Actor &operator+=(int life);//����+= ����������ֵ
	Actor &operator-=(int life);//����-= ����������ֵ
	virtual void print_attribute()=0;//��ʾ��������
	virtual void get_weapons_information(void)=0;//��ʾȫ����������Ϣ
	virtual Weapon get_best_weapon()=0;//��ȡ������������
	virtual Actor &operator<<(Weapon weapon)=0;//����<< ���һ������
	virtual Actor &operator>>(Weapon &weapon)=0;//����>> ȡ�������������
	virtual void on_lose(Actor &winner, Weapons &weapons)=0;//ս��ʧ��
	virtual void on_win(Actor &loser, Weapons &weapons)=0;//ս��ʤ��
	virtual void on_killed(Actor &winner)=0;//��ɱ��
	virtual Weapons &get_weapons(void)=0;//��ȡ��������
	virtual void cure_life()=0;//������������ֵ�ָ�������
	virtual void success_practice(int add_num)=0;//�����ɹ�
	virtual void fail_practice(int sub_num)=0;//����ʧ��
};

//ս��NPC�������������ࣨ���м̳���Actor��
class Combat_actor :public Actor
{
private:
	int num_of_weapon;//������Ŀ	
	int initial_power;//��ʼս����
	int initial_life;//��ʼ������
public:
	Weapons weapons;//������������б������ȼ�����
	Combat_actor();
	~Combat_actor();
	Combat_actor(string _name, int _power, int _life, string _place);
	int get_num_of_weapon();//��ȡ������Ŀ
	void set_num_of_weapon();//�趨������Ŀ
	void get_weapons_information(void);//��ʾȫ����������Ϣ
	Weapon get_best_weapon();//��ȡ������������
	Actor &operator<<(Weapon weapon);//����<< ���һ������
	Actor &operator>>(Weapon &weapon);//����>> ȡ�������������
	void on_lose(Actor &winner, Weapons &weapons);//ս��ʧ��
	void on_win(Actor &loser, Weapons &weapons);//ս���ɹ�
	void on_killed(Actor &winner);//��ɱ��
	Weapons &get_weapons(void);//�����������
	virtual void print_attribute();//��ʾ����
	void cure_life();//����������ֵ�ָ�������
	void success_practice(int add_num);//�����ɹ�
	void fail_practice(int sub_num);//����ʧ��
	int get_initial_power();//��ó�ʼս����
	void set_initial_power(int power);//�趨��ʼս����
	int get_initial_life();//��ó�ʼ������
	void set_initial_life(int life);//�趨��ʼ������
};
ostream &operator<<(ostream &cout, Combat_actor &actor);//���ز�����<< ��������������

//��ҿɲٿؽ�ɫ�������������ࣨ���м̳���Combat_actor��
class Nezha :public Combat_actor
{
private:int relationship;//��߸����ֵ
		string good[10] = {"0","0","0","0","0","0","0","0","0","0"};//��߸��Ʒ���硾ָ�㽭ɽ�ʡ���
		int num_of_good = 0;//��Ʒ����
public: ~Nezha();
		Nezha();
		Nezha(string _name, int _power, int _life, string _place, int _relationship);
		int get_relationship();//��ȡ����ֵ
		void add_relationship(int num);//��������ֵ
		void print_attribute();//��ʾ��߸����
		int get_num_of_good();//�����Ʒ����
		void set_good(string _good);//������Ʒ
		string get_good(int num);//�����Ʒ
		void print_good();//�����Ʒ
		bool find_pen();//�ҵ���(��ָ�㽭ɽ�ʡ�)
		void write_file_actor(Nezha &actor);//����浵
		void read_file_actor(Nezha &actor);//�������
		void write_file_weapon(Weapon &weapon, ofstream &file);//�����浵
		void read_file_weapon(Combat_actor &actor);//��������
};