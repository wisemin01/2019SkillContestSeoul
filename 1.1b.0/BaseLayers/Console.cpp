#include "DXUT.h"
#include "Console.h"

void Console::Alloc()
{
	::AllocConsole();
	(VOID)(::freopen("CONOUT$", "w", stdout));
}

void Console::Free()
{
	::FreeConsole();
}

void Console::Clear()
{
	system("cls");
}
