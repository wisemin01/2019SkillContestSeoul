#include "DXUT.h"
#include "INIFile.h"

std::string INIFile::Get(const string& section, const string& key, const string& path)
{
	char outString[256] = { 0 };
	GetPrivateProfileStringA(section.c_str(), key.c_str(), "NULL", outString, 256, path.c_str());

	return outString;
}

void INIFile::Set(const string& section, const string& key, const string& value, const string& path)
{
	WritePrivateProfileStringA(section.c_str(), key.c_str(), value.c_str(), path.c_str());
}
