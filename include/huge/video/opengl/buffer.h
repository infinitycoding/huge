#ifndef _huge_opengl_buffer_h_
#define _huge_opengl_buffer_h_
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
        along with HUGE. If not, see <http://www.gnu.org/licenses/>.
*/

/*
	@author Michael Sippel <micha@infinitycoding.de>
 */

#include <GL/glew.h>
#include <GL/gl.h>
#include <stdint.h>

namespace huge
{

namespace video
{

class GL_Buffer
{
    public:
        GL_Buffer();
        GL_Buffer(GLenum target);
        ~GL_Buffer();

        void bind(void);
        void loadData(size_t size, const void *data, GLenum usage);

    private:
        inline void create(void);

        GLuint gl_id;
        GLenum gl_target;
};

}; // namespace video

}; // namespace huge

#endif

