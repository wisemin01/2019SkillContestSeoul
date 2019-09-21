#include "DXUT.h"
#include "Collider.h"

Collider::Collider(float range)
{
	m_BoundarySphere = Sphere(Vector3(0, 0, 0), range);
	m_iCollisionType = (int)CollisionType::Sphere;
}

void Collider::Initialize()
{
	Base->collider = this;

	COLLISIONMANAGER.Register(this);
}

void Collider::Update()
{
}

void Collider::Release()
{
	COLLISIONMANAGER.Unregister(this);

	if (Base->collider == this)
		Base->collider = nullptr;
}

const Sphere Collider::GetBoundarySphere() const
{
	Sphere world = m_BoundarySphere.Transform(transform->Position);

	return world;
}

bool Collider::Intersect(const Collider* c1, const Collider* c2)
{
	constexpr int _type_none		= (int)CollisionType::None;
	constexpr int _type_sphere		= (int)CollisionType::Sphere;
	constexpr int _type_box			= (int)CollisionType::Box;
	constexpr int _type_rectangle	= (int)CollisionType::Rectangle;
	constexpr int _type_pixelsource = (int)CollisionType::Pixel;

	if (c1->m_iCollisionType == _type_sphere
		&& c2->m_iCollisionType == _type_sphere)
	{
		return ::Intersect(c1->GetBoundarySphere(), c2->GetBoundarySphere());
	}

	if (c1->m_iCollisionType == _type_rectangle
		&& c2->m_iCollisionType == _type_rectangle)
	{
		return ::Intersect(c1->GetBoundaryRect(), c2->GetBoundaryRect());
	}

	if (c1->m_iCollisionType == _type_box
		&& c2->m_iCollisionType == _type_box)
	{
		return ::Intersect(c1->GetBoundaryBox(), c2->GetBoundaryBox());
	}

	return false;
}
