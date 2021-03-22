#include"game.h"
#include "observe.h"
Game::Game()
{

}
Game::~Game()
{

}
void Game::save_game(Nezha &actor)//保存游戏（存档）
{
	actor.write_file_actor(actor);
	actor.set_num_of_weapon();
	ofstream write_file("weapon.dat", ios_base::out | ios_base::binary);
	//构造一个武器副本
	Weapons _weapons(actor.get_weapons());
	int real_num = actor.get_num_of_weapon();
	write_file << real_num;
	while (!_weapons.empty())
	{
		//取出顶部元素
		Weapon weapon = _weapons.top();
		actor.write_file_weapon(weapon, write_file);
		//弹出顶部元素
		_weapons.pop();
	}
	write_file.close();
}

//运行游戏
void Game::run_game(Game game,Nezha &actor,Place place[],Wonderland practice_place[],Place *current)
{
	Place temp;
	Wonderland temp1;
	while (1)
	{
		current->describe_place();//内有清屏
		MENU menu;
		cin >> (int &)menu;
		string file_name_map = "map.dat";
		string set_color_map = "\033[93m";
		switch (menu)
		{
		case MENU::play_prompt:
			current->print_warning(actor);//显示该地点的提示
			break;
		case MENU::change_place:
			cout << "\033[93m";
			if (current->flag == 7)
			{
				ConcreteSubject *s = new ConcreteSubject();//构造发布者
				s->attach(new ConcreteObserver(s, "海绵宝宝"));
				s->attach(new ConcreteObserver(s, "派大星"));
				s->attach(new ConcreteObserver(s, "蟹老板"));

				cout << "请选择您想前往的地点" << endl;
				for (int i = 0; i < 4; i++)
				{
					if (current->spot[i] == "0")break;
					else cout << i << "[" << current->spot[i] << "] ";
				}
				int num_in;
				cin >> num_in;
				for (int i = 0; i < 10; i++)
				{
					if (place[i].get_name() == current->spot[num_in])
					{
						temp = place[i];
						current = &temp;
						break;
					}
				}
				if (current->spot[num_in] == "边春山")
				{
					if (actor.find_pen() == false)
					{
						cout << endl<<"您未找到【指点江山笔】，不能进入修炼地！" <<endl;
						cout << "-----------------------------------------------------------------------------------" << endl;
						s->set("还在【比奇堡】里玩耍！");
						s->notify();
						cout << "-----------------------------------------------------------------------------------" << endl;
						delete s;
					}
					else
					{
						cout << "-----------------------------------------------------------------------------------" << endl;
						cout << "海绵宝宝从菠萝屋赶来！ " << "派大星从石头屋赶来！ " << "蟹老板从船锚房赶来！" << endl;
						s->set("准备好了！");
						s->notify();
						cout << "-----------------------------------------------------------------------------------" << endl;
						delete s;
						temp1 = practice_place[0];
						current = &temp1;
					}
				}
			}
			else
			{
				current->change_place(place, practice_place, *current);//实现地点切换
			}
			actor.set_place(current->get_name());
			cout << "\033[0m";
			system("pause");
			break;
		case MENU::go_fighting:
			current->fight_with_demon(actor);//实现在该地点的战斗
			break;
		case MENU::print_map:
			game.print_file(file_name_map, set_color_map);
			//打印地图
			system("pause");
			break;
		case MENU::save_game:
			cout << "\033[94m";
			cout << "1.存档 2.退出游戏 3.取消" << endl;
			int choose;
			cin >> choose;
			cout << "\033[0m";
			if (choose == 1)
				save_game(actor);
			if (choose == 2) exit(0);
			system("pause");
			break;
		case MENU::my_information:
			actor.print_attribute();//显示人物属性卡
			system("pause");
			break;
		case MENU::enemy_information:
			current->look_demon();//显示妖怪资料
			system("pause");
			break;
		default:cout << "输入错误！" << endl;
			system("pause");
		}
	}
}
void Game::print_file(string file_name,string set_color)//文件读取
{
	ifstream in(file_name);
	string s;
	getline(in, s, '!');
	while (in)
	{
		cout << set_color << s << "\033[0m" << endl;
		getline(in, s);
	}
	in.close();
}