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
/*Advanced PVP*/

#if defined(__BL_ADVANCED_DUEL__)
CAdvancedPVP::CAdvancedPVP(CPVP& v, LPCHARACTER ch_1, LPCHARACTER ch_2)
	: CPVP{ v }
{
	//Get Classes
	const CExchange* m_Exhange_1 = ch_1->GetExchange();
	const CExchange* m_Exhange_2 = ch_2->GetExchange();
	if (m_Exhange_1 == nullptr || m_Exhange_2 == nullptr)
	{
		sys_err("CAdvancedPVP, Exchange is null pointer.");
		return;
	}

	//Get Item Vectors
	auto vItem_1 = m_Exhange_1->GetItemVector();
	auto vItem_2 = m_Exhange_2->GetItemVector();
	vDuelItems.reserve(vItem_1.size() + vItem_2.size());

	//Merge Vectors
	vDuelItems.insert(vDuelItems.end(), std::make_move_iterator(vItem_1.begin()), std::make_move_iterator(vItem_1.end()));
	vDuelItems.insert(vDuelItems.end(), std::make_move_iterator(vItem_2.begin()), std::make_move_iterator(vItem_2.end()));

	//Remove Items From Characters
	for (LPITEM Item : vDuelItems)
		if (Item != nullptr)
			Item->RemoveFromCharacter();

	//Get Money
	const long lMoney_1 = m_Exhange_1->GetGold();
	const long lMoney_2 = m_Exhange_2->GetGold();
	lGold = lMoney_1 + lMoney_2; // Safe For Default Limit

	//Remove Money From Characters
	ch_1->PointChange(POINT_GOLD, -lMoney_1);
	ch_2->PointChange(POINT_GOLD, -lMoney_2);

	//Agree
	for (std::uint8_t i = 0; i < 2; i++)
		m_players[i].bAgree = true;

	//Set Flag (m_Exhange_1 & m_Exhange_2 flags are same)
	uFlag = m_Exhange_1->GetAdvancedDuelFlag();

	//Mount
	if (IsForbidden(CAdvancedPVP::EFLAG::Mount))
	{
		if (ch_1->GetMountVnum())
			ch_1->StopRiding();

		if (ch_2->GetMountVnum())
			ch_2->StopRiding();
	}
}

CAdvancedPVP::~CAdvancedPVP()
{
	if (vDuelItems.empty())
		return;

	// Say 'good bye' to items
	for (LPITEM Item : vDuelItems)
		if (Item != nullptr)
			ITEM_MANAGER::Instance().DestroyItem(Item);
}

void CAdvancedPVP::Win(DWORD dwPID)
{
	LPCHARACTER chWinner = CHARACTER_MANAGER::instance().FindByPID(dwPID);
	if (chWinner == nullptr)
		return;

	//Give All Items To Winner Player
	for (LPITEM Item : vDuelItems)
	{
		if (Item == nullptr)
			continue;

		Item->SetExchanging(false); // Important
		chWinner->AutoGiveItem(Item, true); // true: Long Ownership
	}

	// Don't let 'Destructor' to delete items.
	vDuelItems.clear();

	//Give All Money To Winner Player
	chWinner->GiveGold(lGold);

	//Info Message For Winner Player
	chWinner->ChatPacket(CHAT_TYPE_INFO, "[ADVANCED DUEL] Congratulation, you won!");

	//Win Effect
	chWinner->EffectPacket(SE_ADVANCED_PVP_KILL);

	// Clear Target etc.
	Packet(true);
}

CAdvancedPVP* CPVPManager::GetAdvancedPVP(LPCHARACTER pkChr) const
{
	if (pkChr == nullptr)
		return nullptr;

	auto it = m_map_pkPVPSetByID.find(pkChr->GetPlayerID());
	if (it == m_map_pkPVPSetByID.end())
		return false;

	for (CPVP* pkPVP : it->second)
	{
		CAdvancedPVP* aPVP = dynamic_cast<CAdvancedPVP*>(pkPVP);
		if (aPVP)
			return aPVP;
	}

	return nullptr;
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
