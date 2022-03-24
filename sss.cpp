#include "sss.h"
#include<iostream>
#include<windows.h>
sneak::sneak()
{
	vel = 1;
	rear = 3;
	for (int i = rear-1; i >= 0; --i)queue[i] = { i+1,1 };
	dir = 4;
}

bool sneak::is_eat()//暂时被吃了不会消失
{
	for (std::vector<PII>::iterator it = marks.begin();it!=marks.end();++it)
	{
		if (*it == queue[0])
		{
			marks.erase(it);
			return 1;
		}
	}
	return 0;
}
bool sneak::is_hit_wall()
{
	auto pos = queue[0];
	if (pos.first >= 75 || pos.second >= 75 || pos.first <= 0 || pos.second <= 0)return 1;
	return 0;
}
bool sneak::is_hit_myself()
{
	auto pos = queue[0];
	for (int i = 1; i < rear; ++i)if (pos == queue[i])return 1;
	return 0;
}
bool sneak::is_over()
{
	if (is_hit_wall() || is_hit_myself())return 1;
	return 0;
}

void sneak::changedir(int k)
{
	if (k == 87 + 32)dir = 1;
	else if (k == 115)dir = 2;
	else if (k == 65 + 32) dir = 3;
	else if (k == 100) dir = 4;
}

void sneak::renew()
{	

	auto t = queue[0];
	if (dir == 1)t.first -= 1;
	else if (dir == 2)t.first += 1;
	else if (dir == 3)t.second -= 1;
	else if (dir == 4)t.second += 1;
	if (is_eat())
	{
		for (int i = rear - 1; i >=0; --i)
			queue[i + 1] = queue[i];
		++rear;
		queue[0] = t;
	}
	else
	{
		for (int i = rear - 1; i > 0; --i) queue[i] = queue[i - 1];
		queue[0] = t;
	}
}

void sneak::ppp()
{
	HANDLE hout;
	COORD coord;
	for (int i=0;i<rear;++i)
	{
		auto t = queue[i];
		coord.Y= t.first;
		coord.X = t.second;
		hout = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hout, coord);
		std::cout << '@';
	}
	
}

void sneak::cls()
{
	HANDLE hout;
	COORD coord;
	auto t = queue[rear - 1];
	coord.Y = t.first;
	coord.X = t.second;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hout, coord);
	std::cout <<' ';
}