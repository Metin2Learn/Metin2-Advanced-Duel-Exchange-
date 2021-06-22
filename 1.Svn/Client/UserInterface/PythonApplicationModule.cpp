//Find
#ifdef ENABLE_ENERGY_SYSTEM
	PyModule_AddIntConstant(poModule, "ENABLE_ENERGY_SYSTEM",	1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_ENERGY_SYSTEM",	0);
#endif

///Add
#if defined(__BL_ADVANCED_DUEL__)
	PyModule_AddIntConstant(poModule, "__BL_ADVANCED_DUEL__", true);
#else
	PyModule_AddIntConstant(poModule, "__BL_ADVANCED_DUEL__", false);
#endif