#pragma once
#include "../Math/Math.h"

static class Window
{
public:
	enum : int
	{
		Width = 1280,
		Height = 720,
	};

	static const bool Windowed = true;
	inline static Vector3 Center = Vector3(Width / 2, Height / 2, 0);
};