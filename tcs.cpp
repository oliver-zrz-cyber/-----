/*
������Ҫ֪�������ͷ�����
Ȼ�������Ҫ�Լ����ߣ�
Ҫ֪��ײǽ������ײ���Լ�
Ҫ֪�������µĶ�����
Ҫ��һ��ǰ�����ٶȣ�
Ҫ��һ���ٶȵı仯��
��Ҫ���ϵ�print��
����Ҫ���ϵ������Ļ
Ҫ���Ըı��ߵķ���
Ҫ�и���ʼ�Ĵ�С
��Ҫ��һЩ����Ķ���
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
			std::cout << std::endl << "�ٶ����ӿ�";
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
			std::cout<<std::endl << "�ٶ������ӿ�";
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
			std::cout << std::endl<<"���̫ǿ�ˣ����һ������";
			level = 80;
		}
		if (t % 35==0)//����һ������ֵ��
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
		//system("cls");�ĳ�ֻ�����
		S.cls();
		if(!run())break;
		Sleep(level);
	}
	return 0;
}
