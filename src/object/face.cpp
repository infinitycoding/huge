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
        along with the Universe Kernel. If not, see <http://www.gnu.org/licenses/>.
*/

/*
	@author Michael Sippel <micha@infinitycoding.de>
 */

#include <stdlib.h>

#include <huge/math/vector.h>
#include <huge/math/transformation.h>
#include <huge/video/device.h>
#include <huge/object/face.h>

namespace huge
{

Face::Face()
    : num_vertices(0), vertices(NULL)
{
}

Face::Face(int num_vertices_, int *vertices_)
    : num_vertices(num_vertices_), vertices(vertices_)
{
}

Face::Face(int num_vertices_, int *vertices_, int *texcoords_)
    : num_vertices(num_vertices_), vertices(vertices_), texcoords(texcoords_)
{
}

Face::~Face()
{
}

}; // namespace huge

