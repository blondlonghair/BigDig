#pragma once
#include "CSingleton.h"
class Timer
{
public:
	Timer();
	~Timer();

	bool Update();
	float curtime = 0;
	float cooltime = 0;

	void setTimer(float vel) { cooltime = vel; }
};

