#ifndef _vector_h_
#define _vector_h_
/*
        Copyright 2012-2014 Infinitycoding all rights reserved
        This file is part of the HugeUniversalGameEngine.

        HUGE is free software: you can redistribute it and/or modify
        it under the terms of the GNU General Public License as published by
        the Free Software Foundation, either version 3 of the License, or
        any later version.

        The Universe Kernel is distributed in the hope that it will be useful,
        but WITHOUT ANY WARRANTY; without even the implied warranty of
        MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
        GNU General Public License for more details.

        You should have received a copy of the GNU General Public License
        along with the Universe Kernel. If not, see <http://www.gnu.org/licenses/>.
*/

namespace huge
{

template <int N, typename T>
class VectorBase
{
	public:
		inline VectorBase<N, T>& operator=(T v);
		inline VectorBase<N, T>& operator=(VectorBase<N, T> v);

		inline VectorBase<N, T>& operator+=(T v);
		inline VectorBase<N, T>& operator+=(VectorBase<N, T> v);
		inline VectorBase<N, T>& operator-=(T v);
		inline VectorBase<N, T>& operator-=(VectorBase<N, T> v);
		inline VectorBase<N, T>& operator*=(T v);
		inline VectorBase<N, T>& operator*=(VectorBase<N, T> v);
		inline VectorBase<N, T>& operator/=(T v);
		inline VectorBase<N, T>& operator/=(VectorBase<N, T> v);

		T data[N];
};

template <int N, typename T>
class Vector : public VectorBase<N, T>
{
	public:
		Vector() {}
		Vector(Vector<N, T>& v) { *this = v; }

		using VectorBase<N, T>::operator=;

		using VectorBase<N, T>::operator+=;
		using VectorBase<N, T>::operator-=;
		using VectorBase<N, T>::operator*=;
		using VectorBase<N, T>::operator/=;
};

template <int N, typename T> inline Vector<N, T> operator+(Vector<N, T> v1, T v2);
template <int N, typename T> inline Vector<N, T> operator+(Vector<N, T> v1, Vector<N, T> v2);
template <int N, typename T> inline Vector<N, T> operator-(Vector<N, T> v1, T v2);
template <int N, typename T> inline Vector<N, T> operator-(Vector<N, T> v1, Vector<N, T> v2);
template <int N, typename T> inline Vector<N, T> operator*(Vector<N, T> v1, T v2);
template <int N, typename T> inline Vector<N, T> operator*(Vector<N, T> v1, Vector<N, T> v2);
template <int N, typename T> inline Vector<N, T> operator/(Vector<N, T> v1, T v2);
template <int N, typename T> inline Vector<N, T> operator/(Vector<N, T> v1, Vector<N, T> v2);


// MxN - Matrix
template <int M, int N, typename T>
class Vector<M, Vector<N, T> > : public VectorBase<M, Vector<N, T> >
{
	public:
		using VectorBase<M, Vector<N, T> >::operator=;
		inline Vector<M, Vector<N, T> >& operator=(T v);

		using VectorBase<M, Vector<N, T> >::operator+=;
		using VectorBase<M, Vector<N, T> >::operator-=;
		using VectorBase<M, Vector<N, T> >::operator*=;
		using VectorBase<M, Vector<N, T> >::operator/=;
		inline Vector<M, Vector<N, T> >& operator+=(T v);
		inline Vector<M, Vector<N, T> >& operator-=(T v);
		inline Vector<M, Vector<N, T> >& operator*=(T v);
		inline Vector<M, Vector<N, T> >& operator/=(T v);
};

// XYZ - Vector
template <typename T>
class Vector<3, T> : public VectorBase<3, T>
{
	public:
		Vector() {}
		Vector(T x_, T y_, T z_){this->data[0]=x_;this->data[1]=y_;this->data[2]=z_;}
		~Vector() {}

		using VectorBase<3, T>::operator=;

		using VectorBase<3, T>::operator+=;
		using VectorBase<3, T>::operator-=;
		using VectorBase<3, T>::operator*=;
		using VectorBase<3, T>::operator/=;
		/*union
		{
			struct { T x,y,z; };
			
		};*/
};

typedef Vector<3, int> Vector3i;
typedef Vector<3, float> Vector3f;

};

#include "vector_impl.h"

#endif

