#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "observe.h"
using namespace std;

//�۲���ģʽ

//��Ϣ�����ߡ�������
class Observer
{
public:
	Observer();
	virtual ~Observer();
	virtual void update() = 0;//��������
};

//��Ϣ�����ߡ�������
class Subject
{
public:
	Subject();
	virtual ~Subject();
	virtual void attach(Observer *observer);//��ӹ۲���
	virtual void detach(Observer *observer);//ɾ���۲���
	virtual void notify();//ע�������Ϣ
private:
	vector<Observer*>observers;//�۲����б�
};

//������Ϣ�����ߡ���������
class ConcreteSubject : public Subject
{
public:
	string get();//���״̬
	void set(string value);//�趨״̬
private:
	string subjectState;//״̬
};

//������Ϣ�����ߡ���������
class ConcreteObserver : public Observer
{
public:
	ConcreteObserver(ConcreteSubject *sub, string name);
	void update() override;//����
private:
	ConcreteSubject *sub;//������
	string name;//����������
	string observerState;//�����ߵ�״̬
};