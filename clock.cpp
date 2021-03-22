#include"clock.h"

void Clock::set_time(int _hour, int _minute, int _second)//�趨������ʱ��ʱ�ӵĳ�ʼֵ
{
	hour = _hour;
	minute = _minute;
	second = _second;
}
void Clock::count_down()//����ʱ����
{
	time_t t = time(NULL);
	while (time(NULL) == t);
	if (--second < 0)
	{
		second = 59;
		if (--minute < 0)
		{
			minute = 59;
			--hour;
		}
	}
}
void Clock::show_time()//��ʾʱ��
{
	cout << '\r';
	if (hour < 10)
		cout << 0;
	cout << hour << ':';
	if (minute < 10)
		cout << 0;
	cout << minute << ':';
	if (second < 10)
		cout << 0;
	cout << second << flush;
}
void Clock::run_time()//������ʱ��ʱ������
{
	while (hour != 0 || minute != 0 || second != 0)//�� ʱ���� ��Ϊ0ʱ����ѭ��
	{
		count_down();//ʵ�ֵ���1��
		show_time();//��ʾ��ǰ������ʱ��ʱ��
	}
	cout << "\033[96m";
	cout << endl << "Time out!" << endl;//����ʱ����
	cout << '\a';//�������
}