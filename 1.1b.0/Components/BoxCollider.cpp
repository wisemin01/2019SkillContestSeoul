#include "DXUT.h"
#include "BoxCollider.h"

BoxCollider::BoxCollider(const Box& box)
{
	SetBoundaryBox(box);
}

void BoxCollider::Initialize()
{
	m_iCollisionType = (int)CollisionType::Box;
	Super::Initialize();
}

void BoxCollider::Release()
{
	Super::Release();
}

const Box BoxCollider::GetBoundaryBox() const
{
	return m_BoundaryBox.Transform(transform->Position);
}

void BoxCollider::SetBoundaryBox(const Box& box)
{
	m_BoundaryBox = box;
}
