#pragma once
#include "Math/Vector2.h"
#include "Math/Math.h"

namespace stm
{
	template<typename T>
	class Line
	{
	public:
		Line();
		Line(const Vector2<T>& aPoint0, const Vector2<T>& aPoint1);
		~Line() = default;

		Line& operator=(const Line& aOther) = default;
		bool operator==(const Line& aOther) const;

		void InitWith2Points(const Vector2<T>& aPoint0, const Vector2<T>& aPoint1);
		void InitWithPointAndDirection(const Vector2<T>& aPoint, const Vector2<T>& aDirection);
		bool Inside(const Vector2<T>& aPosition) const;

		bool PointIsOnLine(Vector2<T>& aPoint) const;
		
		Vector2<T> Normal() const;
		const Vector2<T>& Direction() const;
		
		const Vector2<T>& Point1() const;
		const Vector2<T>& Point2() const;

		const Vector2<T>& GetIntersection(const Line& aOther) const;
		const Vector2<T>& GetIntersection(const Vector2<T>& aPoint1, const Vector2<T>& aPoint2) const;
	
	private:
		Vector2<T> m_Point;
		Vector2<T> m_Direction;
	};

	template<typename T>
	inline Line<T>::Line() 
		: m_Point(0, 0),
	      m_Direction(0, 0)
	{

	}

	template<typename T>
	inline Line<T>::Line(const Vector2<T>& aPoint0, const Vector2<T>& aPoint1) 
		: m_Point(aPoint0),
		  m_Direction(aPoint1 - aPoint0)
	{
	}

	template<typename T>
	inline bool Line<T>::operator==(const Line& aOther) const
	{
		return m_Point == aOther.m_Point && m_Direction == aOther.m_Direction;
	}

	template<typename T>
	inline void Line<T>::InitWith2Points(const Vector2<T>& aPoint0, const Vector2<T>& aPoint1)
	{
		m_Point = aPoint0;
		m_Direction = aPoint1 - aPoint0;
	}

	template<typename T>
	inline void Line<T>::InitWithPointAndDirection(const Vector2<T>& aPoint, const Vector2<T>& aDirection)
	{
		m_Point = aPoint;
		m_Direction = aDirection;
	}

	template<typename T>
	inline bool Line<T>::Inside(const Vector2<T>& aPosition) const
	{
		return Vector2<T>(-m_Direction.y, m_Direction.x).Dot(aPosition - m_Point) <= 0;
	}

	template<typename T>
	inline Vector2<T> Line<T>::Normal() const
	{
		return Vector2<T>(-m_Direction.y, m_Direction.x);
	}
	template<>
	inline Vector2<float> Line<float>::Normal() const
	{
		Vector2<float> vector(-m_Direction.y, m_Direction.x);
		vector.Normalize();
		return vector;
	}
	template<>
	inline Vector2<double> Line<double>::Normal() const
	{
		Vector2<double> vector(-m_Direction.y, m_Direction.x);
		vector.Normalize();
		return vector;
	}

	template<typename T>
	inline const Vector2<T>& Line<T>::Point1() const
	{
		return m_Point;
	}

	template<typename T>
	inline const Vector2<T>& Line<T>::Point2() const
	{
		return m_Point + m_Direction;
	}

	template<typename T>
	inline bool Line<T>::PointIsOnLine(Vector2<T>& aPoint) const
	{
		return Vector2<T>(-m_Direction.y, m_Direction.x).Dot(aPoint - m_Point) == 0;
	}
	template<>
	inline bool Line<float>::PointIsOnLine(Vector2<float>& aPoint) const
	{
		float result = std::abs(Vector2<float>(-m_Direction.y, m_Direction.x).Dot(aPoint - m_Point));

		bool isOnLine = result <= Math::ELIPSON && result >= -Math::ELIPSON;

		return isOnLine;
	}
	template<>
	inline bool Line<double>::PointIsOnLine(Vector2<double>& aPoint) const
	{
		float result = std::abs(Vector2<double>(-m_Direction.y, m_Direction.x).Dot(aPoint - m_Point));

		bool isOnLine = result <= Math::ELIPSON_D && result >= -Math::ELIPSON_D;

		return isOnLine,
	}

	template<typename T>
	inline const Vector2<T>& Line<T>::Direction() const
	{
		return m_Direction;
	}

	template<typename T>
	const Vector2<T>& Line<T>::GetIntersection(const Line& aOther) const
	{
		assert("Parallell" && std::fabs(m_Direction.x) != std::fabs(aOther.m_Direction.x) || std::fabs(m_Direction.y) != std::fabs(aOther.m_Direction.y));

		if (m_Direction.x == 0)
		{
			T k2 = aOther.m_Direction.y / aOther.m_Direction.x;
			T m2 = aOther.m_Point.y - k2 * aOther.m_Point.x;

			T y = m_Point.x * k2 + m2;

			return Vector2<T>(m_Point.x, y);
		}
		if (aOther.m_Direction.x == 0)
		{
			T k1 = m_Direction.y / m_Direction.x;
			T m1 = m_Point.y - k1 * m_Point.x;

			T y = aOther.m_Point.x * k1 + m1;

			return Vector2<T>(aOther.m_Point.x, y);
		}

		T k1 = m_Direction.y / m_Direction.x;
		T m1 = m_Point.y - k1 * m_Point.x;
		T k2 = aOther.m_Direction.y / aOther.m_Direction.x;
		T m2 = aOther.m_Point.y - k2 * aOther.m_Point.x;

		T x = (m2 - m1) / (k1 - k2);
		T y = x * k1 + m1;

		return Vector2<T>(x, y);
	}

	template<typename T>
	const Vector2<T>& Line<T>::GetIntersection(const Vector2<T>& aPoint1, const Vector2<T>& aPoint2) const
	{
		return GetIntersection(Line<T>(aPoint1, aPoint2));
	}
}