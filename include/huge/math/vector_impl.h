#ifndef _huge_math_vector_impl_h_
#define _huge_math_vector_impl_h_
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

/*
	@author Michael Sippel <micha@infinitycoding.de>
 */

#include <math.h>

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

// Basic
template <int N, typename T>
T VectorBase<N, T>::length(void)
{
    T len = 0;

    int i;
    for(i = 0; i < N; i++)
        len += this->data[i] * this->data[i];

    len = sqrt(len);
    return len;
}

template <int N, typename T>
void VectorBase<N, T>::normalize(void)
{
    T len = this->length();

    if(len > 0)
    {

        int i;
        for(i = 0; i < N; i++)
            this->data[i] /= len;
    }
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

template <int N, typename T>
inline T VectorBase<N, T>::dot(VectorBase<N, T> v)
{
    T r = 0;

    int i;
    for(i = 0; i < N; i++)
        r += this->data[i] * v.data[i];

    return r;
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
template <int N, typename T>
inline Vector<N, T> dot(Vector<N, T> v1, Vector<N, T> v2)
{
    Vector<N, T> r = Vector<N, T>(v1);
    r.dot(v2);
    return r;
}

template <typename T>
inline void Vector<3, T>::cross(Vector<3, T> v)
{
    *this = cross(*this, v);
}

template <typename T>
inline Vector<3, T> cross(Vector<3, T> v1, Vector<3, T> v2)
{
    Vector<3, T> r;
    r.data[0] = (v1.data[1] * v2.data[2]) - (v1.data[2] * v2.data[1]);
    r.data[1] = (v1.data[2] * v2.data[0]) - (v1.data[0] * v2.data[2]);
    r.data[2] = (v1.data[0] * v2.data[1]) - (v1.data[1] * v2.data[0]);

    return r;
}

}; // namespace huge

#endif

