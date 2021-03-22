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
void Actor::set_place(string _place)//设定所在地
{
	place = _place;
}
string Actor::get_place()//获取所在地
{
	return place;
}
string Actor::get_name()//获取姓名
{
	return name;
}
int Actor::get_power(void)//获取战斗力
{
	return power;
}
void Actor::add_power(int _power)//增加战斗力
{
	power += _power;
}
void Actor::sub_power(int _power)//减少战斗力
{
	power -= _power;
}
int Actor::get_life(void)//获取生命力
{
	return life;
}
void Actor::set_life(int _life)//设定生命力
{
	life = _life;
}
Actor & Actor::operator+=(int _life)//重载 += 增加生命力值
{
	life += _life;
	return *this;
}
Actor & Actor::operator-=(int _life)//重载 -= 增加生命力值
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
int Combat_actor::get_num_of_weapon()//获取武器数目
{
	return num_of_weapon;
}
void Combat_actor::set_num_of_weapon()//设定武器数目
{
	int num=0;
	Weapons _weapons(weapons);//创建武器副本
	while (!_weapons.empty())
	{
		Weapon weapon = _weapons.top();//取得顶端元素
		num++;
		_weapons.pop();//弹出顶端元素
	}
	num_of_weapon = num;
}
void Combat_actor::get_weapons_information(void)//显示全部武器的信息
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
Weapon Combat_actor::get_best_weapon()//获取最厉害的武器
{
	Weapon weapon = weapons.top();
	return weapon;
}
Actor &Combat_actor::operator<<(Weapon weapon)//重载<<添加一个武器
{
	weapons.push(weapon);
	return *this;
}
Actor &Combat_actor::operator>>(Weapon &weapon)//重载>>取出威力最大的武器--武器减少
{
	if (!weapons.empty())
	{
		weapon = weapons.top();
		weapons.pop();
	}
	return *this;
}
//哪吒输
void Combat_actor::on_lose(Actor &winner, Weapons &weapons)//战斗失败
{
	//交出武器
	while (!weapons.empty())
	{
		Weapon weapon;
		(*this) >> weapon;
		weapons.push(weapon);//战胜方将武器收下
	}
}
//哪吒赢
void Combat_actor::on_win(Actor &loser, Weapons &weapons)//战斗成功
{
	//收下来自失败者的武器
	if (!weapons.empty())
	{
		Weapon weapon = weapons.top();
		(*this) << weapon;
		weapons.pop();
	}
}
void Combat_actor::on_killed(Actor &winner)//被杀死
{
	cout << get_name() << "被消灭" << endl;
}
Weapons &Combat_actor::get_weapons(void)//获得所有武器
{
	return weapons;
}
void Combat_actor::print_attribute()//显示属性
{
	cout <<"\033[96m"<< "[人物属性]"  << endl;
	cout << "姓名：" << get_name() << endl;
	cout << "战斗力：";
	for (int i = 0; i < get_power() / 10; i++)
		cout << "I";
	cout << "  "<<get_power() << endl;
	cout << "生命力：";
	for (int i = 0; i < get_life()/ 10; i++)
		cout << "I";
	cout << "  "<<get_life() << endl;
	cout <<endl << "[拥有武器]"  << endl;
	get_weapons_information();
	cout << "\033[0m" << endl;
}
void Combat_actor::cure_life()//治愈（生命值恢复到满格）
{
	set_life(200);
}
void Combat_actor::success_practice(int add_num)//修炼成功
{
	add_power(add_num);
	cure_life();
}
void Combat_actor::fail_practice(int sub_num)//修炼失败
{
	sub_power(sub_num);
	cure_life();
}
int Combat_actor::get_initial_power()//获得初始战斗力
{
	return initial_power;
}
void Combat_actor::set_initial_power(int power)//设定初始战斗力
{
	initial_power = power;
}
int Combat_actor::get_initial_life()//获得初始生命力
{
	return initial_life;
}
void Combat_actor::set_initial_life(int life)//设定初始生命力
{
	initial_life = life;
}

//cout<<actor;
ostream & operator <<(ostream &cout, Combat_actor &actor)//重载操作符<< 简便地输出人物对象
{
	//输出姓名
	cout << actor.get_name() << "(" << actor.get_power() << ")";
	//输出武器
	//构造一个副本
	Weapons _weapons(actor.get_weapons());
	if (!_weapons.empty())
	{
		cout << "[";
		while (!_weapons.empty())
		{
			//取出顶部元素
			Weapon weapon = _weapons.top();
			cout << weapon;
			//弹出顶部元素
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
int Nezha::get_relationship()//获取友谊值
{
	return relationship;
}
void Nezha::add_relationship(int num)//增加友谊值
{
	relationship += num;
}
void Nezha::print_attribute()//显示哪吒属性
{
	cout << "\033[92m" << "-----------我的资料卡-----------" << endl<<endl;
	cout <<"[人物属性]" << "\033[0m" << endl;
	cout << "\033[91m" << "        /\\_____/\\" << endl;
	cout << "        \\/     \\/" << endl;
	cout << "        /|___:_|\\" << endl;
	cout << "       | |o   o| |" << endl;
	cout << "	\\|  V  |/" << endl;
	cout << "         `-----`" <<"\033[0m"<< endl;
	cout << "\033[92m" <<"战斗力：";
	for (int i = 0; i < get_power() / 10; i++)
		cout << "I";
	cout << "  "<<get_power() << endl;
	cout << "生命力：";
	for (int i = 0; i < get_life() / 10; i++)
		cout << "I";
	cout << "  "<<get_life() << endl;
	cout << "友谊值：";
	for (int i = 0; i < get_relationship() / 10; i++)
		cout << "I";
	cout <<"  "<< get_relationship() << endl;
	cout << endl  <<"[拥有武器]" << endl;
	get_weapons_information();
	cout << endl  << "[拥有物品]" << endl;
	print_good();
	cout << endl;
	cout << "\033[0m";
}
int Nezha::get_num_of_good()//获得物品数量
{
	return num_of_good;
}
void Nezha::set_good(string _good)//存入物品
{
	good[num_of_good] = _good;
	num_of_good++;//物品数增加
}
string Nezha::get_good(int num)//获得物品
{
	return good[num];
}
void Nezha::print_good()//输出物品
{
	for (int i = 0; i < num_of_good; i++)
	{
		cout << i << ":" << good[i] << endl;
	}
}
bool Nezha::find_pen()//找到笔（【指点江山笔】）
{
	for (int i = 0; i < num_of_good; i++)
	{
		if (good[i] == "指点江山笔")
			return true;
	}
	return false;
}
void Nezha::write_file_actor(Nezha &actor)//人物存档
{
	ofstream write_file("actor.dat", ios_base::out | ios_base::binary);
	write_file.write((char *)(&actor), sizeof(actor));
	write_file.close();
}
void Nezha::read_file_actor(Nezha &actor)//人物读档
{
	ifstream read_file;
	read_file.open("actor.dat", ios_base::in | ios_base::binary);
	read_file.read((char *)(&actor), sizeof(actor));
	read_file.close();
}
void Nezha::write_file_weapon(Weapon &weapon,ofstream &file)//武器存档
{
	file.write((char *)(&weapon), sizeof(weapon));
}
void Nezha::read_file_weapon(Combat_actor &actor)//武器读档
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