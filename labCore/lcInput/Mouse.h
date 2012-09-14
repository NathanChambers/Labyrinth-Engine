//--------------------------------------------------------------------------------//
//
// \author		Nathan M. Chambers
// \date        29/02/2012
// \brief		Simple Mouse Wrapper
//
//--------------------------------------------------------------------------------//
#ifndef __MOUSE_H_
#define __MOUSE_H_
//--------------------------------------------------------------------------------//
#include "../lcCore/Window.h"
//--------------------------------------------------------------------------------//

class Mouse
{
	friend class Window;
public:
	enum eBUTTONS
	{
		LEFT,
		RIGHT,
		MIDDLE,
		BUTTON_COUNT,
	};

	static Mouse* Create();
	static Mouse* Get();
	void Release();

	void Update();
	void GetPosition(int& a_iX,int& a_iY);
	void GetPositionToScreen(int& a_iX,int& a_iY);
	void GetDeltaPosition(int& a_iX,int& a_iY);

	void Show(bool a_bShow);

	bool IsButtonDown(eBUTTONS a_uiButton);
	bool IsButtonUp(eBUTTONS a_uiButton);
	bool IsButtonPressed(eBUTTONS a_uiButton);
	bool IsButtonReleased(eBUTTONS a_uiButton);

	bool IsScrollingUp();
	bool IsScrollingDown();

private:
	Mouse();
	~Mouse();

	static Mouse* m_pSingleton;

	int m_iXCurr,m_iYCurr;
	int m_iXPrev,m_iYPrev;

	short m_uiScrollVal;

	int* m_pVKMap;
	bool m_bButtonCurr[3];
	bool m_bButtonPrev[3];

	bool m_bScrollingUp;
	bool m_bScrollingDown;
};

//--------------------------------------------------------------------------------//
#endif //__MOUSE_H_
//--------------------------------------------------------------------------------//