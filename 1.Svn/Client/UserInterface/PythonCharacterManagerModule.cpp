//Find
	PyModule_AddIntConstant(poModule, "EFFECT_LOVE_PENDANT_EQUIP",		CInstanceBase::EFFECT_LOVE_PENDANT_EQUIP);
	
///Add
#if defined(__BL_ADVANCED_DUEL__)
	PyModule_AddIntConstant(poModule, "EFFECT_ADVANCED_PVP_START",		CInstanceBase::EFFECT_ADVANCED_PVP_START);
	PyModule_AddIntConstant(poModule, "EFFECT_ADVANCED_PVP_START_2",	CInstanceBase::EFFECT_ADVANCED_PVP_START_2);
	PyModule_AddIntConstant(poModule, "EFFECT_ADVANCED_PVP_WIN",		CInstanceBase::EFFECT_ADVANCED_PVP_WIN);
#endif