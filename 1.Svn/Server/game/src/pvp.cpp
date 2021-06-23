///Add
#if defined(__BL_ADVANCED_DUEL__)
#include "exchange.h"
#include "item_manager.h"
#include "item.h"
#endif

//Find
DWORD CPVP::GetLastFightTime()
{
	...
}

///Add
#if defined(__BL_ADVANCED_DUEL__)
CAdvancedPVP::CAdvancedPVP(CPVP& v, LPCHARACTER ch_1, LPCHARACTER ch_2)
	: CPVP{ v }
{
	//Get Classes
	const CExchange* m_Exhange_1 = ch_1->GetExchange();
	const CExchange* m_Exhange_2 = ch_2->GetExchange();
	if (m_Exhange_1 == nullptr || m_Exhange_2 == nullptr) // maybe...
	{
		sys_err("CAdvancedPVP, Exchange is null pointer.");
		return;
	}

	//Set Flag (m_Exhange_1 & m_Exhange_2 flags are same)
	uFlag = m_Exhange_1->GetAdvancedDuelFlag();

	//Player Stuff
	const bool bMountRestrict = IsForbidden(CAdvancedPVP::EFLAG::Mount);
	arrPlayerStuff[0] = std::make_unique< SPlayerStuff >(ch_1, m_Exhange_1->GetItemVector(), m_Exhange_1->GetGold(), bMountRestrict);
	arrPlayerStuff[1] = std::make_unique< SPlayerStuff >(ch_2, m_Exhange_2->GetItemVector(), m_Exhange_2->GetGold(), bMountRestrict);

	//Agree
	for (std::uint8_t i = 0; i < 2; i++)
		m_players[i].bAgree = true;
}

void CAdvancedPVP::Win(DWORD dwPID)
{
	LPCHARACTER ch = CHARACTER_MANAGER::instance().FindByPID(dwPID);
	if (ch == nullptr)
		return;

	//Give All Stuff To Winner
	for (const auto& x : arrPlayerStuff)
		x->Win(ch);
	
	//Info Message
	ch->ChatPacket(CHAT_TYPE_INFO, "[ADVANCED DUEL] Congratulation, you won!");

	//Win Effect
	ch->EffectPacket(SE_ADVANCED_PVP_KILL);

	// Clear Target etc.
	Packet(true);
}

CAdvancedPVP* CPVPManager::GetAdvancedPVP(LPCHARACTER pkChr) const
{
	if (pkChr == nullptr)
		return nullptr;

	auto it = m_map_pkPVPSetByID.find(pkChr->GetPlayerID());
	if (it == m_map_pkPVPSetByID.end())
		return nullptr;

	for (CPVP* pkPVP : it->second)
	{
		CAdvancedPVP* aPVP = dynamic_cast<CAdvancedPVP*>(pkPVP);
		if (aPVP)
			return aPVP;
	}

	return nullptr;
}

CAdvancedPVP::SPlayerStuff::SPlayerStuff(LPCHARACTER m_ch, std::vector<LPITEM>&& m_DuelItems, long m_Gold, bool bMountRestrict)
	: ch(m_ch), vDuelItems(std::move(m_DuelItems)), lGold(m_Gold)
{
	for (LPITEM Item : vDuelItems)
	{
		if (Item == nullptr)
			continue;

		Item->SetExchanging(false); // Important
		Item->RemoveFromCharacter();
	}

	ch->PointChange(POINT_GOLD, -lGold);

	if (bMountRestrict && ch->GetMountVnum())
		ch->StopRiding();
}

void CAdvancedPVP::SPlayerStuff::Win(LPCHARACTER ch) const
{
	if (ch == nullptr)
		return;

	//Give All Items To Winner Player
	for (LPITEM Item : vDuelItems)
		if (Item)
			ch->AutoGiveItem(Item, true); // true: Long Ownership

	//Give All Money To Winner Player
	ch->GiveGold(lGold);
}

void CAdvancedPVP::SPlayerStuff::GiveMyStuffBack() const // Currently Not Using
{
	Win(ch); // Give Stuff The Owner
}
#endif

/*PVP MANAGER*/

//Find
void CPVPManager::Insert(LPCHARACTER pkChr, LPCHARACTER pkVictim)

///Change
#if defined(__BL_ADVANCED_DUEL__)
void CPVPManager::Insert(LPCHARACTER pkChr, LPCHARACTER pkVictim, bool bIsAdvanced)
#else
void CPVPManager::Insert(LPCHARACTER pkChr, LPCHARACTER pkVictim)
#endif

//Find
	if ((pkPVP = Find(kPVP.m_dwCRC)))
		
///Change
#if defined(__BL_ADVANCED_DUEL__)
	if ((pkPVP = Find(kPVP.m_dwCRC)) && bIsAdvanced == false) // pkPVP can be not nullptr, so we will delete it below
#else
	if ((pkPVP = Find(kPVP.m_dwCRC)))
#endif

//Find
	pkPVP = M2_NEW CPVP(kPVP);

///Change
#if defined(__BL_ADVANCED_DUEL__)
	if (pkPVP != nullptr)
		Delete(pkPVP); // Delete old - not CAdvancedPVP - duel data

	pkPVP = bIsAdvanced ? new CAdvancedPVP(kPVP, pkChr, pkVictim) : new CPVP(kPVP);
#else
	pkPVP = M2_NEW CPVP(kPVP);
#endif

//Find
	pkPVP->Packet();

///Add
#if defined(__BL_ADVANCED_DUEL__)
	if (bIsAdvanced)
	{
		pkChr->EffectPacket(SE_ADVANCED_PVP_START);
		pkVictim->EffectPacket(SE_ADVANCED_PVP_START_2);
		pkVictim->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("%s님과의 대결 시작!"), pkChr->GetName());
		pkChr->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("%s님과의 대결 시작!"), pkVictim->GetName());
		return;
	}
#endif

//Find in void CPVPManager::Disconnect(LPCHARACTER pkChr)
	//ConnectEx(pkChr, true);
	
///Add
#if defined(__BL_ADVANCED_DUEL__)
	auto Advanced = GetAdvancedPVP(pkChr);
	if (Advanced)
	{
		const bool bSlot = Advanced->m_players[0].dwPID == pkChr->GetPlayerID() ? 1 : 0; // select other player's slot
		Advanced->Win(Advanced->m_players[bSlot].dwPID);
		Delete(Advanced); // End Of Story
	}
#endif

//Find in bool CPVPManager::Dead(LPCHARACTER pkChr, DWORD dwKillerPID)
	bool found = false;
	
///Add
#if defined(__BL_ADVANCED_DUEL__)
	CPVP* pGarbage = nullptr;
#endif

//Find
				pkPVP->Win(dwKillerPID);
				
///Add
#if defined(__BL_ADVANCED_DUEL__)
				if (dynamic_cast<CAdvancedPVP*>(pkPVP))
					pGarbage = pkPVP;
#endif

//Find
	return found;
	
///Add Above
#if defined(__BL_ADVANCED_DUEL__)
	if (pGarbage != nullptr)
		Delete(pGarbage);
#endif
