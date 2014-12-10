#ifndef _vector_impl_h_
#define _vector_impl_h_
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

// SET
template <int N, typename T>
inline VectorBase<N, T>& VectorBase<N, T>::operator=(T v)
{
	int i;
	for(i = 0; i < N; i++)
		this->data[i] = v;

	return *this;
}

template <int N, typename T>
inline VectorBase<N, T>& VectorBase<N, T>::operator=(VectorBase<N, T> v)
{
	int i;
	for(i = 0; i < N; i++)
		this->data[i] = v.data[i];

	return *this;
}


// ADDITION
template <int N, typename T>
inline VectorBase<N, T>& VectorBase<N, T>::operator+=(T v)
{
	int i;
	for(i = 0; i < N; i++)
		this->data[i] += v;

	return *this;
}

template <int N, typename T>
inline VectorBase<N, T>& VectorBase<N, T>::operator+=(VectorBase<N, T> v)
{
	int i;
	for(i = 0; i < N; i++)
		this->data[i] += v.data[i];

	return *this;
}

// SUBTRACTION
template <int N, typename T>
inline VectorBase<N, T>& VectorBase<N, T>::operator-=(T v)
{
	int i;
	for(i = 0; i < N; i++)
		this->data[i] -= v;

	return *this;
}

template <int N, typename T>
inline VectorBase<N, T>& VectorBase<N, T>::operator-=(VectorBase<N, T> v)
{
	int i;
	for(i = 0; i < N; i++)
		this->data[i] -= v.data[i];

	return *this;
}

// MULTIPLICATION
template <int N, typename T>
inline VectorBase<N, T>& VectorBase<N, T>::operator*=(T v)
{
	int i;
	for(i = 0; i < N; i++)
		this->data[i] *= v;

	return *this;
}

template <int N, typename T>
inline VectorBase<N, T>& VectorBase<N, T>::operator*=(VectorBase<N, T> v)
{
	int i;
	for(i = 0; i < N; i++)
		this->data[i] *= v.data[i];

	return *this;
}

// DIVISION
template <int N, typename T>
inline VectorBase<N, T>& VectorBase<N, T>::operator/=(T v)
{
	int i;
	for(i = 0; i < N; i++)
		this->data[i] /= v;

	return *this;
}

template <int N, typename T>
inline VectorBase<N, T>& VectorBase<N, T>::operator/=(VectorBase<N, T> v)
{
	int i;
	for(i = 0; i < N; i++)
		this->data[i] /= v.data[i];

	return *this;
}

// asdasd
template <int N, typename T>
inline Vector<N, T> operator+(Vector<N, T> v1, T v2)
{
	Vector<N, T> r = Vector<N, T>(v1);
	r += v2;
	return r;
}

template <int N, typename T>
inline Vector<N, T> operator+(Vector<N, T> v1, Vector<N, T> v2)
{
	Vector<N, T> r = Vector<N, T>(v1);
	r += v2;
	return r;
}

template <int N, typename T>
inline Vector<N, T> operator-(Vector<N, T> v1, T v2)
{
	Vector<N, T> r = Vector<N, T>(v1);
	r -= v2;
	return r;
}

template <int N, typename T>
inline Vector<N, T> operator-(Vector<N, T> v1, Vector<N, T> v2)
{
	Vector<N, T> r = Vector<N, T>(v1);
	r -= v2;
	return r;
}

template <int N, typename T>
inline Vector<N, T> operator*(Vector<N, T> v1, T v2)
{
	Vector<N, T> r = Vector<N, T>(v1);
	r *= v2;
	return r;
}

template <int N, typename T>
inline Vector<N, T> operator*(Vector<N, T> v1, Vector<N, T> v2)
{
	Vector<N, T> r = Vector<N, T>(v1);
	r *= v2;
	return r;
}

template <int N, typename T>
inline Vector<N, T> operator/(Vector<N, T> v1, T v2)
{
	Vector<N, T> r = Vector<N, T>(v1);
	r /= v2;
	return r;
}

template <int N, typename T>
inline Vector<N, T> operator/(Vector<N, T> v1, Vector<N, T> v2)
{
	Vector<N, T> r = Vector<N, T>(v1);
	r /= v2;
	return r;
}



// matrix
template <int M, int N, typename T>
inline Vector<M, Vector<N, T> >& Vector<M, Vector<N, T> >::operator=(T v)
{
	int i;
	for(i = 0; i < M; i++)
		this->data[i] = v;

	return *this;
}

template <int M, int N, typename T>
inline Vector<M, Vector<N, T> >& Vector<M, Vector<N, T> >::operator+=(T v)
{
	int i;
	for(i = 0; i < M; i++)
		this->data[i] += v;

	return *this;
}

template <int M, int N, typename T>
inline Vector<M, Vector<N, T> >& Vector<M, Vector<N, T> >::operator-=(T v)
{
	int i;
	for(i = 0; i < M; i++)
		this->data[i] -= v;

	return *this;
}

template <int M, int N, typename T>
inline Vector<M, Vector<N, T> >& Vector<M, Vector<N, T> >::operator*=(T v)
{
	int i;
	for(i = 0; i < M; i++)
		this->data[i] *= v;

	return *this;
}

template <int M, int N, typename T>
inline Vector<M, Vector<N, T> >& Vector<M, Vector<N, T> >::operator/=(T v)
{
	int i;
	for(i = 0; i < M; i++)
		this->data[i] /= v;

	return *this;
}


};

#endif

