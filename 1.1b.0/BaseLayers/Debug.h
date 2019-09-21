#pragma once

class CrtFlagType 
{
public:
	enum
	{
		Alloc_Mem = _CRTDBG_ALLOC_MEM_DF,
		Delay_Free_Mem = _CRTDBG_DELAY_FREE_MEM_DF,
		Check_Always = _CRTDBG_CHECK_ALWAYS_DF,
		Reserved = _CRTDBG_RESERVED_DF,
		Check_Crt = _CRTDBG_CHECK_CRT_DF,
		Leak_Check = _CRTDBG_LEAK_CHECK_DF
	};
};

class MessageBoxType
{
public:
	enum Arg
	{
		Ok = 0x00000000L,
		Ok_Cancel = 0x00000001L,
		Abort_Retry_Ignore = 0x00000002L,
		Yes_No_Cancel = 0x00000003L,
		Yes_No = 0x00000004L,
		Retry_Cancel = 0x00000005L
	};

	enum Result
	{
		Result_Ok = 1,
		Cancel = 2,
		Abort = 3,
		Retry = 4,
		Ignore = 5,
		Yes = 6,
		No = 7
	};
};

static class Debug
{
public:
	Debug() {}
	Debug(const Debug& other) = delete;

	static void SetCrtDebugFlag(int flag);
	static void SetBreakAlloc(int alloc);

	static int ShowMessage(const string& caption, const string& text, uint type);

	template<typename ...Args>
	static void Log(Args... args)
	{
		Console::Log(args...);
	}

#if defined(DEBUG)
	inline static constexpr bool IsDebuging = true;
#else
	inline static constexpr bool IsDebuging = false;
#endif
};

