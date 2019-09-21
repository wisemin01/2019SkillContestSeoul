#include "DXUT.h"
#include "Actor.h"

#include "../Components/Component.h"

#include "../Components/Renderer.h"
#include "../Components/Transform.h"

#define ComponentsAction( DO ) \
for (auto &iter: m_mapComponents) \
{ \
	(iter.second)->DO; \
}

void Actor::Initialize()
{

}

void Actor::Update()
{
	ComponentsAction(Update());
}

void Actor::LateUpdate()
{
	ComponentsAction(LateUpdate());
}

void Actor::Release()
{
	for (auto iter : m_mapComponents)
	{
		iter.second->Release();
		SAFE_DELETE(iter.second);
	}

	m_mapComponents.clear();
}

void Actor::OnVisible()
{
	ComponentsAction(OnVisible());
}

void Actor::OnUnvisible()
{
	ComponentsAction(OnUnvisible());
}

void Actor::OnEnable()
{
	ComponentsAction(OnEnable());
}

void Actor::OnDisable()
{
	ComponentsAction(OnDisable());
}

void Actor::OnDestroy()
{
	ComponentsAction(OnDestroy());
}

void Actor::OnCollision(Collider* other)
{
	ComponentsAction(OnCollision(other));
}

void Actor::SetIsLive(bool value)
{
	if (m_bLive == value)
		return;

	m_bLive = value;

	if (m_bLive == false)
	{
		OnDestroy();
	}
}

void Actor::SetIsVisible(bool value)
{
	if (m_bVisible == value)
		return;

	m_bVisible = value;

	if (m_bVisible == true)
	{
		OnVisible();
	}
	else
	{
		OnUnvisible();
	}
}

void Actor::SetIsActive(bool value)
{
	if (m_bActive == value)
		return;

	m_bActive = value;

	if (m_bActive == true)
		OnEnable();
	else
		OnDisable();
}

void Actor::SetParent(Actor* value)
{
	transform->SetParent(value->transform);
}

void Actor::AddChlid(Actor* value)
{
	transform->AddChlid(value->transform);
}

Actor* Actor::Create(_tag_type tag, bool isVisible, bool isActive, int layer)
{
	return ACTORMANAGER.Create(tag, isVisible, isActive, layer);
}

Actor* Actor::Create(_tag_type tag, int layer)
{
	return ACTORMANAGER.Create(tag, layer);
}

Actor* Actor::CreateEmpty(_tag_type tag, bool isVisible, bool isActive)
{
	return ACTORMANAGER.CreateEmpty(tag, isVisible, isActive);
}

Actor* Actor::Find(_tag_type tag)
{
	return ACTORMANAGER.FindActor(tag);
}

uint Actor::PoolSize()
{
	return ACTORMANAGER.Size;
}
