#pragma once
#include "Component.h"

static class RenderType
{
public:
	enum
	{
		None = -1,
		ObjectSpace,
		UI
	};

};

class Animation;

class Renderer :
	public Component
{
	COMPONENT_HEAD(Renderer, Component, true)
protected:
	std::map< int, Animation* > m_mapAnimations;

	Animation* m_pCurrentAnime = nullptr;

	int m_RenderType = RenderType::ObjectSpace;
	int m_iRenderLayer = 0;

	Vector3* m_pCenterPosition = nullptr;

public:
	Renderer() {}
	virtual ~Renderer() {}

	// Component��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Release() override;

	virtual void Render();

	void AddAnimation(int key, Animation* animation);
	void SingleSprite(Sprite* sprite);
	void Change(int key);

	// change current animation's sprite
	void ChangeSprite(Sprite* sprite);

	int GetLayer() const { return m_iRenderLayer; }
	void SetLayer(int value) { m_iRenderLayer = value; }

	void SetDrawCenter(Vector3 center);
	void UnuseCenter();

public:

	Animation* GetCurrentAnimation() { return m_pCurrentAnime; }

	int GetRenderType() { return m_RenderType; }

	// argument optional : RenderType::enum
	void SetRenderType(int renderType);

	PropertyGS(GetRenderType, SetRenderType) int RenderType;
	PropertyGS(GetLayer, SetLayer) int Layer;
	PropertyG(GetCurrentAnimation) Animation* CurrentAnime;
};

