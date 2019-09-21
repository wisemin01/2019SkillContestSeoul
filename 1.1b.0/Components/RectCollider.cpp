#include "DXUT.h"
#include "RectCollider.h"

RectCollider::RectCollider(float width, float height)
{
	::SetRect(&m_BoundaryRect, -Half(width), -Half(height), Half(width), Half(height));
}

RectCollider::RectCollider(const Rect& rc)
{
	m_BoundaryRect = rc;
}

RectCollider::RectCollider(float left, float top, float right, float bottom)
{
	::SetRect(&m_BoundaryRect, left, top, right, bottom);
}

void RectCollider::Initialize()
{
	m_iCollisionType = (int)CollisionType::Rectangle;
	Super::Initialize();
}

void RectCollider::Release()
{
	Super::Release();
}

const Rect RectCollider::GetBoundaryRect() const
{
	Rect world;

	Vector3 p = transform->Position;
	Vector3 s = transform->Scale;

	SetRect(&world, m_BoundaryRect.left * s.x + p.x,
		m_BoundaryRect.top * s.y + p.y,
		m_BoundaryRect.right * s.x + p.x,
		m_BoundaryRect.bottom * s.y + p.y);

	return world;
}

void RectCollider::SetBoundaryRect(const Rect& rc)
{
	m_BoundaryRect = rc;
}
