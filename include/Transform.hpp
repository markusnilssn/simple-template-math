#pragma once
#include "Vector3.hpp"
#include "Quaternion.hpp"
#include "Matrix4x4.hpp"

namespace stm
{
	class Transform
	{
	public:
		Transform();
		~Transform() = default;
		Transform(const Transform& aTransform);

		void SetPosition(const Vector3f& aPosition);
		
		void SetRotation(const Quaternion& aRotation);
		void SetRotation(const float aDegreeAngle, const Vector3f& aRotationAxis);
		void SetRotation(const Vector3f& aEulerAngle);

		const Vector3f Rotate(const Vector3f& aVector) const;
		const Vector4f Rotate(const Vector4f& aVector) const;


		void SetScale(const Vector3f& aScale);
		
		void Move(const Vector3f& aMoveVec);

		const Vector3f GetUp() const;
		const Vector3f GetRight() const;
		const Vector3f GetForward() const;

		const Vector3f& GetPosition() const;

		const Quaternion& GetRotationQuaternion() const;
		const Vector3f GetRotationEuler() const;

		const Vector3f& GetScale() const;

		const Matrix4x4f CreateMatrix() const;

		friend const Vector3f operator*(const Vector3f& aVector, const Transform& aTransform);
		friend void operator*=(Vector3f& aVector, const Transform& aTransform);
		friend const Vector4f operator*(const Vector4f& aVector, const Transform& aTransform);
		friend void operator*=(Vector4f& aVector, const Transform& aTransform);

	private:
		Vector3f m_Scale;
		Quaternion m_Rotation;
		Vector3f m_Position;

	};
}