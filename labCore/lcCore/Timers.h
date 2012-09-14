#ifndef __TIMERS_H_
#define __TIMERS_H_

#include <Windows.h>

class GameTime
{
public:
	static GameTime* Create();
	static GameTime* Get();
	void Release();

	void Update();

	static double GetTimeElapsed();

private:
	static GameTime* m_pSingleton;

	GameTime();
	~GameTime();

	LARGE_INTEGER m_liPrev;
	double m_dDelta;
};


#endif//__TIMERS_H_