#pragma once
#include "Component.h"

class Transform :
	public Component
{
	COMPONENT_HEAD(Transform, Component, true)

private:

	Vector3 m_vLocalPosition		= Vector3::Zero;
	Vector3 m_vLocalScale			= Vector3::One;
	float	m_fLocalRotation		= 0.0f;

	Transform* m_pParentTransform	= nullptr;

public:
	Transform();
	Transform(const Vector3& position);
	virtual ~Transform();

	// Component��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Release() override;

	void Translate(const Vector3& v);
	void Scaling(float s);
	void Rotate(float value);
	
	Matrix GetWorldMatrix();

	void SetParent(Transform* parent);
	void AddChlid(Transform* chlid);

public:

	Vector3 GetPosition() const;
	Vector3 GetScale() const;
	float GetRotation() const;

	Vector3 GetLocalPosition() const;
	Vector3 GetLocalScale() const;
	float GetLocalRotation() const;

	Transform* GetParent();

	void SetPosition(const Vector3& v);
	void SetScale(const Vector3& v);
	void SetRotation(float v);

public:

	PropertyGS(GetPosition, SetPosition) Vector3 Position;
	PropertyGS(GetScale, SetScale) Vector3 Scale;
	PropertyGS(GetRotation, SetRotation) float Rotation;

	PropertyG(GetLocalPosition) Vector3 LocalPosition;
	PropertyG(GetLocalScale) Vector3 LocalScale;
	PropertyG(GetLocalRotation) float LocalRotation;
};

