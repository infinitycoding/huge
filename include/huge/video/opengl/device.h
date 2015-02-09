#ifndef _huge_video_opengl_device_h_
#define _huge_video_opengl_device_h_
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

/*
	@author Michael Sippel <micha@infinitycoding.de>
 */

#include <GL/glew.h>
#include <GL/gl.h>

#include <huge/light.h>
#include <huge/math/vector.h>
#include <huge/video/device.h>
#include <huge/video/opengl/light.h>

namespace huge
{

namespace video
{

class OpenGLDevice : public Device
{
    public:
        OpenGLDevice();
        OpenGLDevice(video::Context *context_);
        ~OpenGLDevice();

        static const enum device_type type = OPENGL_DEVICE;

        // buffers
        void clear(bitfield_t buffers);
        void clearColor(Color4d col);
        void setViewport(Vector2i position, Vector2i size);
        void begin(enum primitive t);
        void end(void);

        // matrix
        void setMatrixMode(enum matrix_mode m);
        void setPerspective(double fovy, double aspect, double znear, double zfar);
        void loadIdentity(void);
        void pushMatrix(void);
        void popMatrix(void);

        void translate(Vector3f v);
        void translate(Vector3d v);
        void rotate(Vector3f v, float angle);
        void rotate(Vector3d v, double angle);
        void scale(Vector3f v);
        void scale(Vector3d v);

        // vertex data
        void vertex(Vector2i v);
        void vertex(Vector2f v);
        void vertex(Vector2d v);
        void vertex(Vector3d v);
        void vertex(Vector3i v);
        void vertex(Vector3f v);

        // normal data
        void normal(Vector3d v);
        void normal(Vector3i v);
        void normal(Vector3f v);

        // color data
        void color(Color3b c);
        void color(Color4b c);
        void color(Color3ub c);
        void color(Color4ub c);
        void color(Color3s c);
        void color(Color4s c);
        void color(Color3us c);
        void color(Color4us c);
        void color(Color3i c);
        void color(Color4i c);
        void color(Color3ui c);
        void color(Color4ui c);
        void color(Color3f c);
        void color(Color4f c);
        void color(Color3d c);
        void color(Color4d c);

        // light data
        void enableLight(Light *light);
        void disableLight(Light *light);
        void updateLight(Light *light);

    private:
        void not_supported(const char *str);

        inline GL_Light *getLight(Light *light);
};

}; // namespace video

}; // namespace huge

#endif
