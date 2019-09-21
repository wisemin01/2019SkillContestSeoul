#include "DXUT.h"
#include "Renderer.h"

#include "../BaseLayers/Actor.h"
#include "Animation.h"

void Renderer::Initialize()
{
	Base->renderer = this;

	RENDERMANAGER.Register(this);
}

void Renderer::Update()
{
	if (m_pCurrentAnime)
	{
		m_pCurrentAnime->Update();
	}
}

void Renderer::Release()
{
	if (Base->renderer == this)
		Base->renderer = nullptr;

	RENDERMANAGER.Unregister(this);

	for (auto iter : m_mapAnimations)
	{
		SAFE_DELETE(iter.second);
	}

	m_mapAnimations.clear();

	SAFE_DELETE(m_pCenterPosition);
}

void Renderer::Render()
{
	if (m_pCurrentAnime)
	{
		RENDERMANAGER.SetTransformForSprite(&transform->GetWorldMatrix());

		if (m_pCenterPosition)
			m_pCurrentAnime->CenterRender(*m_pCenterPosition);
		else
			m_pCurrentAnime->Render();
	}
}

void Renderer::AddAnimation(int key, Animation* animation)
{
	if (auto find = m_mapAnimations.find(key); find == m_mapAnimations.end())
	{
		m_mapAnimations.insert(std::make_pair(key, animation));
	}
}

void Renderer::SingleSprite(Sprite* sprite)
{
	constexpr int key = -1;

	if (auto find = m_mapAnimations.find(key); find == m_mapAnimations.end())
	{
		m_mapAnimations.insert(std::make_pair(key, new Animation(sprite, 0.0f)));
	}

	Change(key);
}

void Renderer::Change(int key)
{
	if (auto find = m_mapAnimations.find(key); find != m_mapAnimations.end())
	{
		m_pCurrentAnime = find->second;
		return;
	}

	throw exception("FSM<OWNER>::ChangeState(int key) - Invalid key value.");
}

void Renderer::ChangeSprite(Sprite* sprite)
{
	if (CurrentAnime)
	{
		CurrentAnime->AnimeSprite = sprite;
	}
}

void Renderer::SetDrawCenter(Vector3 center)
{
	if (m_pCenterPosition)
	{
		*m_pCenterPosition = center;
	}
	else
	{
		m_pCenterPosition = new Vector3(center);
	}
}

void Renderer::UnuseCenter()
{
	SAFE_DELETE(m_pCenterPosition);
}

void Renderer::SetRenderType(int renderType)
{
	// 변경 사항이 없을 경우
	if (renderType == m_RenderType)
	{
		return;
	}

	// 변경 사항이 있을경우

	RENDERMANAGER.Unregister(this);
	m_RenderType = renderType;
	RENDERMANAGER.Register(this);
}
