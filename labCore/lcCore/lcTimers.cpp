#include "lcTimers.h"

lcTime* lcTime::m_pSingleton = 0;

lcTime::lcTime()
{
	m_liPrev.QuadPart = 0;
}

lcTime::~lcTime()
{

}

lcTime* lcTime::Create()
{
	if(!m_pSingleton)
		m_pSingleton = new lcTime;
	return m_pSingleton;
}

lcTime* lcTime::Get()
{
	return m_pSingleton;
}

void lcTime::Release()
{
	if(m_pSingleton)
		delete m_pSingleton;
}

void lcTime::Update()
{
	LARGE_INTEGER liFreq;
	QueryPerformanceFrequency(&liFreq);

	LARGE_INTEGER liCurr;
	QueryPerformanceCounter(&liCurr);

	if(m_liPrev.QuadPart)
	{
		m_fDelta = (float)(liCurr.QuadPart - m_liPrev.QuadPart) / liFreq.QuadPart;
		if(m_fDelta > 1)
		{
			m_fDelta = 1;
		}
		else
		{
			m_fElapsed += m_fDelta;
		}
	}
	else
	{
		m_fDelta = 0;
	}

	m_liPrev = liCurr;
}

float lcTime::DeltaTime()
{
	return m_pSingleton->m_fDelta;
}

float lcTime::ElapsedTime()
{
	return m_pSingleton->m_fElapsed;
}