#pragma once

#include "Plane.hpp"
#include "SimpleList.hpp"
#include "Matrix4x4.hpp"

namespace stm
{
	template<typename T>
	class PlaneVolume
	{
	public:
		PlaneVolume() = default;
		PlaneVolume(const SimpleList<Plane<T>>& aPlaneList);

		void AddPlane(const Plane<T>& aPlane);

		bool Inside(const Vector3<T>& aPosition);

		const std::size_t Size() const;

		const SimpleList<Plane<T>>& GetPlanes();

	private:
		template<typename T>
		friend inline PlaneVolume<T> operator*(const PlaneVolume<T>& aPlaneVolume, const Matrix4x4<T>& aMatrix);

		SimpleList<Plane<T>> m_Data;
	};

	template<typename T>
	inline PlaneVolume<T>::PlaneVolume(const SimpleList<Plane<T>>& aPlaneList)
	{
		m_Data = aPlaneList;
	}

	template<typename T>
	inline void PlaneVolume<T>::AddPlane(const Plane<T>& aPlane)
	{
		m_Data.push_back(aPlane);
	}
	
	template<typename T>
	inline bool PlaneVolume<T>::Inside(const Vector3<T>& aPosition)
	{
		for (auto& iterator : m_Data)
		{
			if (!iterator.Inside(aPosition))
			{
				return false;
			}
		}

		return true;
	}

	template<typename T>
	inline const std::size_t PlaneVolume<T>::Size() const
	{
		return m_Data.Size();
	}

	template<typename T>
	inline const SimpleList<Plane<T>>& PlaneVolume<T>::GetPlanes()
	{
		return m_Data;
	}

	template<typename T>
	PlaneVolume<T> operator*(const PlaneVolume<T>& aPlaneVolume, const Matrix4x4<T>& aMatrix)
	{
		PlaneVolume<T> returnValue;
		for (int i = 0; i < aPlaneVolume.m_Data.Size(); i++)
		{
			Vector4<T> point4 = *(Vector4<T>*) & aPlaneVolume.m_Data[i].Point();
			point4.w = 1.f;
			Vector4<T> normal4 = *(Vector4<T>*) & aPlaneVolume.m_Data[i].Normal();
			normal4.w = 0.f;

			returnValue.AddPlane(Plane<T>(*(Vector3<T>*) & (point4 * aMatrix), *(Vector3<T>*) & (normal4 * aMatrix)));
		}
		return returnValue;
	}
}