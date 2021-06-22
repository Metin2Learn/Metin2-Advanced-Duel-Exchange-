//Find
	EXCHANGE_SUBHEADER_CG_CANCEL,			// arg1 == not used
	
///Add
#if defined(__BL_ADVANCED_DUEL__)
	EXCHANGE_SUBHEADER_CG_DUEL_SETTINGS,	// arg1 == flag
#endif

//Find
    EXCHANGE_SUBHEADER_GC_LESS_ELK,		// arg1 == not used
	
///Add
#if defined(__BL_ADVANCED_DUEL__)
	EXCHANGE_SUBHEADER_GC_DUEL_SETTINGS, // arg1 == flag
#endif

//Find
	SE_EQUIP_LOVE_PENDANT,
	
///Add
#if defined(__BL_ADVANCED_DUEL__)
	SE_ADVANCED_PVP_START,
	SE_ADVANCED_PVP_START_2,
	SE_ADVANCED_PVP_WIN,
#endif