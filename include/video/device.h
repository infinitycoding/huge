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

class Viewport;
template <typename T> class Transformation2;
template <typename T> class Transformation3;

class VideoContext
{
    public:
        VideoContext();
        ~VideoContext();

        void activate(void);

    protected:
        virtual inline void activate_(void);

    private:
        static thread_local VideoContext *current;
};

class VideoDevice
{
    public:
        VideoDevice();
        VideoDevice(VideoContext *context_);
        ~VideoDevice();

        static const enum video_device_type device_type = NULL_DEVICE;
        VideoContext *context;

        //
        // wrappers for better use
        //
        template <typename T> void useTransformation(Transformation2<T> t)
		{
			t.useTransformation(this);
		}
        template <typename T> void useTransformation(Transformation3<T> t)
		{
			t.useTransformation(this);
		}

        void useViewport(Viewport *viewport);

        //
        // specific virtual functions
        //

        // buffer
        DUMMY(void clear(bitfield_t buffers));
        DUMMY(void clearColor(Color4d col));
        DUMMY(void setViewport(Vector2i position, Vector2i size));
        DUMMY(void begin(enum primitive t));
        DUMMY(void end(void));

        // matrix
        DUMMY(void setMatrixMode(enum matrix_mode m));
        DUMMY(void setPerspective(double fovy, double aspect, double znear, double zfar));
        DUMMY(void loadIdentity(void));
        DUMMY(void pushMatrix(void));
        DUMMY(void popMatrix(void));

        DUMMY(void translate(Vector3f v));
        DUMMY(void translate(Vector3d v));
        DUMMY(void rotate(Vector3f v, float angle));
        DUMMY(void rotate(Vector3d v, double angle));
        DUMMY(void scale(Vector3f v));
        DUMMY(void scale(Vector3d v));

        // vertex data
        DUMMY(void vertex2(Vector2f v));
        DUMMY(void vertex2(Vector2d v));
        DUMMY(void vertex3(Vector3f v));
        DUMMY(void vertex3(Vector3d v));

        // color data
        DUMMY(void color3(Color3b c));
        DUMMY(void color3(Color3ub c));
        DUMMY(void color3(Color3s c));
        DUMMY(void color3(Color3us c));
        DUMMY(void color3(Color3i c));
        DUMMY(void color3(Color3ui c));
        DUMMY(void color3(Color3f c));
        DUMMY(void color3(Color3d c));

        DUMMY(void color4(Color4b c));
        DUMMY(void color4(Color4ub c));
        DUMMY(void color4(Color4s c));
        DUMMY(void color4(Color4us c));
        DUMMY(void color4(Color4i c));
        DUMMY(void color4(Color4ui c));
        DUMMY(void color4(Color4f c));
        DUMMY(void color4(Color4d c));

    private:
        virtual void not_supported(const char *str);

};

#undef DUMMY
#undef str
#undef xstr

};

#endif

