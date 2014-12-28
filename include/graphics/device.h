#ifndef _graphics_device_h_
#define _graphics_device_h_
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
#include <stdio.h>

#include "math/vector.h"
#include "color.h"

namespace huge
{

#define xstr(s) str(s)
#define str(s) #s
#define DUMMY(X) virtual X { not_supported(str(X)); }

enum graphics_device_type
{
    NULL_DEVICE,
    OPENGL_DEVICE
};

enum buffer
{
    COLOR_BUFFER_BIT, DEPTH_BUFFER_BIT
};

enum primitive
{
    POINTS, LINES, TRIANGLES, QUADS, POLYGON
};

typedef unsigned int bitfield_t;

class GraphicsDevice
{
    public:
        GraphicsDevice();
        ~GraphicsDevice();

        static const enum graphics_device_type device_type = NULL_DEVICE;

        // buffer
        DUMMY(void clear(bitfield_t buffers));
        DUMMY(void clearColor(Color4f col));
        DUMMY(void begin(enum primitive t));
        DUMMY(void end(void));

        // matrix
        DUMMY(void pushMatrix(void));
        DUMMY(void popMatrix(void));

        DUMMY(void translate2i(Vector2i v));
        DUMMY(void translate3i(Vector3i v));
        DUMMY(void translate2f(Vector2f v));
        DUMMY(void translate3f(Vector3f v));
        DUMMY(void translate2d(Vector2d v));
        DUMMY(void translate3d(Vector3d v));

        DUMMY(void rotate2f(Vector2f v, float angle));
        DUMMY(void rotate3f(Vector3f v, float angle));
        DUMMY(void rotate2d(Vector2d v, double angle));
        DUMMY(void rotate3d(Vector3d v, double angle));

        DUMMY(void scale2i(Vector2i v));
        DUMMY(void scale3i(Vector3i v));
        DUMMY(void scale2f(Vector2f v));
        DUMMY(void scale3f(Vector3f v));
        DUMMY(void scale2d(Vector2d v));
        DUMMY(void scale3d(Vector3d v));

        // vertex data
        DUMMY(void vertex2i(Vector2i v));
        DUMMY(void vertex3i(Vector3i v));
        DUMMY(void vertex2f(Vector2f v));
        DUMMY(void vertex3f(Vector3f v));
        DUMMY(void vertex2d(Vector2d v));
        DUMMY(void vertex3d(Vector3d v));

        // color data
        DUMMY(void color3i(Color3i c));
        DUMMY(void color3f(Color4i c));
        DUMMY(void color4i(Color3f c));
        DUMMY(void color4f(Color4f c));

    private:
        virtual void not_supported(const char *str);

};

#undef DUMMY
#undef str
#undef xstr

};

#endif

