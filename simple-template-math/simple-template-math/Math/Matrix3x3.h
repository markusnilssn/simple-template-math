#pragma once
#include "Vector3.h"

namespace stm
{
	template<typename T>
	class Matrix4x4;

	template<typename T>
	class Matrix3x3
	{
		template<typename T>
		friend inline Vector3<T> operator*(const Vector3<T>& aVector, const Matrix3x3<T>& aMatrix);

	public:
		Matrix3x3<T>();
		Matrix3x3<T>(const Matrix3x3<T>& aMatrix);
		Matrix3x3<T>(const Matrix4x4<T>& aMatrix);

		inline T& operator()(const int row, const int column);
		inline const T& operator()(const int row, const int column) const;
		inline Matrix3x3<T>& operator+=(const Matrix3x3& aOther);
		inline Matrix3x3<T>& operator-=(const Matrix3x3& aOther);
		inline Matrix3x3<T>& operator*=(const Matrix3x3& aOther);
		inline bool operator==(const Matrix3x3& aOther) const;
		inline Matrix3x3<T>& operator=(const Matrix3x3& aOther);

		static inline Matrix3x3<T> CreateRotationAroundX(T aAngleInRadians);
		static inline Matrix3x3<T> CreateRotationAroundY(T aAngleInRadians);
		static inline Matrix3x3<T> CreateRotationAroundZ(T aAngleInRadians);
		static inline Matrix3x3<T> Transpose(const Matrix3x3<T>& aMatrixToTranspose);
	private:
		T m_Data[9];
	};

	template<typename T>
	Matrix3x3<T>::Matrix3x3() 
		: m_Data{ 1, 0, 0, 0, 1, 0, 0, 0, 1 }
	{
	}

	template<typename T>
	Matrix3x3<T>::Matrix3x3(const Matrix3x3<T>& aMatrix) 
		: m_Data{
			aMatrix.m_Data[0], aMatrix.m_Data[1], aMatrix.m_Data[2],
			aMatrix.m_Data[3], aMatrix.m_Data[4], aMatrix.m_Data[5],
			aMatrix.m_Data[6], aMatrix.m_Data[7], aMatrix.m_Data[8]
	}
	{

	}

	template<typename T>
	Matrix3x3<T>::Matrix3x3(const Matrix4x4<T>& aMatrix) 
		: m_Data{
			aMatrix.m_Data[0], aMatrix.m_Data[1], aMatrix.m_Data[2],
			aMatrix.m_Data[4], aMatrix.m_Data[5], aMatrix.m_Data[6],
			aMatrix.m_Data[8], aMatrix.m_Data[9], aMatrix.m_Data[10]
	}
	{

	}

	template<typename T>
	inline T& Matrix3x3<T>::operator()(const int aRow, const int aColumn)
	{
		assert(aRow >= 0 && aRow <= 3 && "Row out of bounds");
		assert(aColumn >= 0 && aColumn <= 3 && "Column out of bounds");

		return m_Data[(aRow - 1) * 3 + (aColumn - 1)];
	}

	template<typename T>
	inline const T& Matrix3x3<T>::operator()(const int aRow, const int aColumn) const
	{
		assert(aRow >= 0 && aRow <= 3 && "Row out of bounds");
		assert(aColumn >= 0 && aColumn <= 3 && "Column out of bounds");

		return m_Data[(aRow - 1) * 3 + (aColumn - 1)];
	}

	template<typename T>
	inline Matrix3x3<T>& Matrix3x3<T>::operator+=(const Matrix3x3<T>& aOther)
	{
		this->m_Data[0] += aOther.m_Data[0];
		this->m_Data[1] += aOther.m_Data[1];
		this->m_Data[2] += aOther.m_Data[2];
		this->m_Data[3] += aOther.m_Data[3];
		this->m_Data[4] += aOther.m_Data[4];
		this->m_Data[5] += aOther.m_Data[5];
		this->m_Data[6] += aOther.m_Data[6];
		this->m_Data[7] += aOther.m_Data[7];
		this->m_Data[8] += aOther.m_Data[8];
		return *this;
	}

	template<typename T>
	inline Matrix3x3<T> operator+(const Matrix3x3<T>& aLeft, const Matrix3x3<T>& aRight)
	{
		Matrix3x3<T> matrix(aLeft);
		matrix += aRight;
		return matrix;
	}

	template<typename T>
	inline Matrix3x3<T>& Matrix3x3<T>::operator-=(const Matrix3x3<T>& aOther)
	{
		this->m_Data[0] -= aOther.m_Data[0];
		this->m_Data[1] -= aOther.m_Data[1];
		this->m_Data[2] -= aOther.m_Data[2];
		this->m_Data[3] -= aOther.m_Data[3];
		this->m_Data[4] -= aOther.m_Data[4];
		this->m_Data[5] -= aOther.m_Data[5];
		this->m_Data[6] -= aOther.m_Data[6];
		this->m_Data[7] -= aOther.m_Data[7];
		this->m_Data[8] -= aOther.m_Data[8];
		return *this;
	}

	template<typename T>
	inline Matrix3x3<T> operator-(const Matrix3x3<T>& aLeft, const Matrix3x3<T>& aRight)
	{
		Matrix3x3<T> matrix(aLeft);
		matrix -= aRight;
		return matrix;
	}

	template<typename T>
	inline Matrix3x3<T>& Matrix3x3<T>::operator*=(const Matrix3x3<T>& aOther)
	{
		T data[9];
		data[0] = this->m_Data[0] * aOther.m_Data[0] + this->m_Data[1] * aOther.m_Data[3] + this->m_Data[2] * aOther.m_Data[6];
		data[1] = this->m_Data[0] * aOther.m_Data[1] + this->m_Data[1] * aOther.m_Data[4] + this->m_Data[2] * aOther.m_Data[7];
		data[2] = this->m_Data[0] * aOther.m_Data[2] + this->m_Data[1] * aOther.m_Data[5] + this->m_Data[2] * aOther.m_Data[8];
		data[3] = this->m_Data[3] * aOther.m_Data[0] + this->m_Data[4] * aOther.m_Data[3] + this->m_Data[5] * aOther.m_Data[6];
		data[4] = this->m_Data[3] * aOther.m_Data[1] + this->m_Data[4] * aOther.m_Data[4] + this->m_Data[5] * aOther.m_Data[7];
		data[5] = this->m_Data[3] * aOther.m_Data[2] + this->m_Data[4] * aOther.m_Data[5] + this->m_Data[5] * aOther.m_Data[8];
		data[6] = this->m_Data[6] * aOther.m_Data[0] + this->m_Data[7] * aOther.m_Data[3] + this->m_Data[8] * aOther.m_Data[6];
		data[7] = this->m_Data[6] * aOther.m_Data[1] + this->m_Data[7] * aOther.m_Data[4] + this->m_Data[8] * aOther.m_Data[7];
		data[8] = this->m_Data[6] * aOther.m_Data[2] + this->m_Data[7] * aOther.m_Data[5] + this->m_Data[8] * aOther.m_Data[8];
		m_Data[0] = data[0];
		m_Data[1] = data[1];
		m_Data[2] = data[2];
		m_Data[3] = data[3];
		m_Data[4] = data[4];
		m_Data[5] = data[5];
		m_Data[6] = data[6];
		m_Data[7] = data[7];
		m_Data[8] = data[8];
		return *this;
	}

	template<typename T>
	inline Matrix3x3<T> operator*(const Matrix3x3<T>& aLeft, const Matrix3x3<T>& aRight)
	{
		Matrix3x3<T> matrix(aLeft);
		matrix *= aRight;
		return matrix;
	}

	template<typename T>
	inline bool Matrix3x3<T>::operator==(const Matrix3x3& aOther) const
	{
		return
			this->m_Data[0] == aOther.m_Data[0] && this->m_Data[1] == aOther.m_Data[1] && this->m_Data[2] == aOther.m_Data[2] &&
			this->m_Data[3] == aOther.m_Data[3] && this->m_Data[4] == aOther.m_Data[4] && this->m_Data[5] == aOther.m_Data[5] &&
			this->m_Data[6] == aOther.m_Data[6] && this->m_Data[7] == aOther.m_Data[7] && this->m_Data[8] == aOther.m_Data[8];
	}

	template<typename T>
	inline Matrix3x3<T>& Matrix3x3<T>::operator=(const Matrix3x3& aOther)
	{
		m_Data[0] = aOther.m_Data[0];
		m_Data[1] = aOther.m_Data[1];
		m_Data[2] = aOther.m_Data[2];
		m_Data[3] = aOther.m_Data[3];
		m_Data[4] = aOther.m_Data[4];
		m_Data[5] = aOther.m_Data[5];
		m_Data[6] = aOther.m_Data[6];
		m_Data[7] = aOther.m_Data[7];
		m_Data[8] = aOther.m_Data[8];
		return *this;
	}

	template<typename T>
	inline Vector3<T> operator*(const Vector3<T>& aVector, const Matrix3x3<T>& aMatrix)
	{
		return Vector3<T>(
			aVector.x * aMatrix.m_Data[0] + aVector.y * aMatrix.m_Data[3] + aVector.z * aMatrix.m_Data[6],
			aVector.x * aMatrix.m_Data[1] + aVector.y * aMatrix.m_Data[4] + aVector.z * aMatrix.m_Data[7],
			aVector.x * aMatrix.m_Data[2] + aVector.y * aMatrix.m_Data[5] + aVector.z * aMatrix.m_Data[8]
		);
	}

	template<typename T>
	inline Matrix3x3<T> Matrix3x3<T>::Transpose(const Matrix3x3<T>& aMatrixToTranspose)
	{
		Matrix3x3<T> matrix;
		matrix(1, 1) = aMatrixToTranspose(1, 1);
		matrix(1, 2) = aMatrixToTranspose(2, 1);
		matrix(1, 3) = aMatrixToTranspose(3, 1);

		matrix(2, 1) = aMatrixToTranspose(1, 2);
		matrix(2, 2) = aMatrixToTranspose(2, 2);
		matrix(2, 3) = aMatrixToTranspose(3, 2);

		matrix(3, 1) = aMatrixToTranspose(1, 3);
		matrix(3, 2) = aMatrixToTranspose(2, 3);
		matrix(3, 3) = aMatrixToTranspose(3, 3);
		return matrix;
	}

	template<typename T>
	inline Matrix3x3<T> Matrix3x3<T>::CreateRotationAroundX(T aAngleInRadians)
	{
		Matrix3x3<T> matrix;
		matrix(1, 1) = 1;
		matrix(2, 2) = std::cos(aAngleInRadians);
		matrix(2, 3) = std::sin(aAngleInRadians);
		matrix(3, 2) = -std::sin(aAngleInRadians);
		matrix(3, 3) = std::cos(aAngleInRadians);
		return matrix;
	}

	template<typename T>
	inline Matrix3x3<T> Matrix3x3<T>::CreateRotationAroundY(T aAngleInRadians)
	{
		Matrix3x3<T> matrix;
		matrix(1, 1) = std::cos(aAngleInRadians);
		matrix(2, 2) = 1;
		matrix(3, 1) = std::sin(aAngleInRadians);
		matrix(1, 3) = -std::sin(aAngleInRadians);
		matrix(3, 3) = std::cos(aAngleInRadians);
		return matrix;
	}

	template<typename T>
	inline Matrix3x3<T> Matrix3x3<T>::CreateRotationAroundZ(T aAngleInRadians)
	{
		Matrix3x3<T> matrix;
		matrix(1, 1) = std::cos(aAngleInRadians);
		matrix(1, 2) = std::sin(aAngleInRadians);
		matrix(2, 1) = -std::sin(aAngleInRadians);
		matrix(2, 2) = std::cos(aAngleInRadians);
		matrix(3, 3) = 1;
		return matrix;
	}

	using Matrix3x3f = Matrix3x3<float>;
}