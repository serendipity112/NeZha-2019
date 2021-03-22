#include "observe.h"

Observer::Observer() 
{

}
Observer:: ~Observer()
{

}
Subject::Subject() 
{

}
Subject::~Subject() 
{

}
void Subject::attach(Observer *observer)//添加观察者
{
	observers.push_back(observer);
}
void Subject::detach(Observer *observer)//删除观察者
{
	//删除特定的observer
	auto it = observers.begin();//迭代器
	for (; it != observers.end(); ++it)
	{
		if (*it == observer)
			break;
	}
	if (it != observers.end())
		observers.erase(it);
}
void Subject::notify()//注意更新信息
{
	for (auto it = observers.begin(); it != observers.end(); ++it)
	{
		(*it)->update();
	}
}
string ConcreteSubject::get()//获得状态
{
	return subjectState;
}
void ConcreteSubject::set(string value)//设定状态
{
	subjectState = value;
}

ConcreteObserver::ConcreteObserver(ConcreteSubject *sub, string name) :sub(sub), name(name)
{}
void ConcreteObserver::update()//更新
{	
	cout << "修炼地中的【" << name << "】收到您要前往修炼地内的指令！" << "他的状态是" << sub->get() << endl;
}
