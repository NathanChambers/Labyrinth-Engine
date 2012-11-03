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

	static float DeltaTime();
	static float ElapsedTime();

private:
	static lcTime* m_pSingleton;

	lcTime();
	~lcTime();

	LARGE_INTEGER m_liPrev;
	float m_fDelta;
	float m_fElapsed;
};


#endif//__TIMERS_H_