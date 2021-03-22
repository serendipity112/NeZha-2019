#include"place.h"
//���������ʼ����� �����ṹ

Place::Place()
{

}
Place:: ~Place()
{
}
Place::Place(string _name,int _flag) :name(_name),flag(_flag)
{
}
string Place::get_name()//��ȡ�ص���
{
	return name;
}
void Place::input_demon(Combat_actor &actor)//�������
{
	demon = actor;
	have_demon= 1;
}
void Place::connect_place(string spot1, string spot2, string spot3, string spot4)//�ص�����
{
	spot[0] = spot1;
	spot[1] = spot2;
	spot[2] = spot3;
	spot[3] = spot4;
}
void Place::describe_place()//�ص�����
{	
	system("cls");
	cout << "\033[91m"<<"[" << name<< "]" << "\033[0m" << endl;
	cout  << "������" << "\033[91m"<<"[" << name <<"]"  <<"\033[0m" << endl << "����ͨ���ĵط�: ";
	for (int i = 0; i < 4; i++)
	{
		if (spot[i] == "0")break;
		else cout << "\033[91m" << "[" << spot[i] << "] " << "\033[0m";
	}
	if(flag==7||flag==8||flag==9||flag==10) cout << "����û�е���"  << endl;
	else { cout << "�����е��ˣ�"<< "\033[91m" << "��" << demon.get_name() << "��" << "\033[0m" << endl; }
	cout << "1.��ʾ 2.��· 3.ս�� 4.��ͼ 5.ϵͳ 6.�ҵ���Ϣ 7.������Ϣ" << endl;
	cout << "\033[91m" << "��������������������������������������������������������������������������������������������������������������������������������������" << "\033[0m" << endl;
}
void Place::change_place(Place place[],Wonderland practice_place[],Place &current_place)//ת���ص��ڲ�����
{
	cout << "\033[93m";
	if ((flag == 1 && current_place.demon_is_dead() == false ))
		cout << "�㻹δ��ܽ���ޣ���ʱ���ܳ�ȥ��" << endl;
	if ((flag == 1&& current_place.demon_is_dead() == true)||flag!=1)
	{
	if (spot[0] != "0")
	{
		cout << "��ѡ������ǰ���ĵص�" << endl;
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
		cout << "û�п���ǰ���ĵص㣡" << endl;
	}
	}
	cout << "\033[0m";
}
void Place::print_warning(Nezha &actor)//��ʾ
{
	cout << "\033[96m";
	switch (flag)
	{
	case 1:cout << "����������������ܱ���ĸ�ۡ��"<<endl<<"��ĸ�����ý�����ڴ˿����㡣���ڣ���ܽ���ޣ�ȥ��������翴���ɣ�"<<endl;  break;
	case 2:cout << "ɽ����¹������˻��������Ի¹̨ɽ��������С��¹�񣬲��糢�Դ�����ǰɣ�"<<endl;  break;
	case 3:cout << "������֮�⣬���֮�磬��ɽ�����ϣ���Ի���ܸ��ӣ��д�������Ի�и���"<<endl;   break;
	case 4:cout << "�����Ƕ���������Ͻ�ĺ���" << endl;
		   cout << "�Ƿ�Ҫ�밽������Ϸ�����Ͱ���������ֵ�ﵽ100������ӭս����Ŷ��    1�� 2��";
		int play_with_npc;
		cin >> play_with_npc;
		if (play_with_npc == 1)
		{
			int win_or_lose;
			additional_game_tictactoe(win_or_lose);
			//��Ϸ
			if (win_or_lose == 3)
			{
				actor.add_relationship(35);

				cout << "���밽��������ֵ����35��" << endl;
			}
		    //��relationship
		}break;
	case 5:cout << "�����澳���깫���ڴ������������㹻ǿ�󣬲��糢�Դ������"<<endl;  break;
	case 6:cout << "Ԫʼ����������������������ٽ��ή�٣��ݻ�ħ�衣������һ�����񣬾���ӭս���ף�"<<endl;  break;
	case 7:cout << "̫�����ˣ�������ʦ��̫�����ˣ���������ɽ�����ͼ��" << endl<<"ɽ��ͼ�п����������֣�������ʹ���������ٴ�����,����ֿ���ʹ��ս����������"<<endl<<"������ڱߴ�ɽ����ˮ���߳���ɽ���֡�" << endl;
		   cout << endl<<"�Ƿ�Ҫ��ɽ��ͼ��������1�� 2��";
		int practice;
		cin >> practice;
		if (practice == 1)
		{   
			cout << "��������ʱing...��ȴ�" << endl;
			//����ʱ
			cout << "\033[93m";	
			Clock clock;
			clock.set_time(0, 0, 10);
			clock.run_time();
			actor.cure_life();
			cout << "�����������������ֵ�ѻָ���200��������Ԫ������@_@��" << endl;
		}break;
	case 8:cout << "�������ں��ϵ�һ����ɽ��"<<endl; break;
	case 9:cout << "����Ⱥ��ͦ�Σ�������Ҫ��������ɽ�ߣ���ɳ���䡱��" << endl;
		   cout << "�ڴ˴����֡�ָ�㽭ɽ�ʡ����Ƿ�ʰ�� 1.��" << endl;
		int pick;
		cin >> pick;
		if (pick == 1)
		{
			actor.set_good("ָ�㽭ɽ��");
			cout << "��ϲ����ָ�㽭ɽ�ʣ���������Դ�ɽ�����ͼ����" << endl;
		}
		break;
	case 10:cout << "�����ǽ�ͨҪ�������ء�" << endl;
		    cout << "��һ����ʥ����Իɽ�����ͼ������Ҫȥ����Ҫ���ҵ�һö��Կ�ס���ָ�㽭ɽ�ʣ������ڵ�ͼ�ϵ�ĳ����ȥ���ҿ��ɣ�"<<endl; break;
	case 11:cout << "�ߴ�֮ɽ����������ޣ����౦�������ڴ˴���֣����ս������"<<endl; break;
	case 12:cout << "�����д���ɳ�⣬���ˮ�����롣�������ɴ��ǡ����ڴ˴���֣����ս������"<<endl; break;
	case 13:cout << "�������ЯԶᶣ��˻Ӱ��������硣���ޣ�з�ϰ塣���ڴ˴���֣����ս������"<<endl; break;
	}
	cout << "\033[0m";
	system("pause");	
}
void Place::fight_with_demon(Nezha &actor)//��ս
{
	cout << "\033[92m";
	if (actor.get_relationship() < 100 && flag == 6)
	{
		cout << "���Ͱ���������ֵ��δ�ﵽ100����ʱ����ӭս���ף�" << endl;
		cout << "\033[0m";
		system("pause");
	}
	if (actor.get_relationship() > 99 && flag == 6)
	{
		cout << "���Ƿ�Ҫ��̫�����ˡ�������(����)1.�� 2.��" << endl;
		int help;
		cin >> help;
		if (help == 1)
		{
			cout << "��̫�����ˡ�����ʹ�á���������������ѽ�������������500!" << endl;
			actor.add_power(500);
			cout << "\033[0m";
			system("pause");
		}
		if (help == 2)
		{
			cout << "Good luck! �����������һ�������ı�Ӱ���¾���սing..." << endl;
			cout << "\033[0m";
			system("pause");
		}
	}
	if (have_demon == 1 && flag != 6 || have_demon == 1 && flag == 6 && actor.get_relationship() > 99)
	{
		cout << "\033[92m";
		int fight;
		cout << "\033[0m";
		cout << "������� (����1.���� 2.����)" << endl;
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
			//ȡ��������������
			cout << "-----------------------------------------------------------" << endl;
			cout << "����ȡ��������������ing..." << endl;
			best_weapon = actor.get_best_weapon();
			cout << "��ȡ����" << best_weapon << endl;
			cout << "-----------------------------------------------------------" << endl;
		}
		if (demon.get_life() == 0)
		{
			cout << "���޸ո��ѱ�����ܣ��´����˵زŻ��п��Թ���Ĺ���Ŷ~" << endl;
			cout << "\033[0m";
			system("pause");
		}
		else {
			while (fight == 1)
			{
				cout << "\033[92m";
				//current->demon��actor_one��ս
				cout << "������ing..." << endl;
				cout << "��ʹ����" << best_weapon.get_name() << endl;
				cout << "�Է��ܵ�" << best_weapon.get_power() + actor.get_power() << "���˺�" << endl;
				//�Է�����
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
					cout << "��ϲ��ң������ѱ�����(�ޣ���)V" << endl;
					cout << "��!!!�ջ����������";
					demon.get_weapons_information();

					//սʤ����-��߸Ӯʱ���ɻ��������
					actor.on_win(demon, demon.get_weapons());
					if (flag == 6)
					{
						cout << endl;
						cout << "\033[94m";
						cout << "[][][][][][][][][][][][][][][][][][][]" << endl;
						cout << "[]        ~congratulations~         []" << endl << "[]         �������Ҳ�����!          []" << endl << "[]       ��ϲ�㣡���سɹ��ˣ�       []" << endl;
						cout << "[][][][][][][][][][][][][][][][][][][]" << endl;
						cout << "\033[0m";
						system("pause");
						exit(0);
					}
					cout << "\033[0m";
					system("pause");
					break;
				}
				cout << "�Է�����ing..." << endl;
				cout << "�Է�ʹ����" << demon.get_best_weapon().get_name() << endl;
				cout << "���ܵ���" << demon.get_best_weapon().get_power() + demon.get_power() << "���˺�" << endl;
				//��Ҽ���
				if (actor.get_life() - demon.get_best_weapon().get_power() - demon.get_power() > 0)
					actor -= demon.get_best_weapon().get_power() + demon.get_power();
				else {
					  cout << endl;
					  cout << "\033[94m";
					  cout << "[][][][][][][][][][][][][][][][][][][][]" << endl;
					  cout << "[]���������ѽ���~                     []" << endl;
					  cout << "[]�������屻���౦�������ˡ����汤����[]" << endl;
					  cout << "[]�治�ң���Ϸ�����ˣ�                []" << endl;
					  cout << "[][][][][][][][][][][][][][][][][][][][]" << endl<<endl;
					  cout << "\033[0m";
					  system("pause"); 
					  exit(0);
				     }
				cout << "\033[0m";
				cout << "������� (����1.���� 2.����)" << endl;
				cin >> fight;
				if (fight == 2)system("pause");
			}
		}
	}
	if(have_demon != 1)
	{
		cout << "��ɶ�أ���������û�й��ޣ�" << endl;
		cout << "\033[0m";
		system("pause");
	}
	cout << "\033[0m";

}
void Place::look_demon()//�鿴������Ϣ
{
	cout << "\033[96m";
	if (have_demon == 1)
	{
		cout << "��ǰ���ڵ����������ϣ�" << endl;
		demon.print_attribute();
	}
	else
	{
		cout << "�õ�������Ŷ~"<<endl;
	}
	cout << "\033[0m";
}
bool Place::demon_is_dead()//�жϸõع����Ƿ�����
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
void Wonderland::fight_with_demon(Nezha &actor) //ѵ��
{
	if (have_demon != 1)
	{
		cout << "\033[92m";
		cout << "��ɶ�أ���������û�й��ޣ�" << endl;
		cout << "\033[0m";
		system("pause");
	}
	else {
		int fight;
		cout << "������� (����1.���� 2.����)" << endl;
		cin >> fight;
		//ȡ��������������
		cout << "\033[92m";
		cout << "-------------------------------------------" << endl;
		cout << "����ȡ��������������ing..." << endl;
		Weapon best_weapon;
		best_weapon = actor.get_best_weapon();
		cout << "��ȡ����" << best_weapon << endl;
		cout << "-------------------------------------------" << endl;

		demon.set_life(demon.get_initial_life());

		while (fight == 1)
		{
			cout << "\033[92m";
			//current->practice_demon��actor��ս
			cout << "������ing..." << endl;
			cout << "��ʹ����" << best_weapon.get_name() << endl;
			cout << "�Է��ܵ�" << best_weapon.get_power() + actor.get_power() << "���˺�" << endl;
			//�Է�����
			if (demon.get_life() - best_weapon.get_power() - actor.get_power() > 0)
				demon -= best_weapon.get_power() + actor.get_power();
			else
			{
				demon.set_life(0);
				cout << "---------------------congratulations!---------------------" << endl;
				cout << '\a';
				cout << "��ϲ��ң������ѱ����ܣ��ɹ����������" << endl;
				//�����ɹ���ս����+10
				actor.success_practice(10);
				cout << "\033[0m";
				system("pause");
				break;
			}
			cout << "�Է�����ing..." << endl;
			cout << "�Է�ʹ����С�ϵ��Һ" << endl;
			cout << "���ܵ���" << demon.get_power() << "���˺�" << endl;
			//��Ҽ���
			if (actor.get_life() - demon.get_power() > 0)
				actor -= demon.get_power();
			else {
				cout << "̫�ź��ˣ����ڴ˴�������ʧ�ܣ�" << endl;
				cout << "\033[0m";
				system("pause");
				break;
			}
			cout << "\033[0m";
			cout << "������� (����1.���� 2.����)" << endl;
			cin >> fight;
		}
	}
}

//��������������Ǵ�һ��һѧ�ڵľ����������0.0
void Place::additional_game_calculate(int array[][3], int array_[][3])//����С��Ϸ�㷨����
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
int Place::additional_game_victory(int &win_or_lose, int array[][3])//����С��Ϸʤ�����
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
			printf("����Ӯ�ˣ�\n");
			win_or_lose = 1;
			return 1;
		}
		else if (n == 3)
		{
			printf("��Ӯ�ˣ�\n");
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
			printf("����Ӯ�ˣ�\n");
			win_or_lose = 1;
			return 1;
		}
		else if (q == 3)
		{
			printf("��Ӯ�ˣ�\n");
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
		printf("����Ӯ�ˣ�\n");
		win_or_lose = 1;
		return 1;
	}
	else if (n == 3)
	{
		printf("��Ӯ�ˣ�\n");
		win_or_lose = 0;
		return 0;
	}
	if (array[0][2] == 1 && array[1][1] == 1 && array[2][0] == 1)
	{
		printf("����Ӯ�ˣ�\n");
		win_or_lose = 1;
		return 1;
	}
	else if (array[0][2] == 3 && array[1][1] == 3 && array[2][0] == 3)
	{
		printf("��Ӯ�ˣ�\n");
		win_or_lose = 0;
		return 0;
	}
	return 2;
}
void Place::additional_game_tictactoe(int &win_or_lose)//����С��Ϸ��Ҫʵ��
{
	int array[3][3] = { 0 };
	int array_[3][3];
	int  x, y,  x1, y11, i, j,k, max1, num;
int is_end;
	char tu[4] = { ' ','#',' ','o' };
	printf("\n**********************************************************************\n");
	printf("                           !��ӭ���龮����Ϸ��\n");
	printf("**********************************************************************\n");
	printf("��˵���������Ͻ�Ϊ(0,0)�����½�Ϊ(2,2)��\n\n");
	printf("--------------------������Ϊ ��������Ϊ#��������Ϊo--------------------\n");
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
		printf("���Ķ��ְ�����������\n");
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
		printf("����������������(x1 y1)(0=<x1<=2,0=<y1<=2)��ע��:���������ֻ��Ϊ0 1 2Ŷ~��\n");
		scanf("%d%d", &x1, &y11);
		if (array[x1][y11] != 1 && array[x1][y11] != 3)
		{
			array[x1][y11] = 3;
		}
		else
		{
			printf("��λ����������\n");
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
	printf("���Ķ��ְ�����������\n");
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
	printf("ƽ�֣�\n");
	win_or_lose = 3;
	return;
}