#ifndef _opengl_device_h_
#define _opengl_device_h_
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

#include <GL/glew.h>
#include <GL/gl.h>

#include "math/vector.h"
#include "graphics/device.h"

namespace huge
{

class OpenGLDevice : public GraphicsDevice
{
    public:
        OpenGLDevice();
        ~OpenGLDevice();

        static const enum graphics_device_type device_type = OPENGL_DEVICE;

        // buffers
        void clear(bitfield_t buffers);
        void clearColor(Color4d col);
        void begin(enum primitive t);
        void end(void);

        // matrix
        void pushMatrix(void);
        void popMatrix(void);

        void translatef(Vector3f v);
        void translated(Vector3d v);
        void rotatef(Vector3f v, float angle);
        void rotated(Vector3d v, double angle);
        void scalef(Vector3f v);
        void scaled(Vector3d v);

        // vertex data
        void vertex2i(Vector2i v);
        void vertex3i(Vector3i v);
        void vertex2f(Vector2f v);
        void vertex3f(Vector3f v);
        void vertex2d(Vector2d v);
        void vertex3d(Vector3d v);

        // color data
        void color3b(Color3b c);
        void color4b(Color4b c);
        void color3ub(Color3ub c);
        void color4ub(Color4ub c);
        void color3s(Color3s c);
        void color4s(Color4s c);
        void color3us(Color3us c);
        void color4us(Color4us c);
        void color3i(Color3i c);
        void color4i(Color4i c);
        void color3ui(Color3ui c);
        void color4ui(Color4ui c);
        void color3f(Color3f c);
        void color4f(Color4f c);
        void color3d(Color3d c);
        void color4d(Color4d c);

    private:
        void not_supported(const char *str);
};

};

#endif
