#pragma once
#include "Collider.h"

class BoxCollider
	: public Collider
{
	COMPONENT_HEAD(BoxCollider, Collider, false)
private:

	Box m_BoundaryBox = Box(0, 0, 0, 0, 0, 0);

public:
	BoxCollider() {}
	BoxCollider(const Box& box);

	virtual void Initialize();
	virtual void Release();

	virtual const Box GetBoundaryBox() const override;
	virtual void SetBoundaryBox(const Box& box) override;
};