#include "DXUT.h"
#include "Transform.h"

#include "../BaseLayers/Actor.h"


Transform::Transform()
{
}

Transform::Transform(const Vector3& position)
{
	m_vLocalPosition = position;
}

Transform::~Transform()
{
}

void Transform::Initialize()
{
	Base->transform = this;
}

void Transform::Update()
{
	if (m_pParentTransform &&
		m_pParentTransform->Base->IsLive == false)
	{
		m_pParentTransform = nullptr;
		Destroy(Base);
	}
}

void Transform::Release()
{
	if (Base->transform == this)
		Base->transform = nullptr;
}

void Transform::Translate(const Vector3& v)
{
	m_vLocalPosition += v;
}

void Transform::Scaling(float s)
{
	m_vLocalScale *= s;
}

Matrix Transform::GetWorldMatrix()
{
	Matrix world = Matrix::Scaling(m_vLocalScale)
		* Matrix::RotationZ(m_fLocalRotation)
		* Matrix::Translation(m_vLocalPosition);

	if (m_pParentTransform != nullptr)
		world *= m_pParentTransform->GetWorldMatrix();

	return world;
}

void Transform::SetParent(Transform* parent)
{
	m_pParentTransform = parent;
}

void Transform::AddChlid(Transform* chlid)
{
	chlid->SetParent(this);
}

Vector3 Transform::GetPosition() const
{
	if (m_pParentTransform)
	{
		return m_vLocalPosition + m_pParentTransform->GetPosition();
	}

	return m_vLocalPosition;
}

Vector3 Transform::GetScale() const
{
	if (m_pParentTransform)
	{
		return m_vLocalScale * m_pParentTransform->GetScale();
	}

	return m_vLocalScale;
}

float Transform::GetRotation() const
{
	if (m_pParentTransform)
	{
		return m_fLocalRotation + m_pParentTransform->GetRotation();
	}

	return m_fLocalRotation;
}

Vector3 Transform::GetLocalPosition() const
{
	return m_vLocalPosition;
}

Vector3 Transform::GetLocalScale() const
{
	return m_vLocalScale;
}

float Transform::GetLocalRotation() const
{
	return m_fLocalRotation;
}

Transform* Transform::GetParent()
{
	return m_pParentTransform;
}

void Transform::SetPosition(const Vector3& v)
{
	m_vLocalPosition = v;
}

void Transform::SetScale(const Vector3& v)
{
	m_vLocalScale = v;
}

void Transform::SetRotation(float v)
{
	m_fLocalRotation = v;
}

void Transform::Rotate(float value)
{
	m_fLocalRotation = value;
}
