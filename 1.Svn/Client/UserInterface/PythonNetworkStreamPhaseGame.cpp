//Find
		case EXCHANGE_SUBHEADER_GC_LESS_ELK:
			Tracef("trade_less_elk");
			break;
			
///Add
#if defined(__BL_ADVANCED_DUEL__)
		case EXCHANGE_SUBHEADER_GC_DUEL_SETTINGS:
			if (exchange_packet.is_me)
				CPythonExchange::Instance().SetDuelFlagToSelf(exchange_packet.arg1);
			else
				CPythonExchange::Instance().SetDuelFlagToTarget(exchange_packet.arg1);
			__RefreshExchangeWindow();
			break;
#endif

//Find
bool CPythonNetworkStream::SendExchangeAcceptPacket()
{
	...
}

///Add
#if defined(__BL_ADVANCED_DUEL__)
bool CPythonNetworkStream::SendExchangeDuelFlagPacket(std::uint8_t uFlag)
{
	if (!__CanActMainInstance())
		return true;

	TPacketCGExchange	packet;

	packet.header = HEADER_CG_EXCHANGE;
	packet.subheader = EXCHANGE_SUBHEADER_CG_DUEL_SETTINGS;
	packet.arg1 = uFlag;

	if (!Send(sizeof(packet), &packet))
	{
		Tracef("send_trade_duel_flag_packet Error\n");
		return false;
	}

	return SendSequence();
}
#endif