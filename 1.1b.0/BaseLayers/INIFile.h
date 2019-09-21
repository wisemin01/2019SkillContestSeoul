#pragma once

static class INIFile
{
public:
	static std::string Get(const string& section,
		const string& key,
		const string& path);

	static void Set(const string& section,
		const string& key,
		const string& value,
		const string& path);
};

