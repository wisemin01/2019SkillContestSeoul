#pragma once
#include "Component.h"

class Collider :
	public Component
{
	COMPONENT_HEAD(Collider, Component, true)

protected:

	enum class CollisionType
	{
		None = 1 << 0,
		Sphere = 1 << 1,
		Box = 1 << 2,
		Rectangle = 1 << 3,
		Pixel = 1 << 4
	};

private:

	Sphere	m_BoundarySphere = Sphere(Vector3::Zero, 0);

protected:

	bool	m_bIsTrigger = false;
	int		m_iCollisionLayer = 0;
	int		m_iCollisionType = (int)CollisionType::None;

public:
	Collider() {}
	Collider(float range);

	// Component을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Release() override;

	bool GetIsTrigger() { return m_bIsTrigger; }
	void SetIsTrigger(bool value) { m_bIsTrigger = value; }

	_tag_type GetTag() { return Base->m_Tag; }

	int		GetLayer() { return m_iCollisionLayer; }
	void	SetLayer(int value) { m_iCollisionLayer = value; }

	virtual const Sphere GetBoundarySphere() const;
	virtual const Rect GetBoundaryRect() const { return Rect(); }
	virtual const Box GetBoundaryBox()		const { return Box(); }

	virtual void SetBoundarySphere(const Sphere& sphere) { m_BoundarySphere = sphere; }
	virtual void SetBoundaryRect(const Rect& sphere) {}
	virtual void SetBoundaryBox(const Box& sphere) {}

public:

	PropertyGS(GetIsTrigger, SetIsTrigger) bool IsTrigger;
	PropertyGS(GetLayer, SetLayer) int CollisionLayer;
	PropertyG(GetTag) _tag_type Tag;

public:

	static bool Intersect(const Collider* c1, const Collider* c2);
};
