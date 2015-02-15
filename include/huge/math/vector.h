#ifndef _huge_math_vector_h_
#define _huge_math_vector_h_
/*
        Copyright 2012-2014 Infinitycoding all rights reserved
        This file is part of the HugeUniversalGameEngine.

        HUGE is free software: you can redistribute it and/or modify
        it under the terms of the GNU General Public License as published by
        the Free Software Foundation, either version 3 of the License, or
        any later version.

        HUGE is distributed in the hope that it will be useful,
        but WITHOUT ANY WARRANTY; without even the implied warranty of
        MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
        GNU General Public License for more details.

        You should have received a copy of the GNU General Public License
        along with the Universe Kernel. If not, see <http://www.gnu.org/licenses/>.
*/

/*
	@author Michael Sippel <micha@infinitycoding.de>
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

        inline T dot(VectorBase<N, T> v);

        T length(void);
        void normalize(void);

        T data[N];
};

template <int N, typename T>
class Vector : public VectorBase<N, T>
{
    public:
        Vector() {}
        Vector(Vector<N, T>& v)
        {
            *this = v;
        }

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
template <int N, typename T> inline Vector<N, T> dot(Vector<N, T> v1, Vector<N, T> v2);

// XY - Vector
template <typename T>
class Vector<2, T> : public VectorBase<2, T>
{
    public:
        Vector() {}
        Vector(T x_, T y_)
        {
            this->data[0]=x_;
            this->data[1]=y_;
        }
        ~Vector() {}

        using VectorBase<2, T>::operator=;
        using VectorBase<2, T>::operator+=;
        using VectorBase<2, T>::operator-=;
        using VectorBase<2, T>::operator*=;
        using VectorBase<2, T>::operator/=;

        inline T& x(void)
        {
            return this->data[0];
        }
        inline T& y(void)
        {
            return this->data[1];
        }
};

// XYZ - Vector
template <typename T>
class Vector<3, T> : public VectorBase<3, T>
{
    public:
        Vector() {}
        Vector(T x_, T y_, T z_)
        {
            this->data[0]=x_;
            this->data[1]=y_;
            this->data[2]=z_;
        }
        Vector(Vector<3, T>& o, Vector<3, T>& p)
        {
            *this = p - o;
        }

        ~Vector() {}

        using VectorBase<3, T>::operator=;
        using VectorBase<3, T>::operator+=;
        using VectorBase<3, T>::operator-=;
        using VectorBase<3, T>::operator*=;
        using VectorBase<3, T>::operator/=;

        inline void cross(Vector<3, T> v);

        inline T& x(void)
        {
            return this->data[0];
        }
        inline T& y(void)
        {
            return this->data[1];
        }
        inline T& z(void)
        {
            return this->data[2];
        }
};

template <typename T> inline Vector<3, T> cross(VectorBase<3, T> v1, VectorBase<3, T> v2);

// XYZW - Vector
template <typename T>
class Vector<4, T> : public VectorBase<4, T>
{
    public:
        Vector() {}
        Vector(T x_, T y_, T z_, T w_)
        {
            this->data[0]=x_;
            this->data[1]=y_;
            this->data[2]=z_;
            this->data[3]=w_;
        }
        ~Vector() {}

        using VectorBase<4, T>::operator=;
        using VectorBase<4, T>::operator+=;
        using VectorBase<4, T>::operator-=;
        using VectorBase<4, T>::operator*=;
        using VectorBase<4, T>::operator/=;

        inline T& x(void)
        {
            return this->data[0];
        }
        inline T& y(void)
        {
            return this->data[1];
        }
        inline T& z(void)
        {
            return this->data[2];
        }
        inline T& w(void)
        {
            return this->data[3];
        }
};


typedef Vector<2, int> Vector2i;
typedef Vector<3, int> Vector3i;
typedef Vector<4, int> Vector4i;

typedef Vector<2, unsigned int> Vector2ui;
typedef Vector<3, unsigned int> Vector3ui;
typedef Vector<4, unsigned int> Vector4ui;

typedef Vector<2, float> Vector2f;
typedef Vector<3, float> Vector3f;
typedef Vector<4, float> Vector4f;

typedef Vector<2, double> Vector2d;
typedef Vector<3, double> Vector3d;
typedef Vector<4, double> Vector4d;

}; // namespace huge

#include "vector_impl.h"

#endif

