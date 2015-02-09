#ifndef _huge_opengl_light_h_
#define _huge_opengl_light_h_
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

#include <huge/color.h>
#include <huge/light.h>
#include <huge/math/vector.h>

namespace huge
{

namespace video
{

class GL_Light
{
    public:
        GL_Light();
        GL_Light(Light *light);
        ~GL_Light();

        Color4f ambient;
        Color4f diffuse;
        Color4f specular;
        Vector4f position;

        void set(Light *light);
        void enable(void);
        void disable(void);
        void update(void);

    private:
        static unsigned int light_counter;
        GLuint gl_id;
};

}; // namespace video

}; // namespace huge

#endif

