#ifndef __LCTIMERS_H_
#define __LCTIMERS_H_

#include <Windows.h>

class lcTime
{
public:
	static lcTime* Create();
	static lcTime* Get();
	void Release();

	void Update();

	static double DeltaTime();
	static double CurrentTime();

private:
	static lcTime* m_pSingleton;

	lcTime();
	~lcTime();

	LARGE_INTEGER m_liPrev;
	double m_dDelta;
	double m_dCurrent;
};


#endif//__TIMERS_H_