//Find
		case SE_EQUIP_LOVE_PENDANT:
			effect = CInstanceBase::EFFECT_LOVE_PENDANT_EQUIP;
			break;
			
///Add
#if defined(__BL_ADVANCED_DUEL__)
		case SE_ADVANCED_PVP_START:
			effect = CInstanceBase::EFFECT_ADVANCED_PVP_START;
			break;
		case SE_ADVANCED_PVP_START_2:
			effect = CInstanceBase::EFFECT_ADVANCED_PVP_START_2;
			break;
		case SE_ADVANCED_PVP_WIN:
			effect = CInstanceBase::EFFECT_ADVANCED_PVP_WIN;
			break;
#endif