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
#include "graphics/opengl.h"

#include <GL/glew.h>
#include <GL/gl.h>

namespace huge
{

#define lenof(x) (sizeof(x) / sizeof(x[0]))

static GLenum gl_buffer[] =
{
    GL_COLOR_BUFFER_BIT, GL_DEPTH_BUFFER_BIT
};

static GLenum gl_primitive[] =
{
    GL_POINTS, GL_LINES, GL_TRIANGLES, GL_QUADS, GL_POLYGON
};



OpenGLDevice::OpenGLDevice()
{
    if(glewInit() != GLEW_OK)
    {
        printf("GLEW init failed!\n");
    }
};

OpenGLDevice::~OpenGLDevice()
{
}

void OpenGLDevice::clear(bitfield_t buffers)
{
    GLbitfield b = 0;

    unsigned int i;
    for(i = 0; i < lenof(gl_buffer); i++)
    {
        if(buffers & (1<<i))
            b |= gl_buffer[i];
    }

    glClear(b);
}

void OpenGLDevice::begin(enum primitive t)
{
    glBegin(gl_primitive[t]);
}

void OpenGLDevice::end(void)
{
    glEnd();
}

void OpenGLDevice::vertex3f(Vector3f v)
{
    glVertex3fv((GLfloat*) &v.data);
}

void OpenGLDevice::not_supported(const char *str)
{
    printf("OpenGLDevice: \"%s\" is not supported.\n", str);
}

};

