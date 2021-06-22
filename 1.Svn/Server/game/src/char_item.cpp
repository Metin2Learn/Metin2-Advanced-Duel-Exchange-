//Find in bool CHARACTER::UseItemEx(LPITEM item, TItemPos DestCell)
	if ( CArenaManager::instance().IsLimitedItem( GetMapIndex(), item->GetVnum() ) == true )
	{
		ChatPacket(CHAT_TYPE_INFO, LC_TEXT("대련 중에는 이용할 수 없는 물품입니다."));
		return false;
	}

///Add
#if defined(__BL_ADVANCED_DUEL__)
	{
		const CAdvancedPVP* CPVP = CPVPManager::instance().GetAdvancedPVP(this);
		if (CPVP && CPVP->IsForbidden(CAdvancedPVP::EFLAG::Potion))
		{
			switch (item->GetVnum())
			{
			case ITEM_AUTO_HP_RECOVERY_S:
			case ITEM_AUTO_HP_RECOVERY_M:
			case ITEM_AUTO_HP_RECOVERY_L:
			case ITEM_AUTO_HP_RECOVERY_X:
			case REWARD_BOX_ITEM_AUTO_HP_RECOVERY_S:
			case REWARD_BOX_ITEM_AUTO_HP_RECOVERY_XS:
			case 27001:
			case 27002:
			case 27003:
			case 27051:
				ChatPacket(CHAT_TYPE_INFO, "[ADVANCED DUEL] You can not use HP Potion!");
				return false;
			}
		}
	}
#endif

//Find in bool CHARACTER::UnequipItem(LPITEM item)
	if (false == CanUnequipNow(item))
		return false;
	
///Add
#if defined(__BL_ADVANCED_DUEL__)
	{
		const CAdvancedPVP* CPVP = CPVPManager::instance().GetAdvancedPVP(this);
		if (CPVP && CPVP->IsForbidden(CAdvancedPVP::EFLAG::Equip_Change))
		{
			ChatPacket(CHAT_TYPE_INFO, "[ADVANCED DUEL] You can not change equip!");
			return false;
		}
	}
#endif

//Find in bool CHARACTER::EquipItem(LPITEM item, int iCandidateCell)
	if (item->IsExchanging())
		return false;
	
///Add
#if defined(__BL_ADVANCED_DUEL__)
	{
		const CAdvancedPVP* CPVP = CPVPManager::instance().GetAdvancedPVP(this);
		if (CPVP && CPVP->IsForbidden(CAdvancedPVP::EFLAG::Equip_Change))
		{
			ChatPacket(CHAT_TYPE_INFO, "[ADVANCED DUEL] You can not change equip!");
			return false;
		}
	}
#endif

//Find in void CHARACTER::AutoRecoveryItemProcess(const EAffectTypes type)
			if (!CArenaManager::instance().IsArenaMap(GetMapIndex()))
				
///Change
#if defined(__BL_ADVANCED_DUEL__)
			const CAdvancedPVP* CPVP = CPVPManager::instance().GetAdvancedPVP(this);
			if ((CPVP && CPVP->IsForbidden(CAdvancedPVP::EFLAG::Potion) && AFFECT_AUTO_HP_RECOVERY == type) == false
				&& !CArenaManager::instance().IsArenaMap(GetMapIndex()))
#else
			if (!CArenaManager::instance().IsArenaMap(GetMapIndex()))
#endif