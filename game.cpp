#include"game.h"
#include "observe.h"
Game::Game()
{

}
Game::~Game()
{

}
void Game::save_game(Nezha &actor)//������Ϸ���浵��
{
	actor.write_file_actor(actor);
	actor.set_num_of_weapon();
	ofstream write_file("weapon.dat", ios_base::out | ios_base::binary);
	//����һ����������
	Weapons _weapons(actor.get_weapons());
	int real_num = actor.get_num_of_weapon();
	write_file << real_num;
	while (!_weapons.empty())
	{
		//ȡ������Ԫ��
		Weapon weapon = _weapons.top();
		actor.write_file_weapon(weapon, write_file);
		//��������Ԫ��
		_weapons.pop();
	}
	write_file.close();
}

//������Ϸ
void Game::run_game(Game game,Nezha &actor,Place place[],Wonderland practice_place[],Place *current)
{
	Place temp;
	Wonderland temp1;
	while (1)
	{
		current->describe_place();//��������
		MENU menu;
		cin >> (int &)menu;
		string file_name_map = "map.dat";
		string set_color_map = "\033[93m";
		switch (menu)
		{
		case MENU::play_prompt:
			current->print_warning(actor);//��ʾ�õص����ʾ
			break;
		case MENU::change_place:
			cout << "\033[93m";
			if (current->flag == 7)
			{
				ConcreteSubject *s = new ConcreteSubject();//���췢����
				s->attach(new ConcreteObserver(s, "���౦��"));
				s->attach(new ConcreteObserver(s, "�ɴ���"));
				s->attach(new ConcreteObserver(s, "з�ϰ�"));

				cout << "��ѡ������ǰ���ĵص�" << endl;
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
				if (current->spot[num_in] == "�ߴ�ɽ")
				{
					if (actor.find_pen() == false)
					{
						cout << endl<<"��δ�ҵ���ָ�㽭ɽ�ʡ������ܽ��������أ�" <<endl;
						cout << "-----------------------------------------------------------------------------------" << endl;
						s->set("���ڡ����汤������ˣ��");
						s->notify();
						cout << "-----------------------------------------------------------------------------------" << endl;
						delete s;
					}
					else
					{
						cout << "-----------------------------------------------------------------------------------" << endl;
						cout << "���౦���Ӳ����ݸ����� " << "�ɴ��Ǵ�ʯͷ�ݸ����� " << "з�ϰ�Ӵ�ê��������" << endl;
						s->set("׼�����ˣ�");
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
				current->change_place(place, practice_place, *current);//ʵ�ֵص��л�
			}
			actor.set_place(current->get_name());
			cout << "\033[0m";
			system("pause");
			break;
		case MENU::go_fighting:
			current->fight_with_demon(actor);//ʵ���ڸõص��ս��
			break;
		case MENU::print_map:
			game.print_file(file_name_map, set_color_map);
			//��ӡ��ͼ
			system("pause");
			break;
		case MENU::save_game:
			cout << "\033[94m";
			cout << "1.�浵 2.�˳���Ϸ 3.ȡ��" << endl;
			int choose;
			cin >> choose;
			cout << "\033[0m";
			if (choose == 1)
				save_game(actor);
			if (choose == 2) exit(0);
			system("pause");
			break;
		case MENU::my_information:
			actor.print_attribute();//��ʾ�������Կ�
			system("pause");
			break;
		case MENU::enemy_information:
			current->look_demon();//��ʾ��������
			system("pause");
			break;
		default:cout << "�������" << endl;
			system("pause");
		}
	}
}
void Game::print_file(string file_name,string set_color)//�ļ���ȡ
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