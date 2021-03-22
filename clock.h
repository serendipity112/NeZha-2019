#pragma once
#include <iostream>
#include<ctime>
using namespace std;

//钟表类（倒计时）
class Clock
{
private:
	int hour;//时
	int minute;//分
	int second;//秒
public:
	void set_time(int hour, int min, int sec);//设定“倒计时”时钟的初始值
	void count_down();//倒计时操作
	void show_time();//显示时间
	void run_time();//“倒计时”时钟运行
};