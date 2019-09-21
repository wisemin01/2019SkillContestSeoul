#pragma once
#include "Collider.h"

class RectCollider :
	public Collider
{
	COMPONENT_HEAD(RectCollider, Collider, false)
private:
	Rect m_BoundaryRect = { 0,0,0,0 };
public:
	RectCollider() {}
	RectCollider(float width, float height);
	RectCollider(const Rect& rc);
	RectCollider(float left, float top, float right, float bottom);

	virtual void Initialize();
	virtual void Release();

	virtual const Rect GetBoundaryRect() const override;
	virtual void SetBoundaryRect(const Rect& rc) override;
};

