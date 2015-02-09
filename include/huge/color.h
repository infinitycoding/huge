#ifndef _huge_color_h_
#define _huge_color_h_
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
#include <limits.h>

#include <huge/math/vector.h>

namespace huge
{

template <int N, typename T, int S>
class Color : public Vector<N, T>
{
    public:
        template <typename nT, int nS>
        inline Color<N, nT, nS> convert_(void)
        {
            Color<N, nT, nS> c;

            int i;
            for(i = 0; i < N; i++)
                c.data[i] = (nT) ( (double) this->data[i] / (double) S * (double) nS );

            return c;
        }

#define CCONV(X, TYPE, SIZE) \
			inline Color<N, TYPE, SIZE> X (void) \
			{ \
				return this->convert_<TYPE, SIZE>(); \
			} \

        CCONV(c2_b, char, CHAR_MAX);
        CCONV(c2_ub, unsigned char, UCHAR_MAX);
        CCONV(c2_s, short, SHRT_MAX);
        CCONV(c2_us, unsigned short, USHRT_MAX);
        CCONV(c2_i, int, INT_MAX);
        CCONV(c2_ui, unsigned int, UINT_MAX);
        CCONV(c2_f, float, 1);
        CCONV(c2_d, double, 1);

#undef CCONV

        using VectorBase<N, T>::operator=;
        using VectorBase<N, T>::operator+=;
        using VectorBase<N, T>::operator-=;
        using VectorBase<N, T>::operator*=;
        using VectorBase<N, T>::operator/=;
};

// RGB
template <typename T, int S>
class Color3 : public Color<3, T, S>
{
    public:
        Color3() {}
        ~Color3() {}

        Color3(Color<3, T, S> c)
        {
            this->r() = c.data[0];
            this->g() = c.data[1];
            this->b() = c.data[2];
        }

        Color3(T r_, T g_, T b_)
        {
            this->r() = r_;
            this->g() = g_;
            this->b() = b_;
        }

        using VectorBase<3, T>::operator=;
        using VectorBase<3, T>::operator+=;
        using VectorBase<3, T>::operator-=;
        using VectorBase<3, T>::operator*=;
        using VectorBase<3, T>::operator/=;

        inline T& r(void)
        {
            return this->data[0];
        }
        inline T& g(void)
        {
            return this->data[1];
        }
        inline T& b(void)
        {
            return this->data[2];
        }
};

typedef Color3<char, CHAR_MAX> Color3b;
typedef Color3<unsigned char, UCHAR_MAX> Color3ub;
typedef Color3<short, SHRT_MAX> Color3s;
typedef Color3<unsigned short, USHRT_MAX> Color3us;
typedef Color3<int, INT_MAX> Color3i;
typedef Color3<unsigned int, UINT_MAX> Color3ui;
typedef Color3<float, 1> Color3f;
typedef Color3<double, 1> Color3d;

// RGBA
template <typename T, int S>
class Color4 : public Color<4, T, S>
{
    public:
        Color4() {}
        ~Color4() {}

        Color4(Color<4, T, S> c)
        {
            this->r() = c.data[0];
            this->g() = c.data[1];
            this->b() = c.data[2];
            this->a() = c.data[3];
        }

        Color4(T r_, T g_, T b_, T a_)
        {
            this->r() = r_;
            this->g() = g_;
            this->b() = b_;
            this->a() = a_;
        }

        using VectorBase<4, T>::operator=;
        using VectorBase<4, T>::operator+=;
        using VectorBase<4, T>::operator-=;
        using VectorBase<4, T>::operator*=;
        using VectorBase<4, T>::operator/=;

        inline T& r(void)
        {
            return this->data[0];
        }
        inline T& g(void)
        {
            return this->data[1];
        }
        inline T& b(void)
        {
            return this->data[2];
        }
        inline T& a(void)
        {
            return this->data[3];
        }
};

typedef Color4<char, CHAR_MAX> Color4b;
typedef Color4<unsigned char, UCHAR_MAX> Color4ub;
typedef Color4<short, SHRT_MAX> Color4s;
typedef Color4<unsigned short, USHRT_MAX> Color4us;
typedef Color4<int, INT_MAX> Color4i;
typedef Color4<unsigned int, UINT_MAX> Color4ui;
typedef Color4<float, 1> Color4f;
typedef Color4<double, 1> Color4d;

}; // namespace huge

#endif

