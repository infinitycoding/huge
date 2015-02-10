#ifndef _huge_texture_h_
#define _huge_texture_h_
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
#include <huge/math/vector.h>

namespace huge
{

class Texture
{
    public:
        Texture();
        Texture(Vector2i size_, unsigned int bpp_, uint8_t *data_);
        ~Texture();

        Vector2i size;
        unsigned int bpp;
        uint8_t *data;
};

namespace loader
{
Texture *load_texture(const char *path);
};

};

#endif

