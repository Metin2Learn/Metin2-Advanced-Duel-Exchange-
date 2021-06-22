#Add
import app

#Find
class ExchangeDialog(ui.ScriptWindow):

#Add
	if app.__BL_ADVANCED_DUEL__:
		ADVANCED_DUEL_SELF = 0
		ADVANCED_DUEL_TARGET = 1

#Find
		self.yStart = 0

#Add
		if app.__BL_ADVANCED_DUEL__:
			self.AdvancedDuelToolTipList = [localeInfo.ADVANCED_DUEL_1, localeInfo.ADVANCED_DUEL_2, localeInfo.ADVANCED_DUEL_3, localeInfo.ADVANCED_DUEL_4, localeInfo.ADVANCED_DUEL_5]

#Find
		self.GetChild("TitleBar").SetCloseEvent(net.SendExchangeExitPacket)

#Add
		if app.__BL_ADVANCED_DUEL__:
			self.AdvancedDuelButtonList = [[] for _ in range(2)]
			for button in ('advanced_duel', 'potion_block', 'equip_block', 'mount_block'):
				self.AdvancedDuelButtonList[ExchangeDialog.ADVANCED_DUEL_SELF].append(self.GetChild("self_{}".format(button)))
				self.AdvancedDuelButtonList[ExchangeDialog.ADVANCED_DUEL_TARGET].append(self.GetChild("target_{}".format(button)))

			for button in self.AdvancedDuelButtonList[ExchangeDialog.ADVANCED_DUEL_TARGET]:
				button.Disable()

			for index, button in enumerate(self.AdvancedDuelButtonList[ExchangeDialog.ADVANCED_DUEL_SELF]):
				button.SetToggleUpEvent(lambda arg = (1 << index): self.__OnClickAdvancedDuelButton(arg))
				button.SetToggleDownEvent(lambda arg = (1 << index): self.__OnClickAdvancedDuelButton(arg))

			self.AdvancedDuelToolTip = self.__CreateGameTypeToolTip(localeInfo.ADVANCED_DUEL_TITLE, self.AdvancedDuelToolTipList)
			self.AdvancedDuelToolTip.SetTop()
			self.AdvancedDuelTIpButton = self.GetChild("AdvancedDuelToolTIpButton")
			self.AdvancedDuelTIpButton.SetToolTipWindow(self.AdvancedDuelToolTip)

#Find
	def SetItemToolTip(self, tooltipItem):
		self.tooltipItem = tooltipItem

#Add
	if app.__BL_ADVANCED_DUEL__:
		def __CreateGameTypeToolTip(self, title, descList):
			import uiToolTip
			toolTip = uiToolTip.ToolTip()
			toolTip.SetTitle(title)
			toolTip.AppendSpace(5)

			for desc in descList:
				toolTip.AutoAppendTextLine(desc)

			toolTip.AlignHorizonalCenter()
			toolTip.SetTop()
			return toolTip
		
		def __OnClickAdvancedDuelButton(self, idx):
			flag = exchange.GetDuelFlagFromSelf() ^ idx
			if not flag & player.ADVANCED_DUEL_FLAG_ACTIVE:
				flag = 0 
			net.SendExchangeDuelFlagPacket(flag)
        
        def RefreshAdvancedDuel(self):
			ADVANCED_DUEL_FLAG_TUPLE = (exchange.GetDuelFlagFromSelf, exchange.GetDuelFlagFromTarget)
			for key, value in enumerate(self.AdvancedDuelButtonList):
				for index, button in enumerate(value):
					if ADVANCED_DUEL_FLAG_TUPLE[key]() & (1 << index):
						button.Down()
					else:
						button.SetUp()

#Find
		self.AcceptButton = 0

#Add
		if app.__BL_ADVANCED_DUEL__:
			self.AdvancedDuelButtonList = None
			self.AdvancedDuelToolTip = None
			self.AdvancedDuelToolTipList = None
			self.AdvancedDuelTIpButton = None

#Find
		self.TargetMoney.SetText(str(exchange.GetElkFromTarget()))

#Add
		if app.__BL_ADVANCED_DUEL__:
			self.RefreshAdvancedDuel()