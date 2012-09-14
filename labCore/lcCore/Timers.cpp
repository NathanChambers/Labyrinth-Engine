#include "Timers.h"

GameTime* GameTime::m_pSingleton = 0;

GameTime::GameTime()
{
	m_liPrev.QuadPart = 0;
}

GameTime::~GameTime()
{

}

GameTime* GameTime::Create()
{
	if(!m_pSingleton)
		m_pSingleton = new GameTime;
	return m_pSingleton;
}

GameTime* GameTime::Get()
{
	return m_pSingleton;
}

void GameTime::Release()
{
	if(m_pSingleton)
		delete m_pSingleton;
}

void GameTime::Update()
{
	LARGE_INTEGER liFreq;
	QueryPerformanceFrequency(&liFreq);

	LARGE_INTEGER liCurr;
	QueryPerformanceCounter(&liCurr);

	if(m_liPrev.QuadPart)
	{
		m_dDelta = (double)(liCurr.QuadPart - m_liPrev.QuadPart) / liFreq.QuadPart;
		if(m_dDelta > 1)
		{
			m_dDelta = 1;
		}
	}
	else
	{
		m_dDelta = 0;
	}

	m_liPrev = liCurr;
}

double GameTime::GetTimeElapsed()
{
	return m_pSingleton->m_dDelta;
}