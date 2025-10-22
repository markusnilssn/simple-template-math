#pragma once
#include <initializer_list>
#include <assert.h>
#include <cmath>

namespace stm
{
	template <typename T>
	class Vector3
	{
	public:
		static Vector3<T> Up()
		{
			return Vector3<T>(0, 1, 0);
		}
		static Vector3<T> Down()
		{
			return Vector3<T>(0, -1, 0);
		}
		static Vector3<T> Right()
		{
			return Vector3<T>(1, 0, 0);
		}
		static Vector3<T> Left()
		{
			return Vector3<T>(-1, 0, 0);
		}
		static Vector3<T> Forward()
		{
			return Vector3<T>(0, 0, 1);
		}
		static Vector3<T> Back()
		{
			return Vector3<T>(0, 0, -1);
		}

	public:
		Vector3<T>();
		Vector3<T>(const T& aX, const T& aY, const T& aZ);
		Vector3<T>(const Vector3<T>& aVector) = default;

		~Vector3<T>() = default;

		inline Vector3<T>& operator=(const Vector3<T>& aVector3) = default;
		inline Vector3<T> operator-(void);

		inline T LengthSqr() const;
		inline T Length() const;
		inline T Distance(const Vector3<T>& aVector) const;
		inline T DistanceSqr(const Vector3<T>& aVector) const;
		inline Vector3<T> GetNormalized() const;
		inline void Normalize();
		inline void Truncate(T aUpperBound);
		inline T Dot(const Vector3<T>& aVector) const;
		inline Vector3<T> Cross(const Vector3<T>& aVector) const;
		static Vector3<T> Lerp(const Vector3<T>& A, const Vector3<T>& B, float aDelta);

		T x;
		T y;
		T z;
	};

	template <typename T>
	Vector3<T>::Vector3() :
		x(T()),
		y(T()),
		z(T())
	{

	}

	template <typename T>
	Vector3<T>::Vector3(const T& aX, const T& aY, const T& aZ) :
		x(aX),
		y(aY),
		z(aZ)
	{

	}

	template <typename T>
	inline bool operator==(const Vector3<T>& aVector0, const Vector3<T>& aVector1)
	{
		return aVector0.x == aVector1.x && aVector0.y == aVector1.y && aVector0.z == aVector1.z;
	}

	template <typename T>
	inline bool operator!=(const Vector3<T>& aVector0, const Vector3<T>& aVector1)
	{
		return aVector0.x != aVector1.x && aVector0.y != aVector1.y && aVector0.z != aVector1.z;
	}

	template <typename T>
	inline Vector3<T> operator+(const Vector3<T>& aVector0, const Vector3<T>& aVector1)
	{
		return Vector3<T>(aVector0.x + aVector1.x, aVector0.y + aVector1.y, aVector0.z + aVector1.z);
	}

	template <typename T>
	inline Vector3<T> operator-(const Vector3<T>& aVector0, const Vector3<T>& aVector1)
	{
		return Vector3<T>(aVector0.x - aVector1.x, aVector0.y - aVector1.y, aVector0.z - aVector1.z);
	}

	template <typename T>
	inline Vector3<T> Vector3<T>::operator-(void)
	{
		return Vector3<T>(-x, -y, -z);
	}

	template <typename T>
	inline Vector3<T> operator*(const Vector3<T>& aVector, const T& aScalar)
	{
		return Vector3<T>(aVector.x * aScalar, aVector.y * aScalar, aVector.z * aScalar);
	}

	template <typename T>
	inline Vector3<T> operator*(const T& aScalar, const Vector3<T>& aVector)
	{
		return Vector3<T>(aVector.x * aScalar, aVector.y * aScalar, aVector.z * aScalar);
	}

	template <typename T>
	Vector3<T> operator/(const Vector3<T>& aVector, const T& aScalar)
	{
		assert(aScalar != 0 && "Division by 0");

		return Vector3<T>(aVector.x / aScalar, aVector.y / aScalar, aVector.z / aScalar);
	}
	template <typename T>
	Vector3<float> operator/(const Vector3<float>& aVector, const float& aScalar)
	{
		assert(aScalar != 0 && "Division by 0");
		float result = 1 / aScalar;
		return Vector3<float>(aVector.x * result, aVector.y * result, aVector.z * result);
	}
	template <typename T>
	Vector3<double> operator/(const Vector3<double>& aVector, const double& aScalar)
	{
		assert(aScalar != 0 && "Division by 0");

		double result = 1 / aScalar;
		return Vector3<double>(aVector.x * result, aVector.y * result, aVector.z * result);
	}

	template <typename T>
	inline void operator+=(Vector3<T>& aVector0, const Vector3<T>& aVector1)
	{
		aVector0 = aVector0 + aVector1;
	}

	template <typename T>
	inline void operator-=(Vector3<T>& aVector0, const Vector3<T>& aVector1)
	{
		aVector0 = aVector0 - aVector1;
	}

	template <typename T>
	inline void operator*=(Vector3<T>& aVector, const T& aScalar)
	{
		aVector.x *= aScalar;
		aVector.y *= aScalar;
		aVector.z *= aScalar;
	}

	template <typename T>
	inline void operator/=(Vector3<T>& aVector, const T& aScalar)
	{
		assert(aScalar != 0 && "Division by 0");

		aVector.x /= aScalar;
		aVector.y /= aScalar;
		aVector.z /= aScalar;
	}
	template <typename T>
	inline void operator/=(Vector3<float>& aVector, const float& aScalar)
	{
		assert(aScalar != 0 && "Division by 0");

		float result = 1 / aScalar;
		aVector.x *= result;
		aVector.y *= result;
		aVector.z *= result;
	}
	template <typename T>
	inline void operator/=(Vector3<double>& aVector, const double& aScalar)
	{
		assert(aScalar != 0 && "Division by 0");

		double result = 1 / aScalar;
		aVector.x *= result;
		aVector.y *= result;
		aVector.z *= result;
	}

	template<typename T>
	inline T Vector3<T>::LengthSqr() const
	{
		return x * x + y * y + z * z;
	}

	template<typename T>
	inline T Vector3<T>::Length() const
	{
		return std::sqrt(x * x + y * y + z * z);
	}

	template<typename T>
	inline T Vector3<T>::Distance(const Vector3<T>& aVector) const
	{
		T arg1 = x - aVector.x;
		T arg2 = y - aVector.y;
		T arg3 = z - aVector.z;
		return std::sqrt(arg1 * arg1 + arg2 * arg2 + arg3 * arg3);
	}

	template<typename T>
	inline T Vector3<T>::DistanceSqr(const Vector3<T>& aVector) const
	{
		T arg1 = x - aVector.x;
		T arg2 = y - aVector.y;
		T arg3 = z - aVector.z;
		return arg1 * arg1 + arg2 * arg2 + arg3 * arg3;
	}

	template<typename T>
	inline Vector3<T> Vector3<T>::GetNormalized() const
	{
		assert(x * x + y * y + z * z != 0 && "Division by 0");

		double result = 1 / std::sqrt(x * x + y * y + z * z);
		return Vector3(x * result, y * result, z * result);
	}

	template<typename T>
	inline void Vector3<T>::Normalize()
	{
		assert(std::sqrt(x * x + y * y + z * z) != 0 && "Division by 0");

		double result = 1 / std::sqrt(x * x + y * y + z * z);
		x *= result;
		y *= result;
		z *= result;
	}

	template<typename T>
	inline void Vector3<T>::Truncate(T aUpperBound)
	{
		T sqrLen = LengthSqr();
		if (sqrLen > aUpperBound * aUpperBound)
		{
			double multiplier = aUpperBound / std::sqrt(sqrLen);
			x *= multiplier; y *= multiplier;
		}
	}

	template<typename T>
	inline T Vector3<T>::Dot(const Vector3<T>& aVector) const
	{
		return x * aVector.x + y * aVector.y + z * aVector.z;
	}

	template<typename T>
	inline Vector3<T> Vector3<T>::Cross(const Vector3<T>& aVector) const
	{
		return Vector3(y * aVector.z - z * aVector.y, z * aVector.x - x * aVector.z, x * aVector.y - y * aVector.x);
	}

	template <typename T>
	Vector3<T> Vector3<T>::Lerp(const  Vector3<T>& a, const  Vector3<T>& b, float aDelta)
	{
		return a + aDelta * (b - a);
	}

	using Vector3f = Vector3<float>;
}