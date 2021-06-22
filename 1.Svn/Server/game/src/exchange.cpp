///Add
#if defined(__BL_ADVANCED_DUEL__)
#include "pvp.h"
#endif

//Find
	m_lGold = 0;
	
///Add
#if defined(__BL_ADVANCED_DUEL__)
	uPVPFlag = 0;
#endif

//Find
CExchange::~CExchange()
{
	...
}

///Add
#if defined(__BL_ADVANCED_DUEL__)
std::uint8_t CExchange::GetAdvancedDuelFlag() const 
{ 
	return uPVPFlag; 
}

long CExchange::GetGold() const
{
	return m_lGold;
}

std::vector<LPITEM>	CExchange::GetItemVector() const
{
	std::vector<LPITEM> vec(m_apItems, m_apItems + EXCHANGE_ITEM_MAX_NUM);
	return vec;
}

void CExchange::SetAdvancedDuelFlag(std::uint8_t uFlag)
{
	if (m_bAccept == false && GetCompany()->GetAcceptStatus() == false)
		uPVPFlag = uFlag;
	
	exchange_packet(GetOwner(), EXCHANGE_SUBHEADER_GC_DUEL_SETTINGS, true, uPVPFlag, NPOS, 0);
	exchange_packet(GetCompany()->GetOwner(), EXCHANGE_SUBHEADER_GC_DUEL_SETTINGS, false, uPVPFlag, NPOS, 0);
}
#endif

//Find
		if (db_clientdesc->GetSocket() == INVALID_SOCKET)
		{
			sys_err("Cannot use exchange feature while DB cache connection is dead.");
			victim->ChatPacket(CHAT_TYPE_INFO, "Unknown error");
			GetOwner()->ChatPacket(CHAT_TYPE_INFO, "Unknown error");
			goto EXCHANGE_END;
		}
		
///Add
#if defined(__BL_ADVANCED_DUEL__)
		if (GetAdvancedDuelFlag() != GetCompany()->GetAdvancedDuelFlag()) // Settings must be same.
		{
			GetOwner()->ChatPacket(CHAT_TYPE_INFO, "[ADVANCED DUEL] Settings must be same.");
			victim->ChatPacket(CHAT_TYPE_INFO, "[ADVANCED DUEL] Settings must be same.");
			goto EXCHANGE_END;
		}
		if (CAdvancedPVP::IsForbidden(CAdvancedPVP::EFLAG::AdvancedDuel, GetAdvancedDuelFlag()))
		{
			if (GetOwner()->IsDead() || victim->IsDead())
			{
				victim->ChatPacket(CHAT_TYPE_INFO, "[ADVANCED DUEL] cannot start when there is a dead player.");
				GetOwner()->ChatPacket(CHAT_TYPE_INFO, "[ADVANCED DUEL] cannot start when there is a dead player.");
				goto EXCHANGE_END;
			}
			if (CPVPManager::Instance().GetAdvancedPVP(GetOwner()) || CPVPManager::Instance().GetAdvancedPVP(victim))
			{
				victim->ChatPacket(CHAT_TYPE_INFO, "[ADVANCED DUEL] cannot start if the player is already in a advanced duel.");
				GetOwner()->ChatPacket(CHAT_TYPE_INFO, "[ADVANCED DUEL] cannot start if the player is already in a advanced duel.");
				goto EXCHANGE_END;
			}
			CPVPManager::Instance().Insert(GetOwner(), victim, true);
			goto EXCHANGE_END;
		}
#endif