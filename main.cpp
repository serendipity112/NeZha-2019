#include "game.h"

int main()//��������
{
    Game game;
	string file_name_window = "Nezha_window.dat";
    string set_color_window = "\033[91m";
	game.print_file(file_name_window, set_color_window);

	string file_name_intro = "Introduce.dat";
	string set_color_intro = "\033[96m";
	game.print_file(file_name_intro, set_color_intro);

	cout << endl << "����������������������������������ѡ�񡪡�����������������������������" << endl;
	cout << "\033[41m" << "                             1.������Ϸ                               " << "\033[0m" << endl;
	cout << "\033[101m" << "                             2.��ʼ��Ϸ                               " << "\033[0m" << endl;

	//������Ϸ����ص�
	Place place[10] = { Place("�",1),Place("¹̨",2),Place("����ɽ",3),Place("����",4),Place("���ι�",5),Place("�칬",6),Place("ɽ�����ͼ",7), Place("��ҡɽ", 8),
	Place("����ɽ", 9),Place("������", 10) };
	Wonderland practice_place[3] = { Wonderland("�ߴ�ɽ", 11),Wonderland("��ˮ", 12),Wonderland("����ɽ", 13) };

	//����ÿ���ص��Ŀ�����ӵ�
	place[0].connect_place("������", "0", "0", "0");//A
	place[1].connect_place("����ɽ", "0", "0", "0");//B
	place[2].connect_place("¹̨", "������", "0", "0");//C
	place[3].connect_place("�칬", "��ҡɽ", "������", "0");//D
	place[4].connect_place("ɽ�����ͼ", "����ɽ", "������", "0");//E
	place[5].connect_place("����", "0", "0", "0");//F
	place[6].connect_place("���ι�", "�ߴ�ɽ", "0", "0");//G
	place[7].connect_place("����", "0", "0", "0");//H
	place[8].connect_place("���ι�", "0", "0", "0");//I
	place[9].connect_place("�", "����ɽ", "����", "���ι�");//J
	practice_place[0].connect_place("ɽ�����ͼ", "��ˮ", "0", "0");//a
	practice_place[1].connect_place("�ߴ�ɽ", "����ɽ", "0", "0");//b
	practice_place[2].connect_place("��ˮ", "0", "0", "0");//c

	//������Ϸ��������
	Combat_actor combat_actor[9] = { Combat_actor("�����", 20, 10, "�"),Combat_actor("¹��", 25, 120, "¹̨"),Combat_actor("�и�", 30, 150, "����ɽ"),
	Combat_actor("��ҹ��", 35, 180, "����"),Combat_actor("�깫��", 40, 200, "���ι�"),Combat_actor("����", 50, 1500, "�칬"),Combat_actor("���౦��",15,50,"�ߴ�ɽ"),
	Combat_actor("�ɴ���",20,100,"��ˮ"),Combat_actor("з�ϰ�",25,110,"����ɽ") };

	//������Ϸ�е�����
	Weapon weapon[7] = { Weapon("ľ��", 2),Weapon("Ǭ��Ȧ", 5),Weapon("�����", 10),Weapon("�����", 15),
	Weapon("���ǹ", 20),Weapon("������", 30),Weapon("����", 40) };

	//�����������������
	for (int i = 0; i < 6; i++)
	{
		combat_actor[i] << weapon[i + 1];
	}

	//��������������ص�
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

	//����1������Ϸ������2��ʼ��Ϸ
	int choose;
	cin >> choose;

	switch (choose)
	{
	case 1:
	{	Place *current;//�ص�ָ��
	cout << "��ӭ��������ӭ���������;��" << endl;
	cout << "��ȡ������..." << endl;
	system("pause");
	//�������룺
	Nezha temp_actor;//������߸���︱��
	temp_actor.read_file_actor(temp_actor);
	//������߸����ң�
	Nezha leading_actor(temp_actor.get_name(), temp_actor.get_power(), temp_actor.get_life(), temp_actor.get_place(), temp_actor.get_relationship());
	//����Ʒ
	for (int i = 0; i < temp_actor.get_num_of_good(); i++)
	{
		leading_actor.set_good(temp_actor.get_good(i));
	}
	ifstream read_file("weapon.dat", ios_base::out | ios_base::binary);
	int num;//������Ŀ
	read_file >> num;//��ȡ����������Ŀ
	Weapon weapon0;//������������
	for (int i = 0; i < num; i++)
	{
		read_file.read((char *)(&weapon0), sizeof(weapon0));
		Weapon weapon1(weapon0.get_name(), weapon0.get_power());
		leading_actor << weapon1;
	}
	read_file.close();

	//����ص㸱��
	Place temp_place = place[0];//�޸� ����ֱ��current=&place[0],��ʹplace[0]�����ı�
	current = &temp_place;
	Place temp0;
	Wonderland temp_place2;
	Place temp;
	Wonderland temp1;
	for (int i = 0; i < 10; i++)
	{
		if (place[i].get_name() == leading_actor.get_place())
		{
			//�޸� ����ֱ��current=&place[0],��ʹplace[0]�����ı�
			temp0 = place[i];
			current = &temp0;
			break;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if (practice_place[i].get_name() == leading_actor.get_place())
		{
			temp_place2 = practice_place[i];//�޸� ����ֱ��current=&place[0],��ʹplace[0]�����ı�
			current = &temp_place2;
			break;
		}
	}
	game.run_game(game, leading_actor, place, practice_place, current);
	}
	break;
	case 2:
	{//��Ϸ��ʼ
		system("cls");//����
		string file_name_window = "background.dat";
		string set_color_window = "\033[95m";
		game.print_file(file_name_window, set_color_window);
		system("pause");
		Nezha leading_actor("��߸", 5, 200, "�", 0);//������߸����ң�
		Place temp;
		Wonderland temp1;
		Place *current;//�ص�ָ��
		leading_actor << weapon[0];//����߸ľ��
		Place temp_place = place[0];//�޸� ����ֱ��current=&place[0],��ʹplace[0]�����ı�
		current = &temp_place;
		game.run_game(game, leading_actor, place, practice_place, current);
	}break;
	}
	return 0;
}