//--------------------------------------------------------------------------------//
//
// \author		Nathan M. Chambers
// \date        29/02/2012
// \brief		Simple Keyboard Wrapper
//
//--------------------------------------------------------------------------------//
#ifndef __KEYBOARD_H_
#define __KEYBOARD_H_
//--------------------------------------------------------------------------------//

//--------------------------------------------------------------------------------//

class Keyboard
{
public:
	static Keyboard* Create();
	static Keyboard* Get();
	void Release();

	void Update();

	bool IsKeyDown(short a_oKey);
	bool IsKeyUp(short a_oKey);
	bool IsKeyPressed(short a_oKey);
	bool IsKeyReleased(short a_oKey);

private:
	Keyboard();
	~Keyboard();

	static Keyboard* m_pSingleton;

	bool m_uiKeysCurr[256];
	bool m_uiKeysPrev[256];
};

//--------------------------------------------------------------------------------//

//Number Keys
const short KEY_0				= 0x30;
const short KEY_1				= 0x31;
const short KEY_2				= 0x32;
const short KEY_3				= 0x33;
const short KEY_4				= 0x34;
const short KEY_5				= 0x35;
const short KEY_6				= 0x36;
const short KEY_7				= 0x37;
const short KEY_8				= 0x38;
const short KEY_9				= 0x39;

//--------------------------------------------------------------------------------//

//Letter Keys
const short KEY_A				= 0x41;
const short KEY_B				= 0x42;
const short KEY_C				= 0x43;
const short KEY_D				= 0x44;
const short KEY_E				= 0x45;
const short KEY_F				= 0x46;
const short KEY_G				= 0x47;
const short KEY_H				= 0x48;
const short KEY_I				= 0x49;
const short KEY_J				= 0x4A;
const short KEY_K				= 0x4B;
const short KEY_L				= 0x4C;
const short KEY_M				= 0x4D;
const short KEY_N				= 0x4E;
const short KEY_O				= 0x4F;
const short KEY_P				= 0x50;
const short KEY_Q				= 0x51;
const short KEY_R				= 0x52;
const short KEY_S				= 0x53;
const short KEY_T				= 0x54;
const short KEY_U				= 0x55;
const short KEY_V				= 0x56;
const short KEY_W				= 0x57;
const short KEY_X				= 0x58;
const short KEY_Y				= 0x59;
const short KEY_Z				= 0x5A;

//--------------------------------------------------------------------------------//

//Arrow Keys
const short KEY_LEFT			= 0x25;
const short KEY_UP				= 0x26;
const short KEY_RIGHT			= 0x27;
const short KEY_DOWN			= 0x28;

//--------------------------------------------------------------------------------//

//Function Keys
const short KEY_F1				= 0x70;
const short KEY_F2				= 0x71;
const short KEY_F3				= 0x72;
const short KEY_F4				= 0x73;
const short KEY_F5				= 0x74;
const short KEY_F6				= 0x75;
const short KEY_F7				= 0x76;
const short KEY_F8				= 0x77;
const short KEY_F9				= 0x78;
const short KEY_F10			= 0x79;
const short KEY_F11			= 0x7A;
const short KEY_F12			= 0x7B;

//--------------------------------------------------------------------------------//

//Numpad Keys
const short KEY_NUMPAD0		= 0x60;
const short KEY_NUMPAD1		= 0x61;
const short KEY_NUMPAD2		= 0x62;
const short KEY_NUMPAD3		= 0x63;
const short KEY_NUMPAD4		= 0x64;
const short KEY_NUMPAD5		= 0x65;
const short KEY_NUMPAD6		= 0x66;
const short KEY_NUMPAD7		= 0x67;
const short KEY_NUMPAD8		= 0x68;
const short KEY_NUMPAD9		= 0x69;

//--------------------------------------------------------------------------------//

//Control Keys
const short KEY_ESCAPE			= 0x1B;
const short KEY_TAB			= 0x09;
const short KEY_LSHIFT			= 0xA0;
const short KEY_LCTRL			= 0xA2;
const short KEY_LALT			= 0xA4;
const short KEY_SPACE			= 0x20;
const short KEY_RALT			= 0xA5;
const short KEY_RCTRL			= 0xA3;
const short KEY_RSHIFT			= 0xA1;
const short KEY_RETURN			= 0x0D;
const short KEY_BACKSPACE		= 0x08;

//--------------------------------------------------------------------------------//
#endif//__KEYBOARD_H_
//--------------------------------------------------------------------------------//