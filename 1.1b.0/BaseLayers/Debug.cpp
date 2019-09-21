#include "DXUT.h"
#include "Debug.h"

void Debug::SetCrtDebugFlag(int flag)
{
	_CrtSetDbgFlag(flag);
}

void Debug::SetBreakAlloc(int alloc)
{
	_CrtSetBreakAlloc(alloc);
}

int Debug::ShowMessage(const string& caption, const string& text, uint type)
{
	return MessageBoxA(MDX::GetHWND(), text.c_str(), caption.c_str(), type);
}
