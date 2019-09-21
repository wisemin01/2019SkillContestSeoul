#include "DXUT.h"
#include "Font.h"


Font* Font::Load(const string& fontKey, int size)
{
	return RESOURCEMANAGER.InsertFont(fontKey, size);
}

Font* Font::Find(const string& fontKey, int size)
{
	return RESOURCEMANAGER.FindFont(fontKey, size);
}
