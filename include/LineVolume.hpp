#pragma once

#include "Line.hpp"
#include "SimpleList.hpp"

namespace stm
{
	template<typename T>
	class LineVolume
	{
	public:
		LineVolume() = default;
		LineVolume(const SimpleList<Line<T>>& aLineList);

		void AddLine(const Line<T>& aLine);

		bool Inside(const Vector2<T>& aPosition);

		const std::size_t Size() const;

	private:
		SimpleList<Line<T>> m_Data;
	};

	template<typename T>
	inline LineVolume<T>::LineVolume(const SimpleList<Line<T>>& aLineList)
	{
		m_Data = aLineList;
	}

	template<typename T>
	inline void LineVolume<T>::AddLine(const Line<T>& aLine)
	{
		m_Data.push_back(aLine);
	}

	template<typename T>
	inline bool LineVolume<T>::Inside(const Vector2<T>& aPosition)
	{
		for (auto i = 0; i < m_Data.Size(); i++)
		{
			auto iterator = m_Data[i];

			if (!iterator.Inside(aPosition))
				return false;
		}

		return true;
	}

	template<typename T>
	inline const std::size_t LineVolume<T>::Size() const
	{
		return m_Data.Size();
	}
}