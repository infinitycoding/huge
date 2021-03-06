#ifndef _huge_texture_impl_h_
#define _huge_texture_impl_h_
/*
        Copyright 2012-2015 Infinitycoding all rights reserved
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

#include <stdint.h>
#include <huge/material/texture.h>

namespace huge
{

template <unsigned int N, typename T>
Texture<N, T>::Texture()
{
}

template <unsigned int N, typename T>
Texture<N, T>::Texture(Vector<N, size_t> size_, unsigned int bpp_, T *data_)
    : size(size_), bpp(bpp_), data(data_)
{
}

template <unsigned int N, typename T>
Texture<N, T>::~Texture()
{
}

};

#include "texture_impl.h"

#endif

