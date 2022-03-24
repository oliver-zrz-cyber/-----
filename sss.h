#pragma once
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
typedef std::pair<int, int>PII;
const int N = 1000;
class sneak
{
public:

	sneak();
	bool is_eat();//吃了怎么没变化
	bool is_hit_wall();
	bool is_hit_myself();
	bool is_over();
	void renew();
	void changedir(int k);
	std::vector<PII> marks;
	void ppp();
	void cls();int rear;
private:
	int vel;
	PII queue[N];
	int dir;
};