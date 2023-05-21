#pragma once
#include "Math/Vector3.h"

namespace stm
{
	template<typename T>
	class Sphere
	{
	public:
		Sphere();
		Sphere(const Sphere<T>& aSphere);
		Sphere(const Vector3<T>& aCenter, T aRadius);

		void InitWithCenterAndRadius(const Vector3<T>& aCenter, T aRadius);
		bool IsInside(const Vector3<T>& aPosition) const;

		T Radius() const;
		const Vector3<T>& Position() const;
	private:
		Vector3<T> m_Position;
		T m_Radius;
	};

	template<typename T>
	inline Sphere<T>::Sphere() 
		: m_Radius(0)
	{

	}

	template<typename T>
	inline Sphere<T>::Sphere(const Sphere<T>& aSphere) 
		: m_Radius(aSphere.m_Radius),
		  m_Position(aSphere.m_Position)
	{

	}

	template<typename T>
	inline Sphere<T>::Sphere(const Vector3<T>& aCenter, T aRadius) 
		: m_Position(aCenter),
		  m_Radius(aRadius)
	{

	}

	template<typename T>
	inline void Sphere<T>::InitWithCenterAndRadius(const Vector3<T>& aCenter, T aRadius)
	{
		m_Position = aCenter;
		m_Radius = aRadius;
	}

	template<typename T>
	inline T Sphere<T>::Radius() const
	{
		return m_Radius;
	}

	template<typename T>
	inline const Vector3<T>& Sphere<T>::Position() const
	{
		return m_Position;
	}

	template<typename T>
	inline bool Sphere<T>::IsInside(const Vector3<T>& aPosition) const
	{
		T distance = (aPosition.x - m_Position.x) + (aPosition.y - m_Position.y) + (aPosition.z - m_Position.z);
		return distance * distance <= m_Radius * m_Radius;
	}
}