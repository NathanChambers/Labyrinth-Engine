//--------------------------------------------------------------------------------//
//
// \author		Nathan M. Chambers
// \date        29/02/2012
// \brief		Simple lcMouse Wrapper
//
//--------------------------------------------------------------------------------//
#ifndef __LCMOUSE_H_
#define __LCMOUSE_H_
//--------------------------------------------------------------------------------//

class lcMouse
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

	static lcMouse* Create();
	static lcMouse* Get();
	void Release();

	void Update();
	void GetPosition(int& a_iX,int& a_iY);
	void GetPositionToScreen(int& a_iX,int& a_iY);
	void GetDeltaPosition(int& a_iX,int& a_iY);

	void Show(bool a_bShow);
	void LockToWindow(bool a_bLocked);

	static bool IsButtonDown(eBUTTONS a_uiButton);
	static bool IsButtonUp(eBUTTONS a_uiButton);
	static bool IsButtonPressed(eBUTTONS a_uiButton);
	static bool IsButtonReleased(eBUTTONS a_uiButton);

	static bool IsScrollingUp();
	static bool IsScrollingDown();

private:
	lcMouse();
	~lcMouse();

	static lcMouse* m_pSingleton;

	int m_iXCurr,m_iYCurr;
	int m_iXPrev,m_iYPrev;

	short m_uiScrollVal;

	int* m_pVKMap;
	bool m_bButtonCurr[3];
	bool m_bButtonPrev[3];

	bool m_bScrollingUp;
	bool m_bScrollingDown;

	bool m_bScreenLocked;
};

//--------------------------------------------------------------------------------//
#endif //__MOUSE_H_
//--------------------------------------------------------------------------------//