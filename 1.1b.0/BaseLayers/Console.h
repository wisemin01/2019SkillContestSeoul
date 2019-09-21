#pragma once

class Console
{
public:
	static void Alloc();
	static void Free();

	template <typename Arg, typename ...Args>
	static void Log(Arg arg, Args... args)
	{
		cout << arg;
		Log(args...);
	}

	static void Log()
	{
		cout << endl;
	}

	static void Clear();
};

