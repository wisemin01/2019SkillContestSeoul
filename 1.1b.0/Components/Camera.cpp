#include "DXUT.h"
#include "Camera.h"

void Camera::Initialize()
{
	Set(Window::Width, Window::Height);

	// ���� ī�޶� �ƹ��͵� ���ٸ� �ڵ����� ���� ī�޶� �ȴ�.
	if (MainCamera() == nullptr)
	{
		SetMain();
	}

	m_pShakeTimer = Timer::Create(0);
}

void Camera::Update()
{
	if (m_listShakeInfos.empty() == false)
	{
		for (auto iter = m_listShakeInfos.begin(); iter != m_listShakeInfos.end();)
		{
			if (iter->timer->IsEnd == true)
			{
				Timer::Destroy(iter->timer);

				iter = m_listShakeInfos.erase(iter);
			}
			else
			{
				transform->Translate(
					Vector3(
						Random::Instance().Get(-iter->power, iter->power),
						Random::Instance().Get(-iter->power, iter->power), 0)
				);
				iter++;
			}
		}
	}


	RENDERMANAGER.SetTransformForDevice(D3DTS_VIEW, &Matrix::View2D(transform->Position, transform->Scale, 0));
}

void Camera::Release()
{
	if (g_pMainCamera == this)
		g_pMainCamera = nullptr;
}

void Camera::Set(int width, int height)
{
	m_iWidth = width;
	m_iHeight = height;

	// 2d world �� y���� +/- �� �ٲ���ִ�.
	RENDERMANAGER.SetTransformForDevice(D3DTS_PROJECTION, &Matrix::OrthoLH(width, -height, 0, 1));
}

void Camera::Shake(float time, float power)
{
	m_listShakeInfos.push_back(ShakeInfo(Timer::Create(time), power));
}

void Camera::SetMain()
{
	g_pMainCamera = this;
}
