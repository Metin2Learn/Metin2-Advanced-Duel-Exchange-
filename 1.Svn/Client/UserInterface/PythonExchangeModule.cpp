//Find
PyObject * exchangeGetAcceptFromTarget(PyObject * poSelf, PyObject * poArgs)
{
	return Py_BuildValue("i", CPythonExchange::Instance().GetAcceptFromTarget());
}

///Add
#if defined(__BL_ADVANCED_DUEL__)
PyObject* exchangeGetDuelFlagFromTarget(PyObject* poSelf, PyObject* poArgs)
{
	return Py_BuildValue("i", CPythonExchange::Instance().GetDuelFlagFromTarget());
}

PyObject* exchangeGetDuelFlagFromSelf(PyObject* poSelf, PyObject* poArgs)
{
	return Py_BuildValue("i", CPythonExchange::Instance().GetDuelFlagFromSelf());
}
#endif

//Find
		{"GetNameFromTarget",			exchangeGetNameFromTarget,			METH_VARARGS},
		
///Add
#if defined(__BL_ADVANCED_DUEL__)
		{"GetDuelFlagFromTarget",		exchangeGetDuelFlagFromTarget,		METH_VARARGS},
		{"GetDuelFlagFromSelf",			exchangeGetDuelFlagFromSelf,		METH_VARARGS},
#endif