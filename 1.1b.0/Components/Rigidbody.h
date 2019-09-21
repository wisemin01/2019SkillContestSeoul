#pragma once
#include "Component.h"

class Rigidbody :
	public Component
{
	COMPONENT_HEAD(Rigidbody, Component, true)
private:

	Vector3 m_vVelocity = Vector3::Zero;
	Vector3 m_vForce = Vector3::Zero;

	float m_fFriction = 0.8f;

	bool m_bIsPhysicalTreatment = false;
	bool m_bIsUseGravity = false;

public:
	// Component��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Release() override;
	virtual void OnCollision(Collider* other) override;

	void AddForce(const Vector3& force);
	void AddForce(const Vector2& force);
	void AddForce(float x, float y, float z);
	void AddForce(float x, float y);

	void MovePosition(const Vector3& position);

public:

	Vector3 GetVelocity() { return m_vVelocity; }
	void SetVelocity(const Vector3& value) { m_vVelocity = value; }

	float GetFriction() { return m_fFriction; }
	void SetFriction(float value) { m_fFriction = value; }

	bool GetPhysicalTreatment() { return m_bIsPhysicalTreatment; }
	void SetPhysicalTreatment(bool value) { m_bIsPhysicalTreatment = value; }

	PropertyGS(GetVelocity, SetVelocity) Vector3 Velocity;
	PropertyGS(GetFriction, SetFriction) float Friction;
	PropertyGS(GetPhysicalTreatment, SetPhysicalTreatment) bool PhysicalTreatment;

private:
	inline static Vector3 g_vGravity = Vector3(0, 9.8, 0);
public:
	static Vector3 GetGravity() { return g_vGravity; }
};

