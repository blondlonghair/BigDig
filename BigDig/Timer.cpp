#include "DXUT.h"
#include "Timer.h"

Timer::Timer()
{
}

Timer::~Timer()
{
}

bool Timer::Update()
{
	curtime += dt;
	if (curtime > cooltime) {
		curtime = 0.f;
		return TRUE;
	}
	return FALSE;
}
