#ifndef _video_device_h_
#define _video_device_h_
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
#include <stdio.h>

#include "math/vector.h"
#include "color.h"

namespace huge
{

#define xstr(s) str(s)
#define str(s) #s
#define DUMMY(X) virtual inline X { not_supported(str(X)); }

enum video_device_type
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

enum matrix_mode
{
    MODELVIEW, PROJECTION, TEXTURE, COLOR
};

typedef unsigned int bitfield_t;

class VideoContext
{
    public:
        VideoContext();
        ~VideoContext();

        void activate(void);

    protected:
        virtual inline void activate_(void);

    private:
        static VideoContext *current;
};

class VideoDevice
{
    public:
        VideoDevice();
        VideoDevice(VideoContext *context_);
        ~VideoDevice();

        static const enum video_device_type device_type = NULL_DEVICE;

        VideoContext *context;

        // buffer
        DUMMY(void clear(bitfield_t buffers));
        DUMMY(void clearColor(Color4d col));
        DUMMY(void begin(enum primitive t));
        DUMMY(void end(void));

        // matrix
        DUMMY(void setMatrixMode(enum matrix_mode m));
        DUMMY(void setPerspective(double fovy, double aspect, double znear, double zfar));
        DUMMY(void loadIdentity(void));
        DUMMY(void pushMatrix(void));
        DUMMY(void popMatrix(void));

        DUMMY(void translatef(Vector3f v));
        DUMMY(void translated(Vector3d v));
        DUMMY(void rotatef(Vector3f v, float angle));
        DUMMY(void rotated(Vector3d v, double angle));
        DUMMY(void scalef(Vector3f v));
        DUMMY(void scaled(Vector3d v));
        /*
        		inline void translate2f(Vector2f v);
        		inline void translate3f(Vector3f v);
        		inline void translate2d(Vector2d v);
        		inline void translate3d(Vector3d v);
        */

        // vertex data
        DUMMY(void vertex2f(Vector2f v));
        DUMMY(void vertex3f(Vector3f v));
        DUMMY(void vertex2d(Vector2d v));
        DUMMY(void vertex3d(Vector3d v));

        // color data
        DUMMY(void color3b(Color3b c));
        DUMMY(void color4b(Color4b c));
        DUMMY(void color3ub(Color3ub c));
        DUMMY(void color4ub(Color4ub c));
        DUMMY(void color3s(Color3s c));
        DUMMY(void color4s(Color4s c));
        DUMMY(void color3us(Color3us c));
        DUMMY(void color4us(Color4us c));
        DUMMY(void color3i(Color3i c));
        DUMMY(void color4i(Color4i c));
        DUMMY(void color3ui(Color3ui c));
        DUMMY(void color4ui(Color4ui c));
        DUMMY(void color3f(Color3f c));
        DUMMY(void color4f(Color4f c));
        DUMMY(void color3d(Color3d c));
        DUMMY(void color4d(Color4d c));

    private:
        virtual void not_supported(const char *str);

};

#undef DUMMY
#undef str
#undef xstr

};

#endif

