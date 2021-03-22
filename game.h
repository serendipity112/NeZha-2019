#pragma once
#include "place.h"
#include "actor.h"
#include "weapon.h"
#include <iostream>
using namespace std;

//游戏类
class Game
{
private:

public:	
	Game();
	~Game();
	enum class MENU//游戏选择基本菜单——枚举类
	{
		play_prompt = 1, change_place, go_fighting, print_map, save_game, my_information, enemy_information,
	};
	void save_game(Nezha &actor);//保存游戏（存档）
	void run_game(Game game,Nezha &actor, Place place[], Wonderland practice_place[], Place *current);//运行游戏
	void print_file(string filename,string set_color);//文件读取
};