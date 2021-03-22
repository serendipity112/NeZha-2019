#include"place.h"
//函数名动词加名词 动宾结构

Place::Place()
{

}
Place:: ~Place()
{
}
Place::Place(string _name,int _flag) :name(_name),flag(_flag)
{
}
string Place::get_name()//获取地点名
{
	return name;
}
void Place::input_demon(Combat_actor &actor)//放入怪兽
{
	demon = actor;
	have_demon= 1;
}
void Place::connect_place(string spot1, string spot2, string spot3, string spot4)//地点连接
{
	spot[0] = spot1;
	spot[1] = spot2;
	spot[2] = spot3;
	spot[3] = spot4;
}
void Place::describe_place()//地点描述
{	
	system("cls");
	cout << "\033[91m"<<"[" << name<< "]" << "\033[0m" << endl;
	cout  << "这里是" << "\033[91m"<<"[" << name <<"]"  <<"\033[0m" << endl << "可以通往的地方: ";
	for (int i = 0; i < 4; i++)
	{
		if (spot[i] == "0")break;
		else cout << "\033[91m" << "[" << spot[i] << "] " << "\033[0m";
	}
	if(flag==7||flag==8||flag==9||flag==10) cout << "这里没有敌人"  << endl;
	else { cout << "这里有敌人："<< "\033[91m" << "【" << demon.get_name() << "】" << "\033[0m" << endl; }
	cout << "1.提示 2.赶路 3.战斗 4.地图 5.系统 6.我的信息 7.敌人信息" << endl;
	cout << "\033[91m" << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << "\033[0m" << endl;
}
void Place::change_place(Place place[],Wonderland practice_place[],Place &current_place)//转换地点内部处理
{
	cout << "\033[93m";
	if ((flag == 1 && current_place.demon_is_dead() == false ))
		cout << "你还未打败结界兽，暂时不能出去！" << endl;
	if ((flag == 1&& current_place.demon_is_dead() == true)||flag!=1)
	{
	if (spot[0] != "0")
	{
		cout << "请选择您想前往的地点" << endl;
		for (int i = 0; i < 4; i++)
		{
			if (spot[i] == "0")break;
			else cout << i << "[" << spot[i] << "] ";
		}
		int num_in;
		cin >> num_in;
		for (int i = 0; i < 10; i++)
		{
			if (place[i].get_name() == current_place.spot[num_in])
			{
				current_place = place[i];
				break;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			if (practice_place[i].get_name() == current_place.spot[num_in])
			{
				current_place = practice_place[i];
				break;
			}
		}
	}
	else
	{
		cout << "没有可以前往的地点！" << endl;
	}
	}
	cout << "\033[0m";
}
void Place::print_warning(Nezha &actor)//提示
{
	cout << "\033[96m";
	switch (flag)
	{
	case 1:cout << "这里是李府，陈塘关总兵李靖的府邸。"<<endl<<"父母下令让结界兽在此看守你。现在，打败结界兽，去外面的世界看看吧！"<<endl;  break;
	case 2:cout << "山中有鹿，常年嘶鸣，故名曰鹿台山。这里有小妖鹿蜀，不如尝试打败它们吧！"<<endl;  break;
	case 3:cout << "西北海之外，大荒之隅，有山而不合，名曰不周负子，有大妖，名曰尚付。"<<endl;   break;
	case 4:cout << "这里是东海龙王管辖的海域。" << endl;
		   cout << "是否要与敖丙玩游戏？【和敖丙的友谊值达到100，才能迎战天雷哦】    1是 2否";
		int play_with_npc;
		cin >> play_with_npc;
		if (play_with_npc == 1)
		{
			int win_or_lose;
			additional_game_tictactoe(win_or_lose);
			//游戏
			if (win_or_lose == 3)
			{
				actor.add_relationship(35);

				cout << "您与敖丙的友谊值增加35！" << endl;
			}
		    //增relationship
		}break;
	case 5:cout << "仙域真境，申公豹在此修炼。若你足够强大，不如尝试打败他。"<<endl;  break;
	case 6:cout << "元始天尊启动了天劫咒语，不久天劫将会降临，摧毁魔丸。你的最后一个任务，就是迎战天雷！"<<endl;  break;
	case 7:cout << "太乙真人：我是你师父太乙真人，而这里是山河社稷图。" << endl<<"山河图中可以修炼或打怪，修炼可使你生命力再次满格,而打怪可以使你战斗力提升。"<<endl<<"你可以在边春山、赤水或者长留山里打怪。" << endl;
		   cout << endl<<"是否要在山河图中修炼？1是 2否";
		int practice;
		cin >> practice;
		if (practice == 1)
		{   
			cout << "修炼倒计时ing...请等待" << endl;
			//倒计时
			cout << "\033[93m";	
			Clock clock;
			clock.set_time(0, 0, 10);
			clock.run_time();
			actor.cure_life();
			cout << "您已完成修炼，生命值已恢复到200，您现在元气满满@_@！" << endl;
		}break;
	case 8:cout << "这是临于海上的一座荒山。"<<endl; break;
	case 9:cout << "这里群峰挺拔，地势险要，“雁门山者，雁飞出其间”。" << endl;
		   cout << "在此处发现【指点江山笔】，是否拾起？ 1.是" << endl;
		int pick;
		cin >> pick;
		if (pick == 1)
		{
			actor.set_good("指点江山笔");
			cout << "恭喜你获得指点江山笔，现在你可以打开山河社稷图啦！" << endl;
		}
		break;
	case 10:cout << "这里是交通要塞陈塘关。" << endl;
		    cout << "有一修炼圣地名曰山河社稷图，不过要去那需要先找到一枚“钥匙”：指点江山笔，它藏在地图上的某处，去找找看吧！"<<endl; break;
	case 11:cout << "边春之山，多桃李。有兽，海绵宝宝。可在此处打怪，提高战斗力。"<<endl; break;
	case 12:cout << "忽吾行此流沙兮，遵赤水而容与。有妖，派大星。可在此处打怪，提高战斗力。"<<endl; break;
	case 13:cout << "风卷珠帘携远岫，浪挥白练化长虹。有兽，蟹老板。可在此处打怪，提高战斗力。"<<endl; break;
	}
	cout << "\033[0m";
	system("pause");	
}
void Place::fight_with_demon(Nezha &actor)//对战
{
	cout << "\033[92m";
	if (actor.get_relationship() < 100 && flag == 6)
	{
		cout << "您和敖丙的友谊值尚未达到100，暂时不能迎战天雷！" << endl;
		cout << "\033[0m";
		system("pause");
	}
	if (actor.get_relationship() > 99 && flag == 6)
	{
		cout << "您是否要向【太乙真人】求助？(求助)1.是 2.否" << endl;
		int help;
		cin >> help;
		if (help == 1)
		{
			cout << "【太乙真人】向您使用【急急如律令】，您已进化，功力增加500!" << endl;
			actor.add_power(500);
			cout << "\033[0m";
			system("pause");
		}
		if (help == 2)
		{
			cout << "Good luck! 你给世界留下一个纤弱的背影，孤军奋战ing..." << endl;
			cout << "\033[0m";
			system("pause");
		}
	}
	if (have_demon == 1 && flag != 6 || have_demon == 1 && flag == 6 && actor.get_relationship() > 99)
	{
		cout << "\033[92m";
		int fight;
		cout << "\033[0m";
		cout << "您请出击 (输入1.出击 2.逃跑)" << endl;
		cin >> fight;
		if (fight == 2)
		{
			cout << "\033[0m";
			system("pause");
		}	
		Weapon best_weapon;
		if (fight == 1)
		{
			cout << "\033[92m";
			//取出威力最大的武器
			cout << "-----------------------------------------------------------" << endl;
			cout << "正在取出威力最大的武器ing..." << endl;
			best_weapon = actor.get_best_weapon();
			cout << "已取出：" << best_weapon << endl;
			cout << "-----------------------------------------------------------" << endl;
		}
		if (demon.get_life() == 0)
		{
			cout << "怪兽刚刚已被您打败，下次来此地才会有可以攻打的怪兽哦~" << endl;
			cout << "\033[0m";
			system("pause");
		}
		else {
			while (fight == 1)
			{
				cout << "\033[92m";
				//current->demon与actor_one交战
				cout << "您出击ing..." << endl;
				cout << "您使用了" << best_weapon.get_name() << endl;
				cout << "对方受到" << best_weapon.get_power() + actor.get_power() << "点伤害" << endl;
				//对方减少
				if (demon.get_life() - best_weapon.get_power() - actor.get_power() > 0)
					demon -= best_weapon.get_power() + actor.get_power();
				else
				{
					demon.set_life(0);
					cout << "\033[91m";
					cout << "                         ++   ++" << endl;
					cout << "                        ++++ ++++" << endl;
					cout << "                       +++++++++++" << endl;
					cout << "                        +++++++++" << endl;
					cout << "                          +++++" << endl;
					cout << "                            +" << endl;
					cout << "\033[92m";
					cout << "---------------------congratulations!---------------------" << endl;
					cout << '\a';
					cout << "恭喜玩家！妖怪已被你打败(＾－＾)V" << endl;
					cout << "【!!!收获敌人武器】";
					demon.get_weapons_information();

					//战胜动作-哪吒赢时，缴获敌人武器
					actor.on_win(demon, demon.get_weapons());
					if (flag == 6)
					{
						cout << endl;
						cout << "\033[94m";
						cout << "[][][][][][][][][][][][][][][][][][][]" << endl;
						cout << "[]        ~congratulations~         []" << endl << "[]         我命由我不由天!          []" << endl << "[]       恭喜你！闯关成功了！       []" << endl;
						cout << "[][][][][][][][][][][][][][][][][][][]" << endl;
						cout << "\033[0m";
						system("pause");
						exit(0);
					}
					cout << "\033[0m";
					system("pause");
					break;
				}
				cout << "对方出击ing..." << endl;
				cout << "对方使用了" << demon.get_best_weapon().get_name() << endl;
				cout << "您受到了" << demon.get_best_weapon().get_power() + demon.get_power() << "点伤害" << endl;
				//玩家减少
				if (actor.get_life() - demon.get_best_weapon().get_power() - demon.get_power() > 0)
					actor -= demon.get_best_weapon().get_power() + demon.get_power();
				else {
					  cout << endl;
					  cout << "\033[94m";
					  cout << "[][][][][][][][][][][][][][][][][][][][]" << endl;
					  cout << "[]您的生命已结束~                     []" << endl;
					  cout << "[]您的仙体被海绵宝宝带回了【比奇堡】！[]" << endl;
					  cout << "[]真不幸，游戏结束了！                []" << endl;
					  cout << "[][][][][][][][][][][][][][][][][][][][]" << endl<<endl;
					  cout << "\033[0m";
					  system("pause"); 
					  exit(0);
				     }
				cout << "\033[0m";
				cout << "您请出击 (输入1.出击 2.逃跑)" << endl;
				cin >> fight;
				if (fight == 2)system("pause");
			}
		}
	}
	if(have_demon != 1)
	{
		cout << "想啥呢？？？这里没有怪兽！" << endl;
		cout << "\033[0m";
		system("pause");
	}
	cout << "\033[0m";

}
void Place::look_demon()//查看怪兽信息
{
	cout << "\033[96m";
	if (have_demon == 1)
	{
		cout << "当前所在地中妖怪资料：" << endl;
		demon.print_attribute();
	}
	else
	{
		cout << "该地无妖怪哦~"<<endl;
	}
	cout << "\033[0m";
}
bool Place::demon_is_dead()//判断该地怪兽是否死了
{
	if (demon.get_life() == 0)return true;
	else return false;
}

Wonderland::Wonderland()
{

}
Wonderland::~Wonderland()
{

}
Wonderland::Wonderland(string _name, int _flag):Place(_name,_flag)
{

}
void Wonderland::fight_with_demon(Nezha &actor) //训练
{
	if (have_demon != 1)
	{
		cout << "\033[92m";
		cout << "想啥呢？？？这里没有怪兽！" << endl;
		cout << "\033[0m";
		system("pause");
	}
	else {
		int fight;
		cout << "您请出击 (输入1.出击 2.逃跑)" << endl;
		cin >> fight;
		//取出威力最大的武器
		cout << "\033[92m";
		cout << "-------------------------------------------" << endl;
		cout << "正在取出威力最大的武器ing..." << endl;
		Weapon best_weapon;
		best_weapon = actor.get_best_weapon();
		cout << "已取出：" << best_weapon << endl;
		cout << "-------------------------------------------" << endl;

		demon.set_life(demon.get_initial_life());

		while (fight == 1)
		{
			cout << "\033[92m";
			//current->practice_demon与actor交战
			cout << "您出击ing..." << endl;
			cout << "您使用了" << best_weapon.get_name() << endl;
			cout << "对方受到" << best_weapon.get_power() + actor.get_power() << "点伤害" << endl;
			//对方减少
			if (demon.get_life() - best_weapon.get_power() - actor.get_power() > 0)
				demon -= best_weapon.get_power() + actor.get_power();
			else
			{
				demon.set_life(0);
				cout << "---------------------congratulations!---------------------" << endl;
				cout << '\a';
				cout << "恭喜玩家！妖怪已被你打败，成功完成修炼！" << endl;
				//修炼成功，战斗力+10
				actor.success_practice(10);
				cout << "\033[0m";
				system("pause");
				break;
			}
			cout << "对方出击ing..." << endl;
			cout << "对方使用了小蜗的黏液" << endl;
			cout << "您受到了" << demon.get_power() << "点伤害" << endl;
			//玩家减少
			if (actor.get_life() - demon.get_power() > 0)
				actor -= demon.get_power();
			else {
				cout << "太遗憾了！您在此处的修炼失败！" << endl;
				cout << "\033[0m";
				system("pause");
				break;
			}
			cout << "\033[0m";
			cout << "您请出击 (输入1.出击 2.逃跑)" << endl;
			cin >> fight;
		}
	}
}

//下面的三个函数是大一第一学期的井字棋代码呢0.0
void Place::additional_game_calculate(int array[][3], int array_[][3])//附加小游戏算法计算
{
	int sum = 0;
	sum = array[0][1] + array[0][2];
	if (sum == 0)
		array_[0][0] = 4;
	else if (sum == 3)
		array_[0][0] = 8;
	else if (sum == 1)
		array_[0][0] = 10;
	else if (sum == 6)
		array_[0][0] = 25;
	else if (sum == 2)
		array_[0][0] = 50;
	sum = array[1][0] + array[2][0];
	if (sum == 0)
		array_[0][0] += 4;
	else if (sum == 3)
		array_[0][0] += 8;
	else if (sum == 1)
		array_[0][0] += 10;
	else if (sum == 6)
		array_[0][0] += 25;
	else if (sum == 2)
		array_[0][0] += 50;
	sum = array[1][1] + array[2][2];
	if (sum == 0)
		array_[0][0] += 4;
	else if (sum == 3)
		array_[0][0] += 8;
	else if (sum == 1)
		array_[0][0] += 10;
	else if (sum == 6)
		array_[0][0] += 25;
	else if (sum == 2)
		array_[0][0] += 50;

	sum = array[0][0] + array[0][2];
	if (sum == 0)
		array_[0][1] = 4;
	else if (sum == 3)
		array_[0][1] = 8;
	else if (sum == 1)
		array_[0][1] = 10;
	else if (sum == 6)
		array_[0][1] = 25;
	else if (sum == 2)
		array_[0][1] = 50;
	sum = array[1][1] + array[2][1];
	if (sum == 0)
		array_[0][1] += 4;
	else if (sum == 3)
		array_[0][1] += 8;
	else if (sum == 1)
		array_[0][1] += 10;
	else if (sum == 6)
		array_[0][1] += 25;
	else if (sum == 2)
		array_[0][1] += 50;

	sum = array[0][0] + array[0][1];
	if (sum == 0)
		array_[0][1] = 4;
	else if (sum == 3)
		array_[0][2] = 8;
	else if (sum == 1)
		array_[0][2] = 10;
	else if (sum == 6)
		array_[0][2] = 25;
	else if (sum == 2)
		array_[0][2] = 50;
	sum = array[1][1] + array[2][0];
	if (sum == 0)
		array_[0][1] += 4;
	else if (sum == 3)
		array_[0][2] += 8;
	else if (sum == 1)
		array_[0][2] += 10;
	else if (sum == 6)
		array_[0][2] += 25;
	else if (sum == 2)
		array_[0][2] += 50;
	sum = array[1][2] + array[2][2];
	if (sum == 0)
		array_[0][1] += 4;
	else if (sum == 3)
		array_[0][2] += 8;
	else if (sum == 1)
		array_[0][2] += 10;
	else if (sum == 6)
		array_[0][2] += 25;
	else if (sum == 2)
		array_[0][2] += 50;

	sum = array[0][0] + array[2][0];
	if (sum == 0)
		array_[1][0] = 4;
	else if (sum == 3)
		array_[1][0] = 8;
	else if (sum == 1)
		array_[1][0] = 10;
	else if (sum == 6)
		array_[1][0] = 25;
	else if (sum == 2)
		array_[1][0] = 50;
	sum = array[1][2] + array[1][1];
	if (sum == 0)
		array_[1][0] += 4;
	else if (sum == 3)
		array_[1][0] += 8;
	else if (sum == 1)
		array_[1][0] += 10;
	else if (sum == 6)
		array_[1][0] += 25;
	else if (sum == 2)
		array_[1][0] += 50;

	sum = array[0][0] + array[2][2];
	if (sum == 0)
		array_[1][1] = 4;
	else if (sum == 3)
		array_[1][1] = 8;
	else if (sum == 1)
		array_[1][1] = 10;
	else if (sum == 6)
		array_[1][1] = 25;
	else if (sum == 2)
		array_[1][1] = 50;
	sum = array[0][1] + array[2][1];
	if (sum == 0)
		array_[1][1] += 4;
	else if (sum == 3)
		array_[1][1] += 8;
	else if (sum == 1)
		array_[1][1] += 10;
	else if (sum == 6)
		array_[1][1] += 25;
	else if (sum == 2)
		array_[1][1] += 50;
	sum = array[0][2] + array[2][0];
	if (sum == 0)
		array_[1][1] += 4;
	else if (sum == 3)
		array_[1][1] += 8;
	else if (sum == 1)
		array_[1][1] += 10;
	else if (sum == 6)
		array_[1][1] += 25;
	else if (sum == 2)
		array_[1][1] += 50;
	sum = array[1][0] + array[1][2];
	if (sum == 0)
		array_[1][1] += 4;
	else if (sum == 3)
		array_[1][1] += 8;
	else if (sum == 1)
		array_[1][1] += 10;
	else if (sum == 6)
		array_[1][1] += 25;
	else if (sum == 2)
		array_[1][1] += 50;

	sum = array[0][2] + array[2][2];
	if (sum == 0)
		array_[1][2] = 4;
	else if (sum == 3)
		array_[1][2] = 8;
	else if (sum == 1)
		array_[1][2] = 10;
	else if (sum == 6)
		array_[1][2] = 25;
	else if (sum == 2)
		array_[1][2] = 50;
	sum = array[1][0] + array[1][1];
	if (sum == 0)
		array_[1][2] += 4;
	else if (sum == 3)
		array_[1][2] += 8;
	else if (sum == 1)
		array_[1][2] += 10;
	else if (sum == 6)
		array_[1][2] += 25;
	else if (sum == 2)
		array_[1][2] += 50;

	sum = array[0][0] + array[1][0];
	if (sum == 0)
		array_[2][0] = 4;
	else if (sum == 3)
		array_[2][0] = 8;
	else if (sum == 1)
		array_[2][0] = 10;
	else if (sum == 6)
		array_[2][0] = 25;
	else if (sum == 2)
		array_[2][0] = 50;
	sum = array[0][2] + array[1][1];
	if (sum == 0)
		array_[2][0] += 4;
	else if (sum == 3)
		array_[2][0] += 8;
	else if (sum == 1)
		array_[2][0] += 10;
	else if (sum == 6)
		array_[2][0] += 25;
	else if (sum == 2)
		array_[2][0] += 50;
	sum = array[2][1] + array[2][2];
	if (sum == 0)
		array_[2][0] += 4;
	else if (sum == 3)
		array_[2][0] += 8;
	else if (sum == 1)
		array_[2][0] += 10;
	else if (sum == 6)
		array_[2][0] += 25;
	else if (sum == 2)
		array_[2][0] += 50;

	sum = array[0][1] + array[1][1];
	if (sum == 0)
		array_[2][1] = 4;
	else if (sum == 3)
		array_[2][1] = 8;
	else if (sum == 1)
		array_[2][1] = 10;
	else if (sum == 6)
		array_[2][1] = 25;
	else if (sum == 2)
		array_[2][1] = 50;
	sum = array[2][0] + array[2][2];
	if (sum == 0)
		array_[2][1] += 4;
	else if (sum == 3)
		array_[2][1] += 8;
	else if (sum == 1)
		array_[2][1] += 10;
	else if (sum == 6)
		array_[2][1] += 25;
	else if (sum == 2)
		array_[2][1] += 50;

	sum = array[0][2] + array[1][2];
	if (sum == 0)
		array_[2][2] = 4;
	else if (sum == 3)
		array_[2][2] = 8;
	else if (sum == 1)
		array_[2][2] = 10;
	else if (sum == 6)
		array_[2][2] = 25;
	else if (sum == 2)
		array_[2][2] = 50;
	sum = array[0][0] + array[1][1];
	if (sum == 0)
		array_[2][2] += 4;
	else if (sum == 3)
		array_[2][2] += 8;
	else if (sum == 1)
		array_[2][2] += 10;
	else if (sum == 6)
		array_[2][2] += 25;
	else if (sum == 2)
		array_[2][2] += 50;
	sum = array[2][0] + array[2][1];
	if (sum == 0)
		array_[2][2] += 4;
	else if (sum == 3)
		array_[2][2] += 8;
	else if (sum == 1)
		array_[2][2] += 10;
	else if (sum == 6)
		array_[2][2] += 25;
	else if (sum == 2)
		array_[2][2] += 50;
}
int Place::additional_game_victory(int &win_or_lose, int array[][3])//附加小游戏胜利与否
{
	int m = 0, n = 0, p = 0, q = 0;//g = 0, h = 0, , z = 0
	int i, j;
	for (i = 0; i < 3; i++)
	{
		m = 0;
		n = 0;
		for (j = 0; j < 3; j++)
		{
			if (array[i][j] == 1)
				m++;
			else if (array[i][j] == 3)
				n++;
		}
		if (m == 3)
		{
			printf("敖丙赢了！\n");
			win_or_lose = 1;
			return 1;
		}
		else if (n == 3)
		{
			printf("你赢了！\n");
			win_or_lose = 0;
			return 0;
		}
	}
	for (i = 0; i < 3; i++)
	{
		p = 0;
		q = 0;
		for (j = 0; j < 3; j++)
		{
			if (array[j][i] == 1)
				p++;
			else if (array[j][i] == 3)
				q++;
		}
		if (p == 3)
		{
			printf("敖丙赢了！\n");
			win_or_lose = 1;
			return 1;
		}
		else if (q == 3)
		{
			printf("你赢了！\n");
			win_or_lose = 0;
			return 0;
		}
	}
	m = 0;
	n = 0;
	for (i = 0; i < 3; i++)
	{
		if (array[i][i] == 1)
			m++;
		else if (array[i][i] == 3)
			n++;
	}
	if (m == 3)
	{
		printf("敖丙赢了！\n");
		win_or_lose = 1;
		return 1;
	}
	else if (n == 3)
	{
		printf("你赢了！\n");
		win_or_lose = 0;
		return 0;
	}
	if (array[0][2] == 1 && array[1][1] == 1 && array[2][0] == 1)
	{
		printf("敖丙赢了！\n");
		win_or_lose = 1;
		return 1;
	}
	else if (array[0][2] == 3 && array[1][1] == 3 && array[2][0] == 3)
	{
		printf("你赢了！\n");
		win_or_lose = 0;
		return 0;
	}
	return 2;
}
void Place::additional_game_tictactoe(int &win_or_lose)//附加小游戏主要实现
{
	int array[3][3] = { 0 };
	int array_[3][3];
	int  x, y,  x1, y11, i, j,k, max1, num;
int is_end;
	char tu[4] = { ' ','#',' ','o' };
	printf("\n**********************************************************************\n");
	printf("                           !欢迎体验井字游戏！\n");
	printf("**********************************************************************\n");
	printf("【说明】：左上角为(0,0)，右下角为(2,2)！\n\n");
	printf("--------------------无棋子为 敖丙棋子为#您的棋子为o--------------------\n");
	for (i = 0; i < 3; i++)
	{
		printf("-------\n");
		for (j = 0; j < 3; j++)
		{
			num = array[i][j];
			printf("|%c", tu[num]);
			if (j == 2)
				printf("|\n");
		}
	}
	printf("-------\n");
	for (k = 0; k < 4; k++)
	{
		additional_game_calculate(array, array_);
		max1 = 0;
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
			{
				if (array_[i][j] >= max1 && array[i][j] == 0)
				{
					max1 = array_[i][j];
					x = i;
					y = j;
				}
			}
		printf("您的对手敖丙正在下棋\n");
		array[x][y] = 1;
		for (i = 0; i < 3; i++)
		{
			printf("-------\n");
			for (j = 0; j < 3; j++)
			{
				num = array[i][j];
				printf("|%c", tu[num]);
				if (j == 2)
					printf("|\n");
			}
		}
		printf("-------\n");
		is_end = additional_game_victory(win_or_lose, array);
		if (is_end == 0 || is_end == 1)
			return;
		printf("请您输入棋子坐标(x1 y1)(0=<x1<=2,0=<y1<=2)【注意:输入的数字只能为0 1 2哦~】\n");
		scanf("%d%d", &x1, &y11);
		if (array[x1][y11] != 1 && array[x1][y11] != 3)
		{
			array[x1][y11] = 3;
		}
		else
		{
			printf("该位置有棋子了\n");
			return;
		}
		for (i = 0; i < 3; i++)
		{
			printf("-------\n");
			for (j = 0; j < 3; j++)
			{
				num = array[i][j];
				printf("|%c", tu[num]);
				if (j == 2)
					printf("|\n");
			}
		}
		printf("-------\n");
		is_end = additional_game_victory(win_or_lose, array);
		if (is_end == 0 || is_end == 1)
			return;
	}
	additional_game_calculate(array, array_);
	max1 = 0;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		{
			if (array_[i][j] >= max1 && array[i][j] == 0)
			{
				max1 = array_[i][j];
				x = i;
				y = j;
			}
		}
	printf("您的对手敖丙正在下棋\n");
	array[x][y] = 1;
	for (i = 0; i < 3; i++)
	{
		printf("-------\n");
		for (j = 0; j < 3; j++)
		{
			num = array[i][j];
			printf("|%c", tu[num]);
			if (j == 2)
				printf("|\n");
		}
	}
	printf("-------\n");
	is_end = additional_game_victory(win_or_lose, array);
	if (is_end == 0 || is_end == 1)
		return;
	printf("平局！\n");
	win_or_lose = 3;
	return;
}