#pragma once
#include <iostream>

class already_exists_exception :
	public std::exception
{
public:
	already_exists_exception() noexcept
		: exception()
	{
	}

	explicit already_exists_exception(char const* const _Message) noexcept
		: exception(_Message)
	{
	}

	already_exists_exception(char const* const _Message, int) noexcept
		: exception(_Message)
	{
	}

	already_exists_exception(exception const& _Other) noexcept
		: exception(_Other)
	{
	}
};

