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

#include "math/vector.h"

namespace huge
{


// RGB
template <typename T>
class Color3 : public VectorBase<3, T>
{
    public:
        Color3() {}
        Color3(T r_, T g_, T b_)
        {
            this->r() = r_;
            this->g() = g_;
            this->b() = b_;
        }

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

class Color3i : public Color3<int>
{
    public:
        using Color3<int>::Color3;
        Color3i(float r_, float g_, float b_)
        {
            this->r() = (int) (r_ * (float) 0xff);
            this->g() = (int) (g_ * (float) 0xff);
            this->b() = (int) (b_ * (float) 0xff);
        }
};

class Color3f : public Color3<float>
{
    public:
        using Color3<float>::Color3;
        Color3f(int r_, int g_, int b_)
        {
            this->r() = (float) r_ / (float) 0xff;
            this->g() = (float) g_ / (float) 0xff;
            this->b() = (float) b_ / (float) 0xff;
        }
};

// RGBA
template <typename T>
class Color4 : public VectorBase<4, T>
{
    public:
        Color4() {}
        Color4(T r_, T g_, T b_, T a_)
        {
            this->r() = r_;
            this->g() = g_;
            this->b() = b_;
            this->a() = a_;
        }

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

class Color4i : public Color4<int>
{
    public:
        using Color4<int>::Color4;
        Color4i(float r_, float g_, float b_, float a_)
        {
            this->r() = (int) (r_ * (float) 0xff);
            this->g() = (int) (g_ * (float) 0xff);
            this->b() = (int) (b_ * (float) 0xff);
            this->a() = (int) (a_ * (float) 0xff);
        }
};

class Color4f : public Color4<float>
{
    public:
        using Color4<float>::Color4;
        Color4f(int r_, int g_, int b_, int a_)
        {
            this->r() = (float) r_ / (float) 0xff;
            this->g() = (float) g_ / (float) 0xff;
            this->b() = (float) b_ / (float) 0xff;
            this->a() = (float) a_ / (float) 0xff;
        }
};

};

#endif

