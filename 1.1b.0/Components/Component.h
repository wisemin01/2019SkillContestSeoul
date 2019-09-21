#pragma once

class Actor;

class Transform;
class Renderer;
class Collider;
class Rigidbody;

/*
 *	������Ʈ�� Actor ��ü�� �����̳ʿ� ��� �����ϸ�
 *  ���� �������Ͽ� ����� ���� ������Ʈ�� ������ �� �ֽ��ϴ�.
*/
class Component
{
	COMPONENT_HEAD(Component, null_t, false)

	friend class Actor;
private:

	Actor* m_pBaseActor = nullptr;

public:
	Component() {}
	virtual ~Component() {}

	// ó�� ������Ʈ�� �ʱ�ȭ �� �� ȣ��˴ϴ�.
	virtual void Initialize() = 0;
	// �� ������ ȣ��Ǵ� �Լ��Դϴ�.
	virtual void Update() = 0;
	// �� ������ ȣ��Ǵ� �Լ��Դϴ�. Update() �������� ��� ����� �� ȣ��˴ϴ�.
	virtual void LateUpdate() {}
	// ������Ʈ�� �ı��� �� ȣ��˴ϴ�.
	virtual void Release() = 0;

protected:

	// ��ü�� ���̰� �Ǿ��� �� ȣ��˴ϴ�.
	virtual void OnVisible() {}
	// ��ü�� ������ �ʰ� �Ǿ��� �� ȣ��˴ϴ�.
	virtual void OnUnvisible() {}
	// ��ü�� Ȱ��ȭ �Ǿ��� �� ȣ��˴ϴ�.
	virtual void OnEnable() {}
	// ��ü�� ��Ȱ��ȭ �Ǿ��� �� ȣ��˴ϴ�.
	virtual void OnDisable() {}
	// ��ü�� �ı��� �� ȣ��˴ϴ�. < Destroy( Actor* ) �Լ��� ���� ȣ��˴ϴ�. >
	virtual void OnDestroy() {}
	// ��ü�� �浹�� �� ȣ��˴ϴ�. Collider* ������Ʈ�� �߰��Ǿ� �ִ� ���¿����� ȣ��˴ϴ�.
	virtual void OnCollision(Collider* other) {}

	// �ش� target ��ü�� �ı��մϴ�.
	void Destroy(Actor* target);

public:

	// �� ������Ʈ�� �߰��մϴ�.
	// ���� Ÿ���� ������Ʈ�� �ߺ��Ǿ� �߰����� �ʽ��ϴ�.
	// ��ȯ : �ߺ��� ���� ������Ʈ
	template <class COM>
	COM* AddComponent();

	// �ش� Ÿ���� ������Ʈ�� �����ɴϴ�.
	// ȣ�� ��� : std::map<>::find() , static_cast<>
	template <class COM>
	COM* GetComponent();

	// �� ������Ʈ�� ������ Actor ��ü�� �����ɴϴ�.
	PropertyG(GetActor) Actor* Base;

	// Transform ��ü�� �����ɴϴ�. ���� ��� nullptr �� ��ȯ�մϴ�.
	PropertyG(GetTransform) Transform* transform;
	// Renderer ��ü�� �����ɴϴ�. ���� ��� nullptr �� ��ȯ�մϴ�.
	PropertyG(GetRenderer) Renderer* renderer;
	// Collider ��ü�� �����ɴϴ�. ���� ��� nullptr �� ��ȯ�մϴ�.
	PropertyG(GetCollider) Collider* collider;
	// Rigidbody ��ü�� �����ɴϴ�. ���� ��� nullptr �� ��ȯ�մϴ�.
	PropertyG(GetRigidbody) Rigidbody* rigidbody;

private:

	// Actor ��ü�� �����մϴ�.
	inline void SetActor(Actor* actor) { m_pBaseActor = actor; }

public:

	inline Actor* GetActor() const { return m_pBaseActor; }

	Transform* GetTransform() const;
	Renderer* GetRenderer() const;
	Collider* GetCollider() const;
	Rigidbody* GetRigidbody() const;
};

#include "Component.hpp"