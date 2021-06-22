//Find
PyObject* netSendExchangeAcceptPacket(PyObject* poSelf, PyObject* poArgs)
{
	...
}

///Add
#if defined(__BL_ADVANCED_DUEL__)
PyObject* netSendExchangeDuelFlagPacket(PyObject* poSelf, PyObject* poArgs)
{
	BYTE bFlag;
	if (!PyTuple_GetByte(poArgs, 0, &bFlag))
		return Py_BuildException();

	CPythonNetworkStream& rkNetStream = CPythonNetworkStream::Instance();
	rkNetStream.SendExchangeDuelFlagPacket(bFlag);
	return Py_BuildNone();
}
#endif

//Find
		{ "SendExchangeAcceptPacket",			netSendExchangeAcceptPacket,			METH_VARARGS },
		
///Add
#if defined(__BL_ADVANCED_DUEL__)
		{ "SendExchangeDuelFlagPacket",			netSendExchangeDuelFlagPacket,			METH_VARARGS },
#endif