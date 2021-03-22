#include "actor.h"

Actor::Actor()
{

}
Actor::~Actor()
{

}
Actor::Actor(string _name,int _power,int _life,string _place) :name(_name),  place(_place),power(_power),life(_life)
{

}
void Actor::set_place(string _place)//�趨���ڵ�
{
	place = _place;
}
string Actor::get_place()//��ȡ���ڵ�
{
	return place;
}
string Actor::get_name()//��ȡ����
{
	return name;
}
int Actor::get_power(void)//��ȡս����
{
	return power;
}
void Actor::add_power(int _power)//����ս����
{
	power += _power;
}
void Actor::sub_power(int _power)//����ս����
{
	power -= _power;
}
int Actor::get_life(void)//��ȡ������
{
	return life;
}
void Actor::set_life(int _life)//�趨������
{
	life = _life;
}
Actor & Actor::operator+=(int _life)//���� += ����������ֵ
{
	life += _life;
	return *this;
}
Actor & Actor::operator-=(int _life)//���� -= ����������ֵ
{
	life -= _life;
	if (life < 0)life = 0;
	return *this;
}

Combat_actor::Combat_actor()
{

}
Combat_actor::~Combat_actor()
{

}
Combat_actor::Combat_actor(string _name, int _power, int _life, string _place) : Actor(_name,_power,_life, _place)
{

}
int Combat_actor::get_num_of_weapon()//��ȡ������Ŀ
{
	return num_of_weapon;
}
void Combat_actor::set_num_of_weapon()//�趨������Ŀ
{
	int num=0;
	Weapons _weapons(weapons);//������������
	while (!_weapons.empty())
	{
		Weapon weapon = _weapons.top();//ȡ�ö���Ԫ��
		num++;
		_weapons.pop();//��������Ԫ��
	}
	num_of_weapon = num;
}
void Combat_actor::get_weapons_information(void)//��ʾȫ����������Ϣ
{
	int i = 0;
	Weapons _weapons(weapons);
	while (!_weapons.empty())
	{
		Weapon weapon = _weapons.top();
		cout << i << ":";
		cout << weapon << endl;
		_weapons.pop();
		i++;
	}
}
Weapon Combat_actor::get_best_weapon()//��ȡ������������
{
	Weapon weapon = weapons.top();
	return weapon;
}
Actor &Combat_actor::operator<<(Weapon weapon)//����<<���һ������
{
	weapons.push(weapon);
	return *this;
}
Actor &Combat_actor::operator>>(Weapon &weapon)//����>>ȡ��������������--��������
{
	if (!weapons.empty())
	{
		weapon = weapons.top();
		weapons.pop();
	}
	return *this;
}
//��߸��
void Combat_actor::on_lose(Actor &winner, Weapons &weapons)//ս��ʧ��
{
	//��������
	while (!weapons.empty())
	{
		Weapon weapon;
		(*this) >> weapon;
		weapons.push(weapon);//սʤ������������
	}
}
//��߸Ӯ
void Combat_actor::on_win(Actor &loser, Weapons &weapons)//ս���ɹ�
{
	//��������ʧ���ߵ�����
	if (!weapons.empty())
	{
		Weapon weapon = weapons.top();
		(*this) << weapon;
		weapons.pop();
	}
}
void Combat_actor::on_killed(Actor &winner)//��ɱ��
{
	cout << get_name() << "������" << endl;
}
Weapons &Combat_actor::get_weapons(void)//�����������
{
	return weapons;
}
void Combat_actor::print_attribute()//��ʾ����
{
	cout <<"\033[96m"<< "[��������]"  << endl;
	cout << "������" << get_name() << endl;
	cout << "ս������";
	for (int i = 0; i < get_power() / 10; i++)
		cout << "I";
	cout << "  "<<get_power() << endl;
	cout << "��������";
	for (int i = 0; i < get_life()/ 10; i++)
		cout << "I";
	cout << "  "<<get_life() << endl;
	cout <<endl << "[ӵ������]"  << endl;
	get_weapons_information();
	cout << "\033[0m" << endl;
}
void Combat_actor::cure_life()//����������ֵ�ָ�������
{
	set_life(200);
}
void Combat_actor::success_practice(int add_num)//�����ɹ�
{
	add_power(add_num);
	cure_life();
}
void Combat_actor::fail_practice(int sub_num)//����ʧ��
{
	sub_power(sub_num);
	cure_life();
}
int Combat_actor::get_initial_power()//��ó�ʼս����
{
	return initial_power;
}
void Combat_actor::set_initial_power(int power)//�趨��ʼս����
{
	initial_power = power;
}
int Combat_actor::get_initial_life()//��ó�ʼ������
{
	return initial_life;
}
void Combat_actor::set_initial_life(int life)//�趨��ʼ������
{
	initial_life = life;
}

//cout<<actor;
ostream & operator <<(ostream &cout, Combat_actor &actor)//���ز�����<< ��������������
{
	//�������
	cout << actor.get_name() << "(" << actor.get_power() << ")";
	//�������
	//����һ������
	Weapons _weapons(actor.get_weapons());
	if (!_weapons.empty())
	{
		cout << "[";
		while (!_weapons.empty())
		{
			//ȡ������Ԫ��
			Weapon weapon = _weapons.top();
			cout << weapon;
			//��������Ԫ��
			_weapons.pop();
		}
		cout << "]";
	}
	return cout;
}

Nezha::Nezha(string _name, int _power, int _life, string _place, int _relationship) :Combat_actor(_name, _power, _life, _place), relationship(_relationship)
{

}
Nezha::Nezha()
{

}
Nezha::~Nezha()
{
}
int Nezha::get_relationship()//��ȡ����ֵ
{
	return relationship;
}
void Nezha::add_relationship(int num)//��������ֵ
{
	relationship += num;
}
void Nezha::print_attribute()//��ʾ��߸����
{
	cout << "\033[92m" << "-----------�ҵ����Ͽ�-----------" << endl<<endl;
	cout <<"[��������]" << "\033[0m" << endl;
	cout << "\033[91m" << "        /\\_____/\\" << endl;
	cout << "        \\/     \\/" << endl;
	cout << "        /|___:_|\\" << endl;
	cout << "       | |o   o| |" << endl;
	cout << "	\\|  V  |/" << endl;
	cout << "         `-----`" <<"\033[0m"<< endl;
	cout << "\033[92m" <<"ս������";
	for (int i = 0; i < get_power() / 10; i++)
		cout << "I";
	cout << "  "<<get_power() << endl;
	cout << "��������";
	for (int i = 0; i < get_life() / 10; i++)
		cout << "I";
	cout << "  "<<get_life() << endl;
	cout << "����ֵ��";
	for (int i = 0; i < get_relationship() / 10; i++)
		cout << "I";
	cout <<"  "<< get_relationship() << endl;
	cout << endl  <<"[ӵ������]" << endl;
	get_weapons_information();
	cout << endl  << "[ӵ����Ʒ]" << endl;
	print_good();
	cout << endl;
	cout << "\033[0m";
}
int Nezha::get_num_of_good()//�����Ʒ����
{
	return num_of_good;
}
void Nezha::set_good(string _good)//������Ʒ
{
	good[num_of_good] = _good;
	num_of_good++;//��Ʒ������
}
string Nezha::get_good(int num)//�����Ʒ
{
	return good[num];
}
void Nezha::print_good()//�����Ʒ
{
	for (int i = 0; i < num_of_good; i++)
	{
		cout << i << ":" << good[i] << endl;
	}
}
bool Nezha::find_pen()//�ҵ��ʣ���ָ�㽭ɽ�ʡ���
{
	for (int i = 0; i < num_of_good; i++)
	{
		if (good[i] == "ָ�㽭ɽ��")
			return true;
	}
	return false;
}
void Nezha::write_file_actor(Nezha &actor)//����浵
{
	ofstream write_file("actor.dat", ios_base::out | ios_base::binary);
	write_file.write((char *)(&actor), sizeof(actor));
	write_file.close();
}
void Nezha::read_file_actor(Nezha &actor)//�������
{
	ifstream read_file;
	read_file.open("actor.dat", ios_base::in | ios_base::binary);
	read_file.read((char *)(&actor), sizeof(actor));
	read_file.close();
}
void Nezha::write_file_weapon(Weapon &weapon,ofstream &file)//�����浵
{
	file.write((char *)(&weapon), sizeof(weapon));
}
void Nezha::read_file_weapon(Combat_actor &actor)//��������
{
	ifstream read_file("weapon.dat", ios_base::in | ios_base::binary);
	int num;
	read_file >> num;
	for (int i = 0; i < num; i++)
	{
		Weapon weapon;
		read_file.read((char *)(&weapon), sizeof(weapon));
        actor << weapon;
	}
	read_file.close();
}