/*
首先是要知道这个蛇头在哪里，
然后这个蛇要自己会走，
要知道撞墙，还会撞到自己
要知道吃了新的东西，
要有一个前进的速度，
要有一个速度的变化，
蛇要不断的print，
还需要不断的清空屏幕
要可以改变蛇的方向
要有个初始的大小
还要有一些好玩的东西
*/
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<windows.h>
#include <conio.h>
#include "sss.h"
typedef std::pair<int, int>PII;
int t;
sneak S;
void print()
{
	S.ppp();
	HANDLE hout;
	COORD coord;
	for (auto& t : S.marks)
	{
		coord.Y = t.first;
		coord.X = t.second;
		hout = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hout, coord);
		std::cout << '+';
	}

}
bool run()
{
	S.renew();
	if (S.is_over())
	{
		printf("game over\nGame over\ngame over");
		return 0;
	}
	print();
	return 1;
}
void init()
{
	HANDLE hout;
	COORD coord;
	for (int i = 0; i <= 75; ++i)
	{
		coord.Y = 0;
		coord.X = i;
		hout = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hout, coord);
		std::cout << '-';
	}
	for (int i = 0; i <= 75; ++i)
	{
		coord.Y = i;
		coord.X = 0;
		hout = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hout, coord);
		std::cout << '-';
	}
	for (int i = 0; i <= 75; ++i)
	{
		coord.Y = i;
		coord.X = 75;
		hout = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hout, coord);
		std::cout << '-';
	}
	for (int i = 0; i <= 75; ++i)
	{
		coord.Y = 75;
		coord.X = i;
		hout = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hout, coord);
		std::cout << '-';
	}
}
int level = 200;
int main() {
	init();
	while(true){
		++t;
		if (t == 100)
		{
			HANDLE hout;
			COORD coord;
			coord.X = 80;
			coord.Y = 0;
			hout = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleCursorPosition(hout, coord);
			std::cout << std::endl << "速度增加咯";
			level = 150;
		}
		if (t == 300)
		{
			HANDLE hout;
			COORD coord;
			coord.X = 80;
			coord.Y = 0;
			hout = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleCursorPosition(hout, coord);
			std::cout<<std::endl << "速度又增加咯";
			level = 80;
		}
		if (t == 1000)
		{
			HANDLE hout;
			COORD coord;
			coord.X = 80;
			coord.Y = 0;
			hout = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleCursorPosition(hout, coord);
			std::cout << std::endl<<"你可太强了，最后一个级别";
			level = 80;
		}
		if (t % 35==0)//产生一个经验值，
		{
			int tx = rand() % 25;
			int ty = rand() % 25;
			S.marks.push_back({ tx,ty });
		}
		//if (t % 15) {
		//	if(S.marks.size())S.marks.pop_back();
		//}
		int keyboard = -1;
		if (_kbhit())
		{
			keyboard = _getch();
			S.changedir(keyboard);
		}
		//system("cls");改成只清除蛇
		S.cls();
		if(!run())break;
		Sleep(level);
	}
	return 0;
}
