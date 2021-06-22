///Add
#if defined(__BL_ADVANCED_DUEL__)
#include "pvp.h"
#endif

//Find in bool CHARACTER::StartRiding()
	if (IsDead() == true)
	{
		...
	}
	
///Add
#if defined(__BL_ADVANCED_DUEL__)
	auto Advanced = CPVPManager::Instance().GetAdvancedPVP(this);
	if (Advanced && Advanced->IsForbidden(CAdvancedPVP::EFLAG::Mount))
	{
		ChatPacket(CHAT_TYPE_INFO, "[ADVANCED DUEL] You can not mount!");
		return false;
	}
#endif
