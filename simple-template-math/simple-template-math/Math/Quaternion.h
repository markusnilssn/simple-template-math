#pragma once
#include "Vector3.h"
#include "Vector4.h"

namespace stm
{
	class Quaternion
	{
	public:
		Quaternion();
		~Quaternion() = default;
		Quaternion(float aR, float aI, float aJ, float aK);
		Quaternion(float aX, float aY, float aZ);
		Quaternion(const Quaternion& aQuaternion);
		Quaternion(const float aDegreeAngle, const Vector3f& aRotationAxis);

		const Vector3f GetEuler() const;

		const Quaternion operator*(const Quaternion& aOther) const;
		void operator*=(const Quaternion& aOther);

		const Vector3f Rotate(const Vector3f& aVector) const;
		const Vector4f Rotate(const Vector4f& aVector) const;

		void Normalize();

		float r;
		float i;
		float j;
		float k;
	};
}