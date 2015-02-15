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

#include <huge/video/opengl/buffer.h>

namespace huge
{

namespace video
{

GL_Buffer::GL_Buffer()
    : gl_target(GL_ARRAY_BUFFER)
{
    this->create();
}

GL_Buffer::GL_Buffer(GLenum target)
    : gl_target(target)
{
    this->create();
}

GL_Buffer::~GL_Buffer()
{
    glDeleteBuffers(1, &this->gl_id);
}

inline void GL_Buffer::create(void)
{
    glGenBuffers(1, &this->gl_id);
}

void GL_Buffer::bind(void)
{
    glBindBuffer(this->gl_target, this->gl_id);
}

void GL_Buffer::loadData(size_t size, const void *data, GLenum usage)
{
    this->bind();
    glBufferData(this->gl_target, size, data, usage);
}

}; // namespace video

}; // namespace huge

