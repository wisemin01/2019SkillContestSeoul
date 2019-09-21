#pragma once
#include "Singleton.h"

#include "../BaseLayers/KeyCode.h"

class InputManager :
	public Singleton<InputManager>
{
private:
	bool m_bCurrentKey[256] = { false };
	bool m_bPrevKey[256] = { false };

public:

	void Update();

	bool GetKeyDown(KeyCode key);
	bool GetKeyUp(KeyCode key);
	bool GetKeyPress(KeyCode key);

	Vector3 GetMousePosition();
};

#define INPUTMANAGER InputManager::GetInstance()

Vector3 ScreenToWorld(const Vector3& screen);
Vector3 WorldToScreen(const Vector3& world);
Vector2 ScreenToWorld(const Vector2& screen);
Vector2 WorldToScreen(const Vector2& world);

// INPUT CLASS : to make access easier
static class Input
{
public:
	static inline bool GetKeyDown(KeyCode key)
	{
		return INPUTMANAGER.GetKeyDown(key);
	}
	static inline bool GetKeyUp(KeyCode key)
	{
		return INPUTMANAGER.GetKeyUp(key);
	}
	static inline bool GetKeyPress(KeyCode key)
	{
		return INPUTMANAGER.GetKeyPress(key);
	}
	static inline Vector3 GetMousePosition()
	{
		return INPUTMANAGER.GetMousePosition();
	}
};