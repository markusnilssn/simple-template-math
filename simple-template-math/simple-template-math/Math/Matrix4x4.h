#pragma once
#include <cassert>

#include "Vector4.h"
#include "Vector3.h"
#include "Matrix3x3.h"

namespace stm
{
	template<typename T>
	class Matrix4x4
	{
	
		template<typename T>
		friend Matrix3x3<T>::Matrix3x3(const Matrix4x4<T>& aMatrix);
		template<typename T>
		friend inline Vector4<T> operator*(const Vector4<T>& aVector, const Matrix4x4<T>& aMatrix);
		template<typename T>
		friend inline Matrix4x4<T> operator*(const Matrix4x4<T>& aLeft, const Matrix4x4<T>& aRight);

	public:
		const Vector3<T> GetRight() const;
		const Vector3<T> GetUp() const;
		const Vector3<T> GetForward() const;
		const Vector3<T> GetTranslation() const;

	public:
		Matrix4x4<T>();
		Matrix4x4<T>(const Matrix4x4<T>& aMatrix);
		Matrix4x4<T>(T a11, T a12, T a13, T a14, T a21, T a22, T a23, T a24, T a31, T a32, T a33, T a34, T a41, T a42, T a43, T a44);

		inline T& operator()(const int row, const int column);
		inline const T& operator()(const int row, const int column) const;
		inline Matrix4x4<T>& operator+=(const Matrix4x4& aOther);
		inline Matrix4x4<T>& operator-=(const Matrix4x4& aOther);
		inline Matrix4x4<T>& operator*=(const Matrix4x4& aOther);
		inline bool operator==(const Matrix4x4& aOther) const;
		inline Matrix4x4<T>& operator=(const Matrix4x4& aOther);

		void ConstructOrientation(const Vector4<T>& aBasise0, const Vector4<T>& aBasise1, const Vector4<T>& aBasise2);
		static inline Matrix4x4<T> CreateRotationAroundX(T aAngleInRadians);
		static inline Matrix4x4<T> CreateRotationAroundY(T aAngleInRadians);
		static inline Matrix4x4<T> CreateRotationAroundZ(T aAngleInRadians);
		static inline Matrix4x4<T> Transpose(const Matrix4x4<T>& aMatrixToTranspose);

		static Matrix4x4<T> GetFastInverse(const Matrix4x4<T>& aTransform);
		static Matrix4x4<T> GetIdentity();

		void RotateAroundX(T anAmount);
	private:
		T m_Data[16];
	};

	template<typename T>
	Matrix4x4<T>::Matrix4x4() 
		: m_Data
	{
		1,0,0,0,
		0,1,0,0,
		0,0,1,0,
		0,0,0,1
	}
	{
	}

	template<typename T>
	Matrix4x4<T>::Matrix4x4(const Matrix4x4<T>& aMatrix) 
		: m_Data {
		aMatrix.m_Data[0],
		aMatrix.m_Data[1],
		aMatrix.m_Data[2],
		aMatrix.m_Data[3],
		aMatrix.m_Data[4],
		aMatrix.m_Data[5],
		aMatrix.m_Data[6],
		aMatrix.m_Data[7],
		aMatrix.m_Data[8],
		aMatrix.m_Data[9],
		aMatrix.m_Data[10],
		aMatrix.m_Data[11],
		aMatrix.m_Data[12],
		aMatrix.m_Data[13],
		aMatrix.m_Data[14],
		aMatrix.m_Data[15]
	}
	{
	}

	template<typename T>
	Matrix4x4<T>::Matrix4x4(T a11, T a12, T a13, T a14, T a21, T a22, T a23, T a24, T a31, T a32, T a33, T a34, T a41, T a42, T a43, T a44) 
		: m_Data{
		a11,
		a12,
		a13,
		a14,
		a21,
		a22,
		a23,
		a24,
		a31,
		a32,
		a33,
		a34,
		a41,
		a42,
		a43,
		a44
	}
	{
	}

	template<typename T>
	inline T& Matrix4x4<T>::operator()(const int aRow, const int aColumn)
	{
		assert(aRow >= 0 && aRow <= 4 && "Row out of bounds");
		assert(aColumn >= 0 && aColumn <= 4 && "Column out of bounds");

		return m_Data[(aRow - 1) * 4 + (aColumn - 1)];
	}

	template<typename T>
	inline const T& Matrix4x4<T>::operator()(const int aRow, const int aColumn) const
	{
		assert(aRow >= 0 && aRow <= 4 && "Row out of bounds");
		assert(aColumn >= 0 && aColumn <= 4 && "Column out of bounds");

		return m_Data[(aRow - 1) * 4 + (aColumn - 1)];
	}

	template<typename T>
	inline Matrix4x4<T>& Matrix4x4<T>::operator+=(const Matrix4x4<T>& aOther)
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
		this->m_Data[9] += aOther.m_Data[9];
		this->m_Data[10] += aOther.m_Data[10];
		this->m_Data[11] += aOther.m_Data[11];
		this->m_Data[12] += aOther.m_Data[12];
		this->m_Data[13] += aOther.m_Data[13];
		this->m_Data[14] += aOther.m_Data[14];
		this->m_Data[15] += aOther.m_Data[15];
		return *this;
	}

	template<typename T>
	inline Matrix4x4<T> operator+(const Matrix4x4<T>& aLeft, const Matrix4x4<T>& aRight)
	{
		Matrix4x4<T> matrix(aLeft);
		matrix += aRight;
		return matrix;
	}

	template<typename T>
	inline Matrix4x4<T>& Matrix4x4<T>::operator-=(const Matrix4x4<T>& aOther)
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
		this->m_Data[9] -= aOther.m_Data[9];
		this->m_Data[10] -= aOther.m_Data[10];
		this->m_Data[11] -= aOther.m_Data[11];
		this->m_Data[12] -= aOther.m_Data[12];
		this->m_Data[13] -= aOther.m_Data[13];
		this->m_Data[14] -= aOther.m_Data[14];
		this->m_Data[15] -= aOther.m_Data[15];
		return *this;
	}

	template<typename T>
	inline Matrix4x4<T> operator-(const Matrix4x4<T>& aLeft, const Matrix4x4<T>& aRight)
	{
		Matrix4x4<T> matrix(aLeft);
		matrix -= aRight;
		return matrix;
	}

	template<typename T>
	inline Matrix4x4<T> operator*(const Matrix4x4<T>& aLeft, const Matrix4x4<T>& aRight)
	{
#define LEFT aLeft.m_Data
#define RIGHT aRight.m_Data

		return Matrix4x4<T>(
			LEFT[0] * RIGHT[0] + LEFT[1] * RIGHT[4] + LEFT[2] * RIGHT[8] + LEFT[3] * RIGHT[12],
			LEFT[0] * RIGHT[1] + LEFT[1] * RIGHT[5] + LEFT[2] * RIGHT[9] + LEFT[3] * RIGHT[13],
			LEFT[0] * RIGHT[2] + LEFT[1] * RIGHT[6] + LEFT[2] * RIGHT[10] + LEFT[3] * RIGHT[14],
			LEFT[0] * RIGHT[3] + LEFT[1] * RIGHT[7] + LEFT[2] * RIGHT[11] + LEFT[3] * RIGHT[15],

			LEFT[4] * RIGHT[0] + LEFT[5] * RIGHT[4] + LEFT[6] * RIGHT[8] + LEFT[7] * RIGHT[12],
			LEFT[4] * RIGHT[1] + LEFT[5] * RIGHT[5] + LEFT[6] * RIGHT[9] + LEFT[7] * RIGHT[13],
			LEFT[4] * RIGHT[2] + LEFT[5] * RIGHT[6] + LEFT[6] * RIGHT[10] + LEFT[7] * RIGHT[14],
			LEFT[4] * RIGHT[3] + LEFT[5] * RIGHT[7] + LEFT[6] * RIGHT[11] + LEFT[7] * RIGHT[15],

			LEFT[8] * RIGHT[0] + LEFT[9] * RIGHT[4] + LEFT[10] * RIGHT[8] + LEFT[11] * RIGHT[12],
			LEFT[8] * RIGHT[1] + LEFT[9] * RIGHT[5] + LEFT[10] * RIGHT[9] + LEFT[11] * RIGHT[13],
			LEFT[8] * RIGHT[2] + LEFT[9] * RIGHT[6] + LEFT[10] * RIGHT[10] + LEFT[11] * RIGHT[14],
			LEFT[8] * RIGHT[3] + LEFT[9] * RIGHT[7] + LEFT[10] * RIGHT[11] + LEFT[11] * RIGHT[15],

			LEFT[12] * RIGHT[0] + LEFT[13] * RIGHT[4] + LEFT[14] * RIGHT[8] + LEFT[15] * RIGHT[12],
			LEFT[12] * RIGHT[1] + LEFT[13] * RIGHT[5] + LEFT[14] * RIGHT[9] + LEFT[15] * RIGHT[13],
			LEFT[12] * RIGHT[2] + LEFT[13] * RIGHT[6] + LEFT[14] * RIGHT[10] + LEFT[15] * RIGHT[14],
			LEFT[12] * RIGHT[3] + LEFT[13] * RIGHT[7] + LEFT[14] * RIGHT[11] + LEFT[15] * RIGHT[15]
		);
#undef LEFT
#undef RIGHT
	}

	template<typename T>
	inline Matrix4x4<T>& Matrix4x4<T>::operator*=(const Matrix4x4<T>& aOther)
	{
		return (*this) = (*this) * aOther;
	}


	template<typename T>
	inline bool Matrix4x4<T>::operator==(const Matrix4x4& aOther) const
	{
		return
			this->m_Data[0] == aOther.m_Data[0] && this->m_Data[1] == aOther.m_Data[1] && this->m_Data[2] == aOther.m_Data[2] && this->m_Data[3] == aOther.m_Data[3] &&
			this->m_Data[4] == aOther.m_Data[4] && this->m_Data[5] == aOther.m_Data[5] && this->m_Data[6] == aOther.m_Data[6] && this->m_Data[7] == aOther.m_Data[7] &&
			this->m_Data[8] == aOther.m_Data[8] && this->m_Data[9] == aOther.m_Data[9] && this->m_Data[10] == aOther.m_Data[10] && this->m_Data[11] == aOther.m_Data[11] &&
			this->m_Data[12] == aOther.m_Data[12] && this->m_Data[13] == aOther.m_Data[13] && this->m_Data[14] == aOther.m_Data[14] && this->m_Data[15] == aOther.m_Data[15];
	}

	template<typename T>
	inline Matrix4x4<T>& Matrix4x4<T>::operator=(const Matrix4x4& aOther)
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
		m_Data[9] = aOther.m_Data[9];
		m_Data[10] = aOther.m_Data[10];
		m_Data[11] = aOther.m_Data[11];
		m_Data[12] = aOther.m_Data[12];
		m_Data[13] = aOther.m_Data[13];
		m_Data[14] = aOther.m_Data[14];
		m_Data[15] = aOther.m_Data[15];
		return *this;
	}

	template<typename T>
	inline Vector4<T> operator*(const Vector4<T>& aVector, const Matrix4x4<T>& aMatrix)
	{
		return Vector4<T>(
			aVector.x * aMatrix.m_Data[0] + aVector.y * aMatrix.m_Data[4] + aVector.z * aMatrix.m_Data[8] + aVector.w * aMatrix.m_Data[12],
			aVector.x * aMatrix.m_Data[1] + aVector.y * aMatrix.m_Data[5] + aVector.z * aMatrix.m_Data[9] + aVector.w * aMatrix.m_Data[13],
			aVector.x * aMatrix.m_Data[2] + aVector.y * aMatrix.m_Data[6] + aVector.z * aMatrix.m_Data[10] + aVector.w * aMatrix.m_Data[14],
			aVector.x * aMatrix.m_Data[3] + aVector.y * aMatrix.m_Data[7] + aVector.z * aMatrix.m_Data[11] + aVector.w * aMatrix.m_Data[15]
		);
	}

	template<typename T>
	inline Matrix4x4<T> Matrix4x4<T>::Transpose(const Matrix4x4<T>& aMatrixToTranspose)
	{
		return Matrix4x4<T>(
			aMatrixToTranspose.m_Data[0],
			aMatrixToTranspose.m_Data[4],
			aMatrixToTranspose.m_Data[8],
			aMatrixToTranspose.m_Data[12],

			aMatrixToTranspose.m_Data[1],
			aMatrixToTranspose.m_Data[5],
			aMatrixToTranspose.m_Data[9],
			aMatrixToTranspose.m_Data[13],

			aMatrixToTranspose.m_Data[2],
			aMatrixToTranspose.m_Data[6],
			aMatrixToTranspose.m_Data[10],
			aMatrixToTranspose.m_Data[14],

			aMatrixToTranspose.m_Data[3],
			aMatrixToTranspose.m_Data[7],
			aMatrixToTranspose.m_Data[11],
			aMatrixToTranspose.m_Data[15]
		);
	}

	template<class T>
	inline void Matrix4x4<T>::ConstructOrientation(const Vector4<T>& aBasise0, const Vector4<T>& aBasise1, const Vector4<T>& aBasise2)
	{
		m_Data[0] = aBasise0.x;
		m_Data[4] = aBasise0.y;
		m_Data[8] = aBasise0.z;
		m_Data[12] = aBasise0.w;

		m_Data[1] = aBasise1.x;
		m_Data[5] = aBasise1.y;
		m_Data[9] = aBasise1.z;
		m_Data[13] = aBasise1.w;

		m_Data[2] = aBasise2.x;
		m_Data[6] = aBasise2.y;
		m_Data[10] = aBasise2.z;
		m_Data[14] = aBasise2.w;
	}

	template<typename T>
	inline Matrix4x4<T> Matrix4x4<T>::CreateRotationAroundX(T aAngleInRadians)
	{
		return Matrix4x4<T>(
			1, 0, 0, 0,
			0, std::cos(aAngleInRadians), std::sin(aAngleInRadians), 0,
			0, -std::sin(aAngleInRadians), std::cos(aAngleInRadians), 0,
			0, 0, 0, 1
		);
	}

	template<typename T>
	inline Matrix4x4<T> Matrix4x4<T>::CreateRotationAroundY(T aAngleInRadians)
	{
		return Matrix4x4<T>(
			std::cos(aAngleInRadians), 0, -std::sin(aAngleInRadians), 0,
			0, 1, 0, 0,
			std::sin(aAngleInRadians), 0, std::cos(aAngleInRadians), 0,
			0, 0, 0, 1
		);
	}

	template<typename T>
	inline Matrix4x4<T> Matrix4x4<T>::CreateRotationAroundZ(T aAngleInRadians)
	{
		return Matrix4x4<T>(
			std::cos(aAngleInRadians), std::sin(aAngleInRadians), 0, 0,
			-std::sin(aAngleInRadians), std::cos(aAngleInRadians), 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1
		);
	}

	template<typename T>
	Matrix4x4<T> Matrix4x4<T>::GetFastInverse(const Matrix4x4<T>& aTransform)
	{
		return Matrix4x4<T>(
			aTransform.m_Data[0], aTransform.m_Data[4], aTransform.m_Data[8], 0,
			aTransform.m_Data[1], aTransform.m_Data[5], aTransform.m_Data[9], 0,
			aTransform.m_Data[2], aTransform.m_Data[6], aTransform.m_Data[10], 0,

			-aTransform.m_Data[12] * aTransform.m_Data[0] - aTransform.m_Data[13] * aTransform.m_Data[1] - aTransform.m_Data[14] * aTransform.m_Data[2],
			-aTransform.m_Data[12] * aTransform.m_Data[4] - aTransform.m_Data[13] * aTransform.m_Data[5] - aTransform.m_Data[14] * aTransform.m_Data[6],
			-aTransform.m_Data[12] * aTransform.m_Data[8] - aTransform.m_Data[13] * aTransform.m_Data[9] - aTransform.m_Data[14] * aTransform.m_Data[10],
			1
		);
	}

	template<typename T>
	Matrix4x4<T> Matrix4x4<T>::GetIdentity()
	{
		return Matrix4x4<T>(
			1, 0, 0, 0,
			0, 1, 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1
		);
	}
	template<typename T>
	const Vector3<T> Matrix4x4<T>::GetRight() const
	{
		return Vector3<T>(m_Data[0], m_Data[1], m_Data[2]);
	}
	template<typename T>
	const Vector3<T> Matrix4x4<T>::GetUp() const
	{
		return Vector3<T>(m_Data[4], m_Data[5], m_Data[6]);
	}
	template<typename T>
	const Vector3<T> Matrix4x4<T>::GetForward() const
	{
		return Vector3<T>(m_Data[8], m_Data[9], m_Data[10]);
	}
	template<typename T>
	const Vector3<T> Matrix4x4<T>::GetTranslation() const
	{
		return Vector3<T>(m_Data[12], m_Data[13], m_Data[14]);
	}

	template<typename T>
	void Matrix4x4<T>::RotateAroundX(T anAmount)
	{
		Matrix4x4<T> matrix;
		matrix *= Matrix4x4<T>::CreateRotationAroundX(anAmount);
		matrix *= *this;
		*this = matrix;
	}

	using Matrix4x4f = Matrix4x4<float>;
}