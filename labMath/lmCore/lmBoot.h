#ifndef __LAB_BOOT_H_
#define __LAB_BOOT_H_

namespace Labyrinth
{
	class lmBoot
	{
	public:
		lmBoot();

	private:
		static lmBoot m_kBoot;
		void Construct();
	};
};

#endif//__LAB_BOOT_H_