#include "Quaternion.hpp"
#include <cassert>
#include "Math.hpp"

namespace stm
{
	Quaternion::Quaternion() : r(1), i(0), j(0), k(0)
	{

	}

	Quaternion::Quaternion(float aR, float aI, float aJ, float aK)
	{
		r = aR;
		i = aI;
		j = aJ;
		k = aK;
	}

	Quaternion::Quaternion(float aX, float aY, float aZ)
	{
		*this = Quaternion(aY, { 0,1,0 }) * Quaternion(aX, { 1,0,0 }) * Quaternion(aZ, { 0,0,1 });
	}

	Quaternion::Quaternion(const Quaternion& aQuaternion)
	{
		r = aQuaternion.r;
		i = aQuaternion.i;
		j = aQuaternion.j;
		k = aQuaternion.k;
	}

	Quaternion::Quaternion(const float aDegreeAngle, const Vector3f& aRotationAxis)
	{
		float halfAngle = Math::DegreeToRad(aDegreeAngle) / 2.0f;
		float sinus = sin(halfAngle);
		r = cos(halfAngle);
		i = aRotationAxis.x * sinus;
		j = aRotationAxis.y * sinus;
		k = aRotationAxis.z * sinus;
	}

	const Vector3f Quaternion::GetEuler() const
	{
		Vector3f eulerAngle = Vector3f();

		Vector3f rotatedForward = Vector3f(0, 0, 1);
		rotatedForward = Rotate(rotatedForward);
		eulerAngle.y = atan2f(rotatedForward.x, rotatedForward.z);

		Quaternion counterYQuat = Quaternion(Math::RadToDegree(-eulerAngle.y), Vector3f(0, 1, 0));
		rotatedForward = counterYQuat.Rotate(rotatedForward);
		eulerAngle.x = atan2f(-rotatedForward.y, rotatedForward.z);

		Quaternion counterXQuat = Quaternion(Math::RadToDegree(-eulerAngle.x), Vector3f(1, 0, 0));
		Vector3f rotatedRight = Vector3f(1, 0, 0);
		rotatedRight = Rotate(rotatedRight);
		rotatedRight = counterYQuat.Rotate(rotatedRight);
		rotatedRight = counterXQuat.Rotate(rotatedRight);
		eulerAngle.z = atan2f(rotatedRight.y, rotatedRight.x);

		return eulerAngle * 57.2957795f;
	}

	const Quaternion Quaternion::operator*(const Quaternion& aOther) const
	{
		return Quaternion(r * aOther.r - i * aOther.i - j * aOther.j - k * aOther.k,
			r * aOther.i + i * aOther.r + j * aOther.k - k * aOther.j,
			r * aOther.j - i * aOther.k + j * aOther.r + k * aOther.i,
			r * aOther.k + i * aOther.j - j * aOther.i + k * aOther.r);
	}
	void Quaternion::operator*=(const Quaternion& aOther)
	{
		*this = *this * aOther;
	}
	const Vector3f Quaternion::Rotate(const Vector3f& aVector) const
	{
		Vector3f vectorPart(i, j, k);

		return 2.0f * vectorPart.Dot(aVector) * vectorPart
			+ (r * r - vectorPart.Dot(vectorPart)) * aVector
			+ 2.0f * r * vectorPart.Cross(aVector);
	}

	const Vector4f Quaternion::Rotate(const Vector4f& aVector) const
	{
		const Vector3f* vector3 = reinterpret_cast<const Vector3f*>(&aVector);
		return Vector4f(Rotate(*vector3), aVector.w);
	}
	
	void Quaternion::Normalize()
	{
		float length = std::sqrt(r * r + i * i + j * j + k * k);
		assert(length != 0 && "Division by 0");

		float result = 1.f / length;
		r *= result;
		i *= result;
		j *= result;
		k *= result;
	}
}