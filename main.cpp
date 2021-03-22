#include "game.h"

int main()//主函数！
{
    Game game;
	string file_name_window = "Nezha_window.dat";
    string set_color_window = "\033[91m";
	game.print_file(file_name_window, set_color_window);

	string file_name_intro = "Introduce.dat";
	string set_color_intro = "\033[96m";
	game.print_file(file_name_intro, set_color_intro);

	cout << endl << "————————————————请选择————————————————" << endl;
	cout << "\033[41m" << "                             1.继续游戏                               " << "\033[0m" << endl;
	cout << "\033[101m" << "                             2.开始游戏                               " << "\033[0m" << endl;

	//构造游戏所需地点
	Place place[10] = { Place("李府",1),Place("鹿台",2),Place("不周山",3),Place("东海",4),Place("碧游宫",5),Place("天宫",6),Place("山河社稷图",7), Place("招摇山", 8),
	Place("雁门山", 9),Place("陈塘关", 10) };
	Wonderland practice_place[3] = { Wonderland("边春山", 11),Wonderland("赤水", 12),Wonderland("长留山", 13) };

	//构造每个地点的目标连接点
	place[0].connect_place("陈塘关", "0", "0", "0");//A
	place[1].connect_place("不周山", "0", "0", "0");//B
	place[2].connect_place("鹿台", "陈塘关", "0", "0");//C
	place[3].connect_place("天宫", "招摇山", "陈塘关", "0");//D
	place[4].connect_place("山河社稷图", "雁门山", "陈塘关", "0");//E
	place[5].connect_place("东海", "0", "0", "0");//F
	place[6].connect_place("碧游宫", "边春山", "0", "0");//G
	place[7].connect_place("东海", "0", "0", "0");//H
	place[8].connect_place("碧游宫", "0", "0", "0");//I
	place[9].connect_place("李府", "不周山", "东海", "碧游宫");//J
	practice_place[0].connect_place("山河社稷图", "赤水", "0", "0");//a
	practice_place[1].connect_place("边春山", "长留山", "0", "0");//b
	practice_place[2].connect_place("赤水", "0", "0", "0");//c

	//构造游戏所需人物
	Combat_actor combat_actor[9] = { Combat_actor("结界兽", 20, 10, "李府"),Combat_actor("鹿蜀", 25, 120, "鹿台"),Combat_actor("尚付", 30, 150, "不周山"),
	Combat_actor("海夜叉", 35, 180, "东海"),Combat_actor("申公豹", 40, 200, "碧游宫"),Combat_actor("天雷", 50, 1500, "天宫"),Combat_actor("海绵宝宝",15,50,"边春山"),
	Combat_actor("派大星",20,100,"赤水"),Combat_actor("蟹老板",25,110,"长留山") };

	//构造游戏中的武器
	Weapon weapon[7] = { Weapon("木剑", 2),Weapon("乾坤圈", 5),Weapon("混天绫", 10),Weapon("风火轮", 15),
	Weapon("火尖枪", 20),Weapon("阴阳剑", 30),Weapon("霹雳", 40) };

	//把武器赋给相关人物
	for (int i = 0; i < 6; i++)
	{
		combat_actor[i] << weapon[i + 1];
	}

	//把人物放入所属地点
	for (int i = 0; i < 6; i++)
	{
		place[i].input_demon(combat_actor[i]);
		place[i].demon.set_initial_life(place[i].demon.get_life());
		place[i].demon.set_initial_power(place[i].demon.get_power());
	}
	for (int i = 0; i < 3; i++)
	{
		practice_place[i].input_demon(combat_actor[i + 6]);
		practice_place[i].demon.set_initial_life(practice_place[i].demon.get_life());
		practice_place[i].demon.set_initial_power(practice_place[i].demon.get_power());
	}

	//输入1继续游戏，输入2开始游戏
	int choose;
	cin >> choose;

	switch (choose)
	{
	case 1:
	{	Place *current;//地点指针
	cout << "欢迎回来！欢迎继续你的旅途！" << endl;
	cout << "读取数据中..." << endl;
	system("pause");
	//读档代码：
	Nezha temp_actor;//构造哪吒人物副本
	temp_actor.read_file_actor(temp_actor);
	//构造哪吒（玩家）
	Nezha leading_actor(temp_actor.get_name(), temp_actor.get_power(), temp_actor.get_life(), temp_actor.get_place(), temp_actor.get_relationship());
	//读物品
	for (int i = 0; i < temp_actor.get_num_of_good(); i++)
	{
		leading_actor.set_good(temp_actor.get_good(i));
	}
	ifstream read_file("weapon.dat", ios_base::out | ios_base::binary);
	int num;//武器数目
	read_file >> num;//读取持有武器数目
	Weapon weapon0;//构造武器副本
	for (int i = 0; i < num; i++)
	{
		read_file.read((char *)(&weapon0), sizeof(weapon0));
		Weapon weapon1(weapon0.get_name(), weapon0.get_power());
		leading_actor << weapon1;
	}
	read_file.close();

	//构造地点副本
	Place temp_place = place[0];//修改 不能直接current=&place[0],会使place[0]发生改变
	current = &temp_place;
	Place temp0;
	Wonderland temp_place2;
	Place temp;
	Wonderland temp1;
	for (int i = 0; i < 10; i++)
	{
		if (place[i].get_name() == leading_actor.get_place())
		{
			//修改 不能直接current=&place[0],会使place[0]发生改变
			temp0 = place[i];
			current = &temp0;
			break;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if (practice_place[i].get_name() == leading_actor.get_place())
		{
			temp_place2 = practice_place[i];//修改 不能直接current=&place[0],会使place[0]发生改变
			current = &temp_place2;
			break;
		}
	}
	game.run_game(game, leading_actor, place, practice_place, current);
	}
	break;
	case 2:
	{//游戏开始
		system("cls");//清屏
		string file_name_window = "background.dat";
		string set_color_window = "\033[95m";
		game.print_file(file_name_window, set_color_window);
		system("pause");
		Nezha leading_actor("哪吒", 5, 200, "李府", 0);//构造哪吒（玩家）
		Place temp;
		Wonderland temp1;
		Place *current;//地点指针
		leading_actor << weapon[0];//给哪吒木剑
		Place temp_place = place[0];//修改 不能直接current=&place[0],会使place[0]发生改变
		current = &temp_place;
		game.run_game(game, leading_actor, place, practice_place, current);
	}break;
	}
	return 0;
}