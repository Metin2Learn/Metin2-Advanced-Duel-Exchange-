#Find
    chrmgr.RegisterCacheEffect(chrmgr.EFFECT_LOVE_PENDANT_EQUIP, "", "d:/ymir work/effect/etc/buff/buff_item4.mse")

#Add
    if app.__BL_ADVANCED_DUEL__:
		chrmgr.RegisterCacheEffect(chrmgr.EFFECT_ADVANCED_PVP_START, "", 'd:/ymir work/effect/etc/pvp/pvp_open1.mse')
		chrmgr.RegisterCacheEffect(chrmgr.EFFECT_ADVANCED_PVP_START_2, "", 'd:/ymir work/effect/etc/pvp/pvp_open2.mse')
		chrmgr.RegisterCacheEffect(chrmgr.EFFECT_ADVANCED_PVP_WIN, "", 'd:/ymir work/effect/etc/pvp/kill.mse')