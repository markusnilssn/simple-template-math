#pragma once
#include <cassert>
#include <memory>

namespace stm
{
	template<typename T>
	class SimpleList
	{
	public:
		SimpleList();
		~SimpleList();

		void Add(const T aData);
		void Add(T&& aData);

		void Remove(const T aData);

		const T& ElementAt(const std::size_t aIndex) const;
		T& ElementAt(const std::size_t aIndex);

		const T& operator[](const size_t aIndex) const;
		T& operator[](const size_t aIndex);

		const std::size_t Size() const;
		const std::size_t Capacity() const;

	private:
		T* m_Data;
		std::size_t m_Size;
		std::size_t m_Capacity;

	};
	template<typename T>
	inline SimpleList<T>::SimpleList()
	{
		m_Data = new T[4];
		m_Size = 0;
		m_Capacity = 4;
	}

	template<typename T>
	inline SimpleList<T>::~SimpleList()
	{
		delete[] m_Data;
	}

	template<typename T>
	inline void SimpleList<T>::Add(const T aData)
	{
		if (m_Size == m_Capacity)
		{
			m_Capacity *= 2;
			T* newData = new T[m_Capacity];
			for (size_t i = 0; i < m_Size; i++)
			{
				newData[i] = m_Data[i];
			}
			delete[] m_Data;
			m_Data = newData;
		}
		m_Data[(int)m_Size] = aData;
		m_Size++;
	}

	template<typename T>
	inline void SimpleList<T>::Add(T&& aData)
	{
		if (m_Size == m_Capacity)
		{
			m_Capacity *= 2;
			T* newData = new T[m_Capacity];
			for (size_t i = 0; i < m_Size; i++)
			{
				newData[i] = m_Data[i];
			}
			delete[] m_Data;
			m_Data = newData;
		}
		m_Data[(int)m_Size] = aData;
		m_Size++;
	}

	template<typename T>
	inline void SimpleList<T>::Remove(const T aData)
	{
		if (aIndex >= m_Size)
		{
			return;
		}
		for (size_t i = aIndex; i < m_Size - 1; i++)
		{
			m_Data[i] = m_Data[i + 1];
		}
		m_Size--;
	}

	template<typename T>
	inline const T& SimpleList<T>::operator[](const size_t aIndex) const
	{
		assert(aIndex < m_Size);
		assert(aIndex >= 0);

		return m_Data[aIndex];
	}

	template<typename T>
	inline T& SimpleList<T>::operator[](const size_t aIndex)
	{
		assert(aIndex < m_Size);
		assert(aIndex >= 0);

		return m_Data[aIndex];
	}

	template<typename T>
	inline const T& SimpleList<T>::ElementAt(const std::size_t aIndex) const
	{
		assert(aIndex < m_Size);
		assert(aIndex >= 0);

		return m_Data[aIndex];
	}

	template<typename T>
	inline T& SimpleList<T>::ElementAt(const std::size_t aIndex)
	{
		assert(aIndex < m_Size);
		assert(aIndex >= 0);

		return m_Data[aIndex];
	}

	template<typename T>
	inline const std::size_t SimpleList<T>::Size() const
	{
		return m_Size;
	}

	template<typename T>
	inline const std::size_t SimpleList<T>::Capacity() const
	{
		return m_Capacity
	}
}