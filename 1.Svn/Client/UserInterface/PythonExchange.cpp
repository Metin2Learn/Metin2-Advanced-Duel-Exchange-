//Find
void CPythonExchange::SetAcceptToSelf(BYTE Accept)
{
	...
}

///Add
#if defined(__BL_ADVANCED_DUEL__)
void CPythonExchange::SetDuelFlagToTarget(std::uint8_t uFlag)
{
	m_victim.uPVPFlag = uFlag;
}

void CPythonExchange::SetDuelFlagToSelf(std::uint8_t uFlag)
{
	m_self.uPVPFlag = uFlag;
}

std::uint8_t CPythonExchange::GetDuelFlagFromTarget() const
{
	return m_victim.uPVPFlag;
}

std::uint8_t CPythonExchange::GetDuelFlagFromSelf() const
{
	return m_self.uPVPFlag;
}
#endif