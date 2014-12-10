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
		inline VectorBase<N, T>& operator+=(T v);
		inline void add(VectorBase<N, T> v);
		/*VectorBase<N, T> operator+=(T v);
		inline void operator+=(VectorBase<N, T> v);
		inline void sub(T v);
		inline void sub(VectorBase<N, T> v);
		inline void mul(T v);
		inline void mul(VectorBase<N, T> v);
		inline void div(T v);
		inline void div(VectorBase<N, T> v);
*/
		T data[N];
};

template <int N, typename T>
class Vector : public VectorBase<N, T>
{
	public:
		Vector();
		~Vector();
};

template <int M, int N, typename T>
class Vector<M, Vector<N, T> > : public VectorBase<M, Vector<N, T> >
{
	public:
		inline Vector<M, Vector<N, T> >& operator+=(T v);
};

// XYZ - Vector
/*
FIXME: how the fuck can I get data into this union?
template <typename T>
class Vector<3, T> : public VectorBase<3, T>
{
	public:
		union
		{
			struct { T x,y,z; };
			//using VectorBase<3, T>::data;
		};
};
*/
typedef Vector<3, int> Vector3i;
typedef Vector<3, float> Vector3f;

};

#include "vector_impl.h"

#endif

