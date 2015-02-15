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

#include <huge/math/vector.h>
#include <huge/material/texture.h>

namespace huge
{

namespace video
{

class GL_Texture
{
    public:
        GL_Texture();
        GL_Texture(GLenum target);
        GL_Texture(Texture2ub *texture);
        ~GL_Texture();

        void load(Texture2ub *texture);
        void load(unsigned int bpp, Vector<1, size_t> size, GLenum type, const void *data);
        void load(unsigned int bpp, Vector<2, size_t> size, GLenum type, const void *data);
        void load(unsigned int bpp, Vector<3, size_t> size, GLenum type, const void *data);
        void load(unsigned int level, unsigned int bpp, Vector<1, size_t> size, int border, GLenum format, GLenum type, const void *data);
        void load(unsigned int level, unsigned int bpp, Vector<2, size_t> size, int border, GLenum format, GLenum type, const void *data);
        void load(unsigned int level, unsigned int bpp, Vector<3, size_t> size, int border, GLenum format, GLenum type, const void *data);
        void bind(void);

    private:
        inline void create(void);

        GLuint gl_id;
        GLenum gl_target;
};

};

};

#endif

