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

#include <stdio.h>
#include <GL/glew.h>
#include <GL/gl.h>

#include <huge/material/texture.h>
#include <huge/video/opengl/texture.h>

namespace huge
{

namespace video
{

GL_Texture::GL_Texture()
    : gl_target(GL_TEXTURE_2D)
{
    this->create();
}

GL_Texture::GL_Texture(GLenum target)
    : gl_target(target)
{
    this->create();
}

GL_Texture::GL_Texture(Texture2ub *texture)
{
    this->create();

    this->gl_target = GL_TEXTURE_2D;
    this->load(texture);
}

GL_Texture::~GL_Texture()
{
    glDeleteTextures(1, &this->gl_id);
}

inline void GL_Texture::create(void)
{
    glGenTextures(1, &this->gl_id);
}

void GL_Texture::load(Texture2ub *texture)
{
    this->load((GLint) texture->bpp, (GLsizei) texture->size.x(), (GLsizei) texture->size.y(), (const GLvoid*) texture->data);
}

void GL_Texture::load(GLint bpp, GLsizei width, GLsizei height, const GLvoid *data)
{
    GLenum format;
    switch(bpp)
    {
        case 3:
            format = GL_RGB;
            break;
        case 4:
            format = GL_RGBA;
            break;
        default:
            return;
    }

    this->load(0, bpp, width, height, 0, format, GL_UNSIGNED_BYTE, data);
}

void GL_Texture::load(GLint level, GLint bpp, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *data)
{
    this->bind();
    glTexImage2D(this->gl_target, level, bpp, width, height, border, format, type, data);

    glTexParameteri(this->gl_target, GL_TEXTURE_MAG_FILTER, GL_LINEAR);//TODO
    glTexParameteri(this->gl_target, GL_TEXTURE_MIN_FILTER, GL_LINEAR);//TODO
}

void GL_Texture::bind(void)
{
    glBindTexture(this->gl_target, this->gl_id);
}

}; // namespace video

}; // namespace huge

