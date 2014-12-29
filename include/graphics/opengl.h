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
		//void clearColor(Color4f col);
        void begin(enum primitive t);
        void end(void);

		// matrix
/*		void pushMatrix(void);
		void popMatrix(void);

        void translate2i(Vector2i v);
        void translate3i(Vector3i v);
        void translate2f(Vector2f v);
        void translate3f(Vector3f v);
        void translate2d(Vector2d v);
        void translate3d(Vector3d v);

        void rotate2f(Vector2f v, float angle);
        void rotate3f(Vector3f v, float angle);
        void rotate2d(Vector2d v, double angle);
        void rotate3d(Vector3d v, double angle);

        void scale2i(Vector2i v);
        void scale3i(Vector3i v);
        void scale2f(Vector2f v);
        void scale3f(Vector3f v);
        void scale2d(Vector2d v);
        void scale3d(Vector3d v);
*/
        // vertex data
//        void vertex2i(Vector2i v);
//        void vertex3i(Vector3i v);
//        void vertex2f(Vector2f v);
        void vertex3f(Vector3f v);
//        void vertex2d(Vector2d v);
//        void vertex3d(Vector3d v);

        // color data
       // void color4i(Color4i v);
       // void color3i(Color3i v);
        void color4f(Color4f v);
       // void color3f(Color3f v);

    private:
        void not_supported(const char *str);
};

};

#endif
