#pragma once
#include "Vector3.hpp"

namespace stm
{
	template <typename T>
	class Vector4
	{
	public:
		Vector4<T>();
		Vector4<T>(const T& aVariable);
		Vector4<T>(const T& aX, const T& aY, const T& aZ, const T& aW);
		Vector4<T>(const Vector3<T>& aVector3, const T& aW);
		Vector4<T>(const Vector4<T>& aVector) = default;
		~Vector4<T>() = default;

		inline Vector4<T>& operator=(const Vector4<T>& aVector4) = default;
		inline Vector4<T>& operator-(void);

		inline T LengthSqr() const;
		inline T Length() const;
		inline T Distance(const Vector4<T>& aVector) const;
		inline T DistanceSqr(const Vector4<T>& aVector) const;
		inline Vector4<T> GetNormalized() const;
		inline void Normalize();
		inline void Truncate(T aUpperBound);
		inline T Dot(const Vector4<T>& aVector) const;
		static Vector4<T> Lerp(const Vector4<T>& aFrom, const Vector4<T>& aTo, float aDelta);

		T x;
		T y;
		T z;
		T w;
	};

	template <typename T>
	Vector4<T>::Vector4() :
		x(T()),
		y(T()),
		z(T()),
		w(T())
	{

	}

	template <typename T>
	Vector4<T>::Vector4(const T& aVariable) :
		x(aVariable),
		y(aVariable),
		z(aVariable),
		w(aVariable)
	{

	}

	template <typename T>
	Vector4<T>::Vector4(const T& aX, const T& aY, const T& aZ, const T& aW) :
		x(aX),
		y(aY),
		z(aZ),
		w(aW)
	{

	}

	template <typename T>
	Vector4<T>::Vector4(const Vector3<T>& aVector3, const T& aW) :
		x(aVector3.x),
		y(aVector3.y),
		z(aVector3.z),
		w(aW)
	{

	}

	template <typename T>
	inline bool operator==(const Vector4<T>& aVector0, const Vector4<T>& aVector1)
	{
		return aVector0.x == aVector1.x && aVector0.y == aVector1.y && aVector0.z == aVector1.z && aVector0.w == aVector1.w;
	}
	template <typename T>
	inline bool operator!=(const Vector4<T>& aVector0, const Vector4<T>& aVector1)
	{
		return aVector0.x != aVector1.x && aVector0.y != aVector1.y && aVector0.z != aVector1.z && aVector0.w != aVector1.w;
	}

	template <typename T>
	inline Vector4<T> operator+(const Vector4<T>& aVector0, const Vector4<T>& aVector1)
	{
		return Vector4<T>(aVector0.x + aVector1.x, aVector0.y + aVector1.y, aVector0.z + aVector1.z, aVector0.w + aVector1.w);
	}

	template <typename T>
	inline Vector4<T> operator-(const Vector4<T>& aVector0, const Vector4<T>& aVector1)
	{
		return Vector4<T>(aVector0.x - aVector1.x, aVector0.y - aVector1.y, aVector0.z - aVector1.z, aVector0.w - aVector1.w);
	}

	template <typename T>
	inline Vector4<T>& Vector4<T>::operator-(void)
	{
		x = -x;
		y = -y;
		z = -z;
		w = -w;
		return *this;
	}

	template <typename T>
	inline Vector4<T> operator*(const Vector4<T>& aVector, const T& aScalar)
	{
		return Vector4<T>(aVector.x * aScalar, aVector.y * aScalar, aVector.z * aScalar, aVector.w * aScalar);
	}

	template <typename T>
	inline Vector4<T> operator*(const T& aScalar, const Vector4<T>& aVector)
	{
		return Vector4<T>(aVector.x * aScalar, aVector.y * aScalar, aVector.z * aScalar, aVector.w * aScalar);
	}

	template <typename T>
	Vector4<T> operator/(const Vector4<T>& aVector, const T& aScalar)
	{
		assert(aScalar != 0 && "Division by 0");
		return Vector4<T>(aVector.x / aScalar, aVector.y / aScalar, aVector.z / aScalar, aVector.w / aScalar);
	}

	template <typename T>
	Vector4<float> operator/(const Vector4<float>& aVector, const float& aScalar)
	{
		assert(aScalar != 0 && "Division by 0");
		float result = 1 / aScalar;
		return Vector4<float>(aVector.x * result, aVector.y * result, aVector.z * result, aVector.w * result);
	}

	template <typename T>
	Vector4<double> operator/(const Vector4<double>& aVector, const double& aScalar)
	{
		assert(aScalar != 0 && "Division by 0");
		double result = 1 / aScalar;
		return Vector4<double>(aVector.x * result, aVector.y * result, aVector.z * result, aVector.w * result);
	}

	template <typename T>
	inline void operator+=(Vector4<T>& aVector0, const Vector4<T>& aVector1)
	{
		aVector0 = aVector0 + aVector1;
	}

	template <typename T>
	inline void operator-=(Vector4<T>& aVector0, const Vector4<T>& aVector1)
	{
		aVector0 = aVector0 - aVector1;
	}

	template <typename T>
	inline void operator*=(Vector4<T>& aVector, const T& aScalar)
	{
		aVector.x *= aScalar;
		aVector.y *= aScalar;
		aVector.z *= aScalar;
		aVector.w *= aScalar;
	}

	template <typename T>
	inline void operator/=(Vector4<T>& aVector, const T& aScalar)
	{
		assert(aScalar != 0 && "Division by 0");
		aVector.x /= aScalar;
		aVector.y /= aScalar;
		aVector.z /= aScalar;
		aVector.w /= aScalar;
	}

	template <typename T>
	inline void operator/=(Vector4<float>& aVector, const float& aScalar)
	{
		assert(aScalar != 0 && "Division by 0");
		float result = 1 / aScalar;
		aVector.x *= result;
		aVector.y *= result;
		aVector.z *= result;
		aVector.w *= result;
	}

	template <typename T>
	inline void operator/=(Vector4<double>& aVector, const double& aScalar)
	{
		assert(aScalar != 0 && "Division by 0");
		double result = 1 / aScalar;
		aVector.x *= result;
		aVector.y *= result;
		aVector.z *= result;
		aVector.w *= result;
	}

	template<typename T>
	inline T Vector4<T>::LengthSqr() const
	{
		return x * x + y * y + z * z + w * w;
	}

	template<typename T>
	inline T Vector4<T>::Length() const
	{
		return std::sqrt(x * x + y * y + z * z + w * w);
	}

	template<typename T>
	inline T Vector4<T>::Distance(const Vector4<T>& aVector) const
	{
		T arg1 = x - aVector.x;
		T arg2 = y - aVector.y;
		T arg3 = z - aVector.z;
		T arg4 = w - aVector.w;
		return std::sqrt(arg1 * arg1 + arg2 * arg2 + arg3 * arg3 + arg4 * arg4);
	}

	template<typename T>
	inline T Vector4<T>::DistanceSqr(const Vector4<T>& aVector) const
	{
		T arg1 = x - aVector.x;
		T arg2 = y - aVector.y;
		T arg3 = z - aVector.z;
		T arg4 = w - aVector.w;
		return arg1 * arg1 + arg2 * arg2 + arg3 * arg3 + arg4 * arg4;
	}

	template<typename T>
	inline Vector4<T> Vector4<T>::GetNormalized() const
	{
		assert(std::sqrt(x * x + y * y + z * z + w * w) != 0 && "Division by 0");
		double result = 1 / std::sqrt(x * x + y * y + z * z + w * w);
		return Vector4(x * result, y * result, z * result, w * result);
	}

	template<typename T>
	inline void Vector4<T>::Normalize()
	{
		assert(std::sqrt(x * x + y * y + z * z + w * w) != 0 && "Division by 0");
		double result = 1 / std::sqrt(x * x + y * y + z * z + w * w);
		x *= result;
		y *= result;
		z *= result;
		w *= result;
	}

	template<typename T>
	inline void Vector4<T>::Truncate(T aUpperBound)
	{
		T sqrLen = LengthSqr();
		if (sqrLen > aUpperBound * aUpperBound)
		{
			double multiplier = aUpperBound / std::sqrt(sqrLen);
			x *= multiplier; y *= multiplier;
		}
	}

	template<typename T>
	inline T Vector4<T>::Dot(const Vector4<T>& aVector) const
	{
		return x * aVector.x + y * aVector.y + z * aVector.z + w * aVector.w;
	}

	template <typename T>
	Vector4<T> Vector4<T>::Lerp(const  Vector4<T>& aFrom, const  Vector4<T>& aTO, float aDelta)
	{
		return aFrom + aDelta * (aTO - aFrom);
	}

	using Vector4f = Vector4<float>;
}