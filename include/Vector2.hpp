#pragma once
#include <initializer_list>
#include <assert.h>
#include <cmath>

namespace stm
{
	template <typename T>
	class Vector2
	{
	public:
		Vector2<T>();
		Vector2<T>(const T& aX, const T& aY);
		Vector2<T>(const Vector2<T>& aVector) = default;
		~Vector2<T>() = default;

		inline Vector2<T>& operator=(const Vector2<T>& aVector2) = default;
		inline Vector2<T> operator-(void);

		template <typename OtherT>
		Vector2<T>& operator=(const Vector2<OtherT>& aVector) { x = (T)aVector.x; y = (T)aVector.y; return *this; }

		inline void Set(T aX, T aY) { x = aX; y = aY; }

		inline T LengthSqr() const;
		inline T Length() const;
		inline T Distance(const Vector2<T>& aVector) const;
		inline T DistanceSqr(const Vector2<T>& aVector) const;
		inline Vector2<T> GetNormalized() const;
		inline Vector2<T>& Normalize();
		inline T Dot(const Vector2<T>& aVector) const;

		inline Vector2<T> Normal() const { return Vector2<T>(y, -x); }

		T x;
		T y;
	};

	template <typename T>
	Vector2<T>::Vector2() :
		x(T()),
		y(T())
	{

	}

	template <typename T>
	Vector2<T>::Vector2(const T& aX, const T& aY) :
		x(aX),
		y(aY)
	{

	}

	template <typename T>
	inline bool operator==(const Vector2<T>& aVector0, const Vector2<T>& aVector1)
	{
		return aVector0.x == aVector1.x && aVector0.y == aVector1.y;
	}

	template <typename T>
	inline bool operator!=(const Vector2<T>& aVector0, const Vector2<T>& aVector1)
	{
		return aVector0.x != aVector1.x && aVector0.y != aVector1.y;
	}

	template <typename T>
	inline Vector2<T> operator+(const Vector2<T>& aVector0, const Vector2<T>& aVector1)
	{
		return Vector2<T>(aVector0.x + aVector1.x, aVector0.y + aVector1.y);
	}

	template <typename T>
	inline Vector2<T> operator-(const Vector2<T>& aVector0, const Vector2<T>& aVector1)
	{
		return Vector2<T>(aVector0.x - aVector1.x, aVector0.y - aVector1.y);
	}

	template <typename T>
	inline Vector2<T> operator*(const Vector2<T>& aVector0, const Vector2<T>& aVector1)
	{
		return Vector2<T>(aVector0.x * aVector1.x, aVector0.y * aVector1.y);
	}

	template <typename T>
	inline Vector2<T> operator/(const Vector2<T>& aVector0, const Vector2<T>& aVector1)
	{
		return Vector2<T>(aVector0.x / aVector1.x, aVector0.y / aVector1.y);
	}

	template <typename T>
	inline Vector2<T> Vector2<T>::operator-(void)
	{
		return Vector2<T>(-x, -y);
	}

	template <typename T>
	inline Vector2<T> operator*(const Vector2<T>& aVector, const T& aScalar)
	{
		return Vector2<T>(aVector.x * aScalar, aVector.y * aScalar);
	}

	template <typename T>
	inline Vector2<T> operator*(const T& aScalar, const Vector2<T>& aVector)
	{
		return Vector2<T>(aVector.x * aScalar, aVector.y * aScalar);
	}

	template <typename T>
	Vector2<T> operator/(const Vector2<T>& aVector, const T& aScalar)
	{
		assert(aScalar != 0 && "Division by 0");

		return Vector2<T>(aVector.x / aScalar, aVector.y / aScalar);
	}

	template <typename T>
	Vector2<float> operator/(const Vector2<float>& aVector, const float& aScalar)
	{
		assert(aScalar != 0 && "Division by 0");

		float result = 1 / aScalar;
		return Vector2<float>(aVector.x * result, aVector.y * result);
	}
	template <typename T>
	Vector2<double> operator/(const Vector2<double>& aVector, const double& aScalar)
	{
		assert(aScalar != 0 && "Division by 0");

		double result = 1 / aScalar;
		return Vector2<double>(aVector.x * result, aVector.y * result);
	}

	template <typename T>
	inline void operator+=(Vector2<T>& aVector0, const Vector2<T>& aVector1)
	{
		aVector0 = aVector0 + aVector1;
	}

	template <typename T>
	inline void operator-=(Vector2<T>& aVector0, const Vector2<T>& aVector1)
	{
		aVector0 = aVector0 - aVector1;
	}

	template <typename T>
	inline void operator*=(Vector2<T>& aVector, const T& aScalar)
	{
		aVector.x *= aScalar;
		aVector.y *= aScalar;
	}

	template <typename T>
	inline void operator/=(Vector2<T>& aVector, const T& aScalar)
	{
		assert(aScalar != 0 && "Division by 0");
		aVector.x /= aScalar;
		aVector.y /= aScalar;
	}
	template <typename T>
	inline void operator/=(Vector2<float>& aVector, const float& aScalar)
	{
		assert(aScalar != 0 && "Division by 0");

		float result = 1 / aScalar;
		aVector.x *= result;
		aVector.y *= result;
	}
	template <typename T>
	inline void operator/=(Vector2<double>& aVector, const double& aScalar)
	{
		assert(aScalar != 0 && "Division by 0");

		double result = 1 / aScalar;
		aVector.x *= result;
		aVector.y *= result;
	}

	template<typename T>
	inline T Vector2<T>::LengthSqr() const
	{
		return x * x + y * y;
	}

	template<typename T>
	inline T Vector2<T>::Length() const
	{
		return std::sqrt(x * x + y * y);
	}

	template<typename T>
	inline T Vector2<T>::Distance(const Vector2<T>& aVector) const
	{
		T arg1 = x - aVector.x;
		T arg2 = y - aVector.y;
		return std::sqrt(arg1 * arg1 + arg2 * arg2);
	}

	template<typename T>
	inline T Vector2<T>::DistanceSqr(const Vector2<T>& aVector) const
	{
		T arg1 = x - aVector.x;
		T arg2 = y - aVector.y;
		return arg1 * arg1 + arg2 * arg2;
	}

	template<typename T>
	inline Vector2<T> Vector2<T>::GetNormalized() const
	{
		assert(std::sqrt(x * x + y * y) != 0 && "Division by 0");

		double result = 1 / std::sqrt(x * x + y * y);
		return Vector2(x * result, y * result);
	}

	template<typename T>
	inline Vector2<T>& Vector2<T>::Normalize()
	{
		assert(std::sqrt(x * x + y * y) != 0 && "Division by 0");

		double result = 1 / std::sqrt(x * x + y * y);
		x *= result;
		y *= result;

		return *this;
	}

	template<typename T>
	inline T Vector2<T>::Dot(const Vector2<T>& aVector) const
	{
		return x * aVector.x + y * aVector.y;
	}

	using Vector2f = Vector2<float>;
}