#pragma once
#include "Component.h"

class Camera :
	public Component
{
	COMPONENT_HEAD(Camera, Component, true)

	struct ShakeInfo
	{
		Timer* timer = nullptr;
		float power = 0.0f;

		ShakeInfo(Timer* timer, float power)
			: timer(timer), power(power) {}
	};
private:

	Vector3 m_vLookAt = Vector3::Zero;

	int m_iWidth = 0;
	int m_iHeight = 0;

	Timer* m_pShakeTimer = nullptr;
	bool m_bShakeOn = false;
	float m_fShakePower = 10.0f;

	std::list<ShakeInfo> m_listShakeInfos;

public:
	// ī�޶� ������Ʈ�� �������� ������ �⺻ Window::Width, Window::Height�� Projection�� �����ϴ�.
	Camera() {}
	Camera(float width, float height) : m_iWidth(width), m_iHeight(height) {}
	~Camera() {}

	// Component��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Release() override;

	void Set(int width, int height);

	void Shake(float time, float power);
	void SetMain();

	int GetWidth() { return m_iWidth; }
	int GetHeight() { return m_iHeight; }

	PropertyG(GetWidth) int Width;
	PropertyG(GetHeight) int Height;

private:
	inline static Camera* g_pMainCamera = nullptr;

public:
	static Camera* MainCamera() { return g_pMainCamera; }
};