#include"clock.h"

void Clock::set_time(int _hour, int _minute, int _second)//设定“倒计时”时钟的初始值
{
	hour = _hour;
	minute = _minute;
	second = _second;
}
void Clock::count_down()//倒计时操作
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
void Clock::show_time()//显示时间
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
void Clock::run_time()//“倒计时”时钟运行
{
	while (hour != 0 || minute != 0 || second != 0)//当 时分秒 都为0时跳出循环
	{
		count_down();//实现倒序1秒
		show_time();//显示当前“倒计时”时钟
	}
	cout << "\033[96m";
	cout << endl << "Time out!" << endl;//倒计时结束
	cout << '\a';//输出警报
}