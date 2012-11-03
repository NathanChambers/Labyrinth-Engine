#ifndef __LAB_BOOT_H_
#define __LAB_BOOT_H_

class lmBoot
{
public:
	lmBoot();
	void Reboot() const;

private:
	void Construct();
	static bool m_bBooted;
};

#endif//__LAB_BOOT_H_