#pragma once
#include <iostream>
#include<ctime>
using namespace std;

//�ӱ��ࣨ����ʱ��
class Clock
{
private:
	int hour;//ʱ
	int minute;//��
	int second;//��
public:
	void set_time(int hour, int min, int sec);//�趨������ʱ��ʱ�ӵĳ�ʼֵ
	void count_down();//����ʱ����
	void show_time();//��ʾʱ��
	void run_time();//������ʱ��ʱ������
};