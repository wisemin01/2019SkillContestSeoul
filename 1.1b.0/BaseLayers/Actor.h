#pragma once

class Component;

/*
 * When creating an Actor,
 * you must create it using the 
 * Actor::Create() function.
*/
class Actor final
{
	friend class ActorManager;
	friend class CollisionManager;

	friend class Transform;
	friend class Renderer;
	friend class Collider;
	friend class Rigidbody;
private:
	bool	m_bLive			= true;
	bool	m_bVisible		= true;
	bool	m_bActive		= true;

	_tag_type		m_Tag			= -1;

	std::map< uint, Component* > m_mapComponents;

private:

	Transform* m_pTransform = nullptr;
	Renderer* m_pRenderer = nullptr;
	Collider* m_pCollider = nullptr;
	Rigidbody* m_pRigidbody = nullptr;

public:

	inline Transform* GetTransform() const { return m_pTransform; }
	inline Renderer* GetRenderer() const { return m_pRenderer; }
	inline Collider* GetCollider() const { return m_pCollider; }
	inline Rigidbody* GetRigidbody() const { return m_pRigidbody; }

	inline void SetTransform(Transform* value) { m_pTransform = value; }
	inline void SetRenderer(Renderer* value) { m_pRenderer = value; }
	inline void SetCollider(Collider* value) { m_pCollider = value; }
	inline void SetRigidbody(Rigidbody* value) { m_pRigidbody = value; }

	PropertyGS(GetTransform, SetTransform) Transform* transform;
	PropertyGS(GetRenderer, SetRenderer) Renderer* renderer;
	PropertyGS(GetCollider, SetCollider) Collider* collider;
	PropertyGS(GetRigidbody, SetRigidbody) Rigidbody* rigidbody;

private:
	Actor() {}

	Actor(_tag_type tag)
		: m_Tag(tag) {}

	Actor(bool isVisible, bool isActive) 
		: m_bVisible(isVisible), m_bActive(isActive) {}

	Actor(_tag_type tag, bool isVisible, bool isActive)
		: m_Tag(tag), m_bVisible(isVisible), m_bActive(isActive) {}

	Actor(const Actor& other) = delete;

	~Actor() {}

	Actor& operator=(const Actor&) = delete;

	void Initialize();
	void Update();
	void LateUpdate();
	void Release();

	void OnVisible();
	void OnUnvisible();
	void OnEnable();
	void OnDisable();
	void OnDestroy();

	void OnCollision(Collider* other);

public:

	void SetIsLive		(bool value);
	void SetIsVisible	(bool value);
	void SetIsActive	(bool value);

	bool GetIsLive		()		{ return m_bLive;		}
	bool GetIsVisible	()		{ return m_bVisible;	}
	bool GetIsActive	()		{ return m_bActive;		}

	PropertyGS(GetIsLive, SetIsLive)			bool IsLive;
	PropertyGS(GetIsVisible, SetIsVisible)		bool IsVisible;
	PropertyGS(GetIsActive, SetIsActive)		bool IsActive;

public:

	template <class COM>
	COM* AddComponent();

	template <class COM>
	COM* GetComponent();

	template <class COM, typename ... Args>
	COM* AddComponent(Args... args);


	void SetParent(Actor* value);
	void AddChlid(Actor* value);

public:

	static Actor* Create(_tag_type tag = -1, bool isVisible = true, bool isActive = true, int layer = 0);
	static Actor* Create(_tag_type tag, int layer);
	static Actor* CreateEmpty(_tag_type tag = -1, bool isVisible = true, bool isActive = true);
	static Actor* Find(_tag_type tag);
	static uint PoolSize();
};

#include "Actor.hpp"