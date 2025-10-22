#pragma once
#include "Vector3.hpp"

namespace stm
{
	template<typename T>
	class AABB3D
	{
	public:
		AABB3D();
		AABB3D(const AABB3D<T>& aAABB3D);
		AABB3D(const Vector3<T>& aMin, const Vector3<T>& aMax);

		void InitWithMinAndMax(const Vector3<T>& aMin, const Vector3<T>& aMax);

		bool IsInside(const Vector3<T>& aPosition) const;

		Vector3<T>& Min();
		const Vector3<T>& Min() const;

		Vector3<T>& Max();
		const Vector3<T>& Max() const;

	private:
		Vector3<T> m_Min;
		Vector3<T> m_Max;
	};

	template<typename T>
	inline AABB3D<T>::AABB3D()
	{

	}

	template<typename T>
	inline AABB3D<T>::AABB3D(const AABB3D<T>& aAABB3D) :
		m_Min(aAABB3D.m_Min),
		m_Max(aAABB3D.m_Max)
	{
	}

	template<typename T>
	inline AABB3D<T>::AABB3D(const Vector3<T>& aMin, const Vector3<T>& aMax) :
		m_Min(aMin),
		m_Max(aMax)
	{
	}

	template<typename T>
	inline void AABB3D<T>::InitWithMinAndMax(const Vector3<T>& aMin, const Vector3<T>& aMax)
	{
		m_Min = aMin;
		m_Max = aMax;
	}

	template<typename T>
	inline Vector3<T>& AABB3D<T>::Min()
	{
		return m_Min;
	}

	template<typename T>
	inline const Vector3<T>& AABB3D<T>::Min() const
	{
		return m_Min;
	}

	template<typename T>
	inline Vector3<T>& AABB3D<T>::Max()
	{
		return m_Max;
	}

	template<typename T>
	inline const Vector3<T>& AABB3D<T>::Max() const
	{
		return m_Max;
	}

	template<typename T>
	inline bool AABB3D<T>::IsInside(const Vector3<T>& aPosition) const
	{
		return
			aPosition.x >= m_Min.x && aPosition.x <= m_Max.x &&
			aPosition.y >= m_Min.y && aPosition.y <= m_Max.y &&
			aPosition.z >= m_Min.z && aPosition.z <= m_Max.z;
	}
}