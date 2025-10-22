#pragma once
#include "Vector3.hpp"
#include "Math.hpp"

namespace stm
{
	template<typename T>
	class Plane
	{
	public:
		Plane();
		Plane(const Vector3<T>& aPoint0, const Vector3<T>& aPoint1, const Vector3<T>& aPoint2);
		Plane(const Vector3<T>& aPoint0, const Vector3<T>& aNormal);
		~Plane() = default;

		void InitWith3Points(const Vector3<T>& aPoint0, const Vector3<T>& aPoint1, const Vector3<T>& aPoint2);
		void InitWithPointAndNormal(const Vector3<T>& aPoint, const Vector3<T>& aNormal);

		bool Inside(const Vector3<T>& aPosition) const;

		const Vector3<T>& Point() const;
		const Vector3<T>& Normal() const;

	private:
		Vector3<T> m_Point;
		Vector3<T> m_Normal;
	};

	template<typename T>
	inline Plane<T>::Plane() 
		: m_Point(0, 0, 0),
	 	  m_Normal(0, 0, 0)
	{
	}

	template<typename T>
	inline Plane<T>::Plane(const Vector3<T>& aPoint0, const Vector3<T>& aPoint1, const Vector3<T>& aPoint2)
	{
		InitWith3Points(aPoint0, aPoint1, aPoint2);
	}

	template<typename T>
	inline Plane<T>::Plane(const Vector3<T>& aPoint0, const Vector3<T>& aNormal)
	{
		InitWithPointAndNormal(aPoint0, aNormal);
	}

	template<typename T>
	inline void Plane<T>::InitWith3Points(const Vector3<T>& aPoint0, const Vector3<T>& aPoint1, const Vector3<T>& aPoint2)
	{
		m_Point = aPoint0;
		m_Normal = Vector3<T>(aPoint1 - aPoint0).Cross(Vector3<T>(aPoint2 - aPoint0)).GetNormalized();
	}

	template<typename T>
	inline void Plane<T>::InitWithPointAndNormal(const Vector3<T>& aPoint, const Vector3<T>& aNormal)
	{
		m_Point = aPoint;
		m_Normal = aNormal.GetNormalized();
	}

	template<typename T>
	inline bool Plane<T>::Inside(const Vector3<T>& aPosition) const
	{
		return m_Normal.Dot(aPosition - m_Point) <= 0;
	}

	inline bool Plane<float>::Inside(const Vector3<float>& aPosition) const
	{
		return m_Normal.Dot(aPosition - m_Point) <= Math::ELIPSON;
	}

	inline bool Plane<double>::Inside(const Vector3<double>& aPosition) const
	{
		return m_Normal.Dot(aPosition - m_Point) <= Math::ELIPSON_D;
	}

	template<typename T>
	const Vector3<T>& Plane<T>::Point() const
	{
		return m_Point;
	}

	template<typename T>
	const Vector3<T>& Plane<T>::Normal() const
	{
		return m_Normal;
	}
}