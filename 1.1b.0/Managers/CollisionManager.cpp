#include "DXUT.h"
#include "CollisionManager.h"

#include "../Components/Collider.h"

void CollisionManager::Register(Collider* collider)
{
	m_listColliders.push_back(collider);
}

void CollisionManager::Unregister(Collider* collider)
{
	m_listColliders.remove(collider);
}

void CollisionManager::Update()
{
	if (m_listColliders.size() < 2)
		return;

	auto End = std::prev(m_listColliders.end());

	for (auto col1 = m_listColliders.begin(); col1 != End; col1++)
	{
		for (auto col2 = std::next(col1); col2 != m_listColliders.end(); col2++)
		{
			auto& C1 = *col1;
			auto& C2 = *col2;

			if (C1->Base->IsLive == false
				|| C2->Base->IsLive == false)
			{
				continue;
			}

			if (Collider::Intersect(C1, C2))
			{
				C1->Base->OnCollision(C2);
				C2->Base->OnCollision(C1);
			}
		}
	}
}

void CollisionManager::Reset()
{
	m_listColliders.clear();
}
