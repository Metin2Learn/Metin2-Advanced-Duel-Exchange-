//Find
	PyModule_AddIntConstant(poModule, "EMOTION_SLAP",			EMOTION_SLAP);
	
///Add
#if defined(__BL_ADVANCED_DUEL__)
	PyModule_AddIntConstant(poModule, "ADVANCED_DUEL_FLAG_ACTIVE",	(1 << 0));
	PyModule_AddIntConstant(poModule, "ADVANCED_DUEL_POTION",		(1 << 1));
	PyModule_AddIntConstant(poModule, "ADVANCED_DUEL_EQUIP_CHANGE",	(1 << 2));
	PyModule_AddIntConstant(poModule, "ADVANCED_DUEL_MOUNT",		(1 << 3));
#endif