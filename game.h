#pragma once
#include "place.h"
#include "actor.h"
#include "weapon.h"
#include <iostream>
using namespace std;

//��Ϸ��
class Game
{
private:

public:	
	Game();
	~Game();
	enum class MENU//��Ϸѡ������˵�����ö����
	{
		play_prompt = 1, change_place, go_fighting, print_map, save_game, my_information, enemy_information,
	};
	void save_game(Nezha &actor);//������Ϸ���浵��
	void run_game(Game game,Nezha &actor, Place place[], Wonderland practice_place[], Place *current);//������Ϸ
	void print_file(string filename,string set_color);//�ļ���ȡ
};