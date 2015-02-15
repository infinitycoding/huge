#ifndef _huge_texture_h_
#define _huge_texture_h_
/*
        Copyright 2012-2015 Infinitycoding all rights reserved
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
        along with HUGE. If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdint.h>
#include <huge/math/vector.h>

namespace huge
{

template <unsigned int N, typename T>
class Texture
{
    public:
        Texture();
        Texture(Vector<N, size_t> size_, unsigned int bpp_, T *data_);
        ~Texture();

        Vector<N, size_t> size;
        unsigned int bpp;
        T *data;
};

typedef Texture<2, unsigned char> Texture2ub;
typedef Texture<2, float> Texture2f;

};

#include "texture_impl.h"

#endif

