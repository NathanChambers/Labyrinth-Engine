//--------------------------------------------------------------------------------//
//
// \author      Conan H. Bourke
// \date        13/01/2012
// \brief		A minimal abstract application wrapper.
//
//--------------------------------------------------------------------------------//
#ifndef __APPBASE_H_
#define __APPBASE_H_
//--------------------------------------------------------------------------------//

class AppBase
{
	enum FLAGS
	{
		FLAGS_CREATED	= (1<<0),
		FLAGS_DESTROYED	= (1<<1),
	};

public:

	AppBase();
	virtual ~AppBase();

	static AppBase* GetSingleton()	{	return sm_pSingleton;	}

	bool	Create(const char* a_sCmdLine);

	void	Execute();

	void	Destroy();

	bool	IsCreated();

protected:

	virtual bool	OnCreate(const char* a_sCmdLine) = 0;
	virtual bool	OnUpdate() = 0;
	virtual void	OnDestroy() = 0;
	virtual void	OnRender() = 0;

private:

	// Application flags (created/destroyed) add your own if desired
	unsigned int			m_uiFlags;
	
	// Singleton handle to the Application instance
	static AppBase*			sm_pSingleton;
};

//--------------------------------------------------------------------------------//
#endif //__APPBASE_H_
//--------------------------------------------------------------------------------//