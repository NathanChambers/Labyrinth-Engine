//#ifndef __LCMEMTRACKER_H_
//#define __LCMEMTRACKER_H_
//
//#include "lcUtilities.h"
//#include <map>
//
//void* operator new (unsigned int a_uiSize);
//void operator delete (void* a_pMem);
//
//class lcMemTracker
//{
//public:
//	static lcMemTracker* Create();
//	void Release();
//
//	static void AddMemory(void* address,unsigned int size);
//	static void RemoveMemory(void* address);
//	static void DumpMemoryData();
//
//private:
//	static lcMemTracker* m_pkSingleton;
//
//	lcMemTracker();
//	~lcMemTracker();
//
//	std::map<void*,unsigned int> m_akMemory;
//	unsigned int m_uiMemAllocations;
//};
//
//#endif//__LCMEMTRACKER_H_