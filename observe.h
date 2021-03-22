#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "observe.h"
using namespace std;

//观察者模式

//消息接收者——基类
class Observer
{
public:
	Observer();
	virtual ~Observer();
	virtual void update() = 0;//更新数据
};

//消息发布者——基类
class Subject
{
public:
	Subject();
	virtual ~Subject();
	virtual void attach(Observer *observer);//添加观察者
	virtual void detach(Observer *observer);//删除观察者
	virtual void notify();//注意更新信息
private:
	vector<Observer*>observers;//观察者列表
};

//具体消息发布者——派生类
class ConcreteSubject : public Subject
{
public:
	string get();//获得状态
	void set(string value);//设定状态
private:
	string subjectState;//状态
};

//具体消息接收者——派生类
class ConcreteObserver : public Observer
{
public:
	ConcreteObserver(ConcreteSubject *sub, string name);
	void update() override;//更新
private:
	ConcreteSubject *sub;//发布者
	string name;//接受者姓名
	string observerState;//接收者的状态
};