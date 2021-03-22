#pragma once
#include"actor.h"
#include"clock.h"
#include<iostream>
#include<string>

using namespace std;

class Wonderland;//前向引用声明

//地点——基类
class Place
{
private:
	string name;//地名
protected:
	int have_demon=0;//有无妖怪
public:
	string spot[4];//该地的可连接地点
	int flag;//地点编号
    Combat_actor demon;//该地妖怪
	Place();
	Place(string _name, int _flag);
    ~Place();
	string get_name();//获取地点名
	virtual void input_demon(Combat_actor &actor);//放入怪兽
	void connect_place(string spot1, string spot2, string spot3, string spot4);//地点连接
    void describe_place();//地点描述
	void change_place( Place place[],Wonderland practice_place[], Place &current_place);//转换地点内部处理
	void print_warning(Nezha &actor);//提示
	virtual void fight_with_demon(Nezha &actor); //对战
	virtual void look_demon();//查看怪兽信息
	bool demon_is_dead();//判断该地的怪兽是否死了
	void additional_game_calculate(int a[][3], int s[][3]);//附加小游戏算法计算
	int additional_game_victory(int &win_or_lose, int a[][3]);//附加小游戏胜利与否
	void additional_game_tictactoe(int &win_or_lose);//附加小游戏主要实现
};
//训练地（仙境）中，打斗过程人物生命力减少，打完生命力自动恢复，同时战斗力因得到训练而增强
//训练地（仙境）中的妖怪没有武器
//训练地——地点派生类（公有继承自Place）
class Wonderland:public Place
{
private:
public:
	Wonderland();
	~Wonderland();
	Wonderland(string _name, int _flag);
	virtual void fight_with_demon(Nezha &actor); //训练
};