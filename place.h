#pragma once
#include"actor.h"
#include"clock.h"
#include<iostream>
#include<string>

using namespace std;

class Wonderland;//ǰ����������

//�ص㡪������
class Place
{
private:
	string name;//����
protected:
	int have_demon=0;//��������
public:
	string spot[4];//�õصĿ����ӵص�
	int flag;//�ص���
    Combat_actor demon;//�õ�����
	Place();
	Place(string _name, int _flag);
    ~Place();
	string get_name();//��ȡ�ص���
	virtual void input_demon(Combat_actor &actor);//�������
	void connect_place(string spot1, string spot2, string spot3, string spot4);//�ص�����
    void describe_place();//�ص�����
	void change_place( Place place[],Wonderland practice_place[], Place &current_place);//ת���ص��ڲ�����
	void print_warning(Nezha &actor);//��ʾ
	virtual void fight_with_demon(Nezha &actor); //��ս
	virtual void look_demon();//�鿴������Ϣ
	bool demon_is_dead();//�жϸõصĹ����Ƿ�����
	void additional_game_calculate(int a[][3], int s[][3]);//����С��Ϸ�㷨����
	int additional_game_victory(int &win_or_lose, int a[][3]);//����С��Ϸʤ�����
	void additional_game_tictactoe(int &win_or_lose);//����С��Ϸ��Ҫʵ��
};
//ѵ���أ��ɾ����У��򶷹����������������٣������������Զ��ָ���ͬʱս������õ�ѵ������ǿ
//ѵ���أ��ɾ����е�����û������
//ѵ���ء����ص������ࣨ���м̳���Place��
class Wonderland:public Place
{
private:
public:
	Wonderland();
	~Wonderland();
	Wonderland(string _name, int _flag);
	virtual void fight_with_demon(Nezha &actor); //ѵ��
};