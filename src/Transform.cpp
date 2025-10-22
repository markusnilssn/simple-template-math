#include "Transform.hpp"

namespace stm
{
	Transform::Transform() 
		: m_Scale(1, 1, 1), 
		  m_Rotation(), 
		  m_Position()
	{

	}

	Transform::Transform(const Transform& aTransform)
	{
		m_Scale = aTransform.m_Scale;
		m_Rotation = aTransform.m_Rotation;
		m_Position = aTransform.m_Position;
	}

	void Transform::SetScale(const Vector3f& aScale)
	{
		m_Scale = aScale;
	}

	void Transform::SetRotation(const Quaternion& aRotation)
	{
		m_Rotation = aRotation;
	}

	void Transform::SetRotation(const float aDegreeAngle, const Vector3f& aRotationAxis)
	{
		SetRotation(Quaternion(aDegreeAngle, aRotationAxis));
	}

	void Transform::SetRotation(const Vector3f& aEulerAngle)
	{
		SetRotation(Quaternion(aEulerAngle.x, aEulerAngle.y, aEulerAngle.z));
	}

	void Transform::SetPosition(const Vector3f& aPosition)
	{
		m_Position = aPosition;
	}
	void Transform::Move(const Vector3f& aMoveVec)
	{
		m_Position += aMoveVec;
	}
	const Vector3f& Transform::GetScale() const
	{
		return m_Scale;
	}
	const Quaternion& Transform::GetRotationQuaternion() const
	{
		return m_Rotation;
	}
	const Vector3f Transform::GetRotationEuler() const
	{
		return m_Rotation.GetEuler();
	}
	const Vector3f& Transform::GetPosition() const
	{
		return m_Position;
	}
	const Vector3f Transform::GetUp() const
	{
		return Rotate(Vector3f(0, 1, 0));
	}
	const Vector3f Transform::GetRight() const
	{
		return Rotate(Vector3f(1, 0, 0));
	}
	const Vector3f Transform::GetForward() const
	{
		return Rotate(Vector3f(0, 0, 1));
	}
	const Vector3f Transform::Rotate(const Vector3f& aVector) const
	{
		return m_Rotation.Rotate(aVector);
	}
	const Vector4f Transform::Rotate(const Vector4f& aVector) const
	{
		return m_Rotation.Rotate(aVector);
	}
	const Matrix4x4f Transform::CreateMatrix() const
	{
		Vector4f right = Vector4f(m_Scale.x, 0, 0, 0);
		Vector4f up = Vector4f(0, m_Scale.y, 0, 0);
		Vector4f forward = Vector4f(0, 0, m_Scale.z, 0);

		right = m_Rotation.Rotate(right);
		up = m_Rotation.Rotate(up);
		forward = m_Rotation.Rotate(forward);

		Matrix4x4f returnMatrix = Matrix4x4f();
		returnMatrix(1, 1) = right.x;
		returnMatrix(1, 2) = right.y;
		returnMatrix(1, 3) = right.z;
		returnMatrix(2, 1) = up.x;
		returnMatrix(2, 2) = up.y;
		returnMatrix(2, 3) = up.z;
		returnMatrix(3, 1) = forward.x;
		returnMatrix(3, 2) = forward.y;
		returnMatrix(3, 3) = forward.z;
		returnMatrix(4, 1) = m_Position.x;
		returnMatrix(4, 2) = m_Position.y;
		returnMatrix(4, 3) = m_Position.z;

		return returnMatrix;
	}
	const Vector3f operator*(const Vector3f& aVector, const Transform& aTransform)
	{
		Vector3f returnVector = aVector;
		returnVector.x *= aTransform.m_Scale.x;
		returnVector.y *= aTransform.m_Scale.y;
		returnVector.z *= aTransform.m_Scale.z;
		returnVector = aTransform.m_Rotation.Rotate(returnVector);
		returnVector += aTransform.m_Position;

		return returnVector;
	}

	void operator*=(Vector3f& aVector, const Transform& aTransform)
	{
		aVector = aVector * aTransform;
	}

	const Vector4f operator*(const Vector4f& aVector, const Transform& aTransform)
	{
		Vector4f returnVector = aVector;
		returnVector.x *= aTransform.m_Scale.x;
		returnVector.y *= aTransform.m_Scale.y;
		returnVector.z *= aTransform.m_Scale.z;
		returnVector = aTransform.m_Rotation.Rotate(returnVector);
		returnVector.x += aTransform.m_Position.x * returnVector.w;
		returnVector.y += aTransform.m_Position.y * returnVector.w;
		returnVector.z += aTransform.m_Position.z * returnVector.w;

		return returnVector;
	}

	void operator*=(Vector4f& aVector, const Transform& aTransform)
	{
		aVector = aVector * aTransform;
	}
}