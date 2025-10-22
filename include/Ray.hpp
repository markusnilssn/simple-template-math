#pragma once
#include "Vector3.hpp"

namespace stm
{
	template<typename T>
	class Ray
	{
	public:
		Ray();
		Ray(const Ray<T>& aRay);
		Ray(const Vector3<T>& aOrigin, const Vector3<T>& aPoint);

		void InitWith2Points(const Vector3<T>& aOrigin, const Vector3<T>& aPoint);
		void InitWithOriginAndDirection(const Vector3<T>& aOrigin, const Vector3<T>& aDirection);

		const Vector3<T>& GetPosition() const;
		const Vector3<T>& GetDirection() const;
	private:

		Vector3<T> m_Position;
		Vector3<T> m_Direction;
	};

	template<typename T>
	inline Ray<T>::Ray()
	{
		m_Direction = Vector3f(0, 0, 1);
		m_Position = Vector3f();
	}

	template<typename T>
	inline Ray<T>::Ray(const Ray<T>& aRay) :
		m_Position(aRay.m_Position),
		m_Direction(aRay.m_Direction)
	{
	}

	template<typename T>
	inline Ray<T>::Ray(const Vector3<T>& aOrigin, const Vector3<T>& aPoint) :
		m_Position(aOrigin),
		m_Direction(aPoint - aOrigin)
	{
	}

	template<typename T>
	inline void Ray<T>::InitWith2Points(const Vector3<T>& aOrigin, const Vector3<T>& aPoint)
	{
		m_Position = aOrigin;
		m_Direction = aPoint - aOrigin;
	}
	
	template<typename T>
	inline void Ray<T>::InitWithOriginAndDirection(const Vector3<T>& aOrigin, const Vector3<T>& aDirection)
	{
		m_Position = aOrigin;
		m_Direction = aDirection;
	}

	template<typename T>
	inline const Vector3<T>& Ray<T>::GetPosition() const
	{
		return m_Position;
	}

	template<typename T>
	inline const Vector3<T>& Ray<T>::GetDirection() const
	{
		return m_Direction;
	}
}