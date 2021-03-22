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
void Subject::attach(Observer *observer)//��ӹ۲���
{
	observers.push_back(observer);
}
void Subject::detach(Observer *observer)//ɾ���۲���
{
	//ɾ���ض���observer
	auto it = observers.begin();//������
	for (; it != observers.end(); ++it)
	{
		if (*it == observer)
			break;
	}
	if (it != observers.end())
		observers.erase(it);
}
void Subject::notify()//ע�������Ϣ
{
	for (auto it = observers.begin(); it != observers.end(); ++it)
	{
		(*it)->update();
	}
}
string ConcreteSubject::get()//���״̬
{
	return subjectState;
}
void ConcreteSubject::set(string value)//�趨״̬
{
	subjectState = value;
}

ConcreteObserver::ConcreteObserver(ConcreteSubject *sub, string name) :sub(sub), name(name)
{}
void ConcreteObserver::update()//����
{	
	cout << "�������еġ�" << name << "���յ���Ҫǰ���������ڵ�ָ�" << "����״̬��" << sub->get() << endl;
}
