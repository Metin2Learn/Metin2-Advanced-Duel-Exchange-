//Find
		case EXCHANGE_SUBHEADER_CG_CANCEL:	// arg1 == not used
			if (ch->GetExchange())
				ch->GetExchange()->Cancel();
			break;

///Add
#if defined(__BL_ADVANCED_DUEL__)
		case EXCHANGE_SUBHEADER_CG_DUEL_SETTINGS:	// arg1 == flag
			if (ch->GetExchange())
				ch->GetExchange()->SetAdvancedDuelFlag(pinfo->arg1);
			break;
#endif