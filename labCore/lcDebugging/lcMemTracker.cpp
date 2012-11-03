//#include "lcMemTracker.h"
//#include "lcAssert.h"
//#include "lcUtilities.h"
//#include <stdlib.h>
//
//lcMemTracker* lcMemTracker::m_pkSingleton = nullptr;
//
//lcMemTracker::lcMemTracker()
//{
//	m_uiMemAllocations = 0;
//}
//
//lcMemTracker::~lcMemTracker()
//{
//
//}
//
//lcMemTracker* lcMemTracker::Create()
//{
//	if(m_pkSingleton == nullptr)
//		m_pkSingleton = new lcMemTracker();
//	return m_pkSingleton;
//}
//
//void lcMemTracker::Release()
//{
//	if(m_pkSingleton != nullptr)
//		delete m_pkSingleton;
//	m_pkSingleton = nullptr;
//}
//
//void lcMemTracker::AddMemory(void* a_pAddress,unsigned int a_uiMemSize)
//{
//	m_pkSingleton->m_akMemory[a_pAddress] = a_uiMemSize;
//	m_pkSingleton->m_uiMemAllocations++;
//}
//
//void lcMemTracker::RemoveMemory(void* a_pAddress)
//{
//	m_pkSingleton->m_akMemory.erase(a_pAddress);
//	m_pkSingleton->m_uiMemAllocations--;
//}
//
//void lcMemTracker::DumpMemoryData()
//{
//	for(auto pIter = m_pkSingleton->m_akMemory.begin();pIter != m_pkSingleton->m_akMemory.end();++pIter)
//	{
//		Utilities::Debug_ConsoleWrite("Address : %d  Size : %d bytes",pIter->first,pIter->second);
//	}
//}
//
//void* operator new (unsigned int a_uiSize)
//{
//	void* mem = calloc(1,a_uiSize);
//	if(mem == nullptr)
//		lcAssert("Error Alocating Memory : No Free Memory");
//
//	lcMemTracker::AddMemory(mem,a_uiSize);
//	return mem;
//}
//
//void operator delete (void* a_pMem)
//{
//	if(a_pMem != nullptr)
//	{
//		lcMemTracker::RemoveMemory(a_pMem);
//		free(a_pMem);
//	}
//}