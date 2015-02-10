#ifndef _huge_opengl_texture_h_
#define _huge_opengl_texture_h_
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

#include <GL/glew.h>
#include <GL/gl.h>

#include <huge/material/texture.h>

namespace huge
{

namespace video
{

class GL_Texture
{
    public:
        GL_Texture();
        GL_Texture(GLenum target_);
        ~GL_Texture();

        void load(Texture *texture);
        void load(GLint bpp, GLsizei width, GLsizei height, const GLvoid *data);
        void load(GLint level, GLint bpp, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *data);
        void bind();

        //private:
        GLuint gl_id;
        GLenum target;
};

};

};

#endif

