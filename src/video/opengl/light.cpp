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
#include <GL/glu.h>

#include <huge/video/device.h>
#include <huge/video/opengl/device.h>
#include <huge/video/opengl/light.h>
#include <huge/light.h>

namespace huge
{

namespace video
{

unsigned int GL_Light::light_counter = 0;

GL_Light::GL_Light()
{
    this->gl_id = GL_LIGHT0 + (GLuint) GL_Light::light_counter++;
}

GL_Light::GL_Light(Light *light)
{
	GL_Light();
	this->set(light);
}

GL_Light::~GL_Light()
{
}

void GL_Light::set(Light *light)
{
    this->ambient = light->color * 0.1f;
    this->diffuse = light->color * 0.8f;
    this->specular = light->color;
    this->position = Vector4f(0.0f, 0.0f, 0.0f, 1.0f);

    switch(light->type)
    {
        case POINT:
            this->position.w() = 1.0f;
            break;

        case PARALLEL:
            this->position.w() = 0.0f;
            break;
    };
}

void GL_Light::enable(void)
{
    glEnable(this->gl_id);
}

void GL_Light::disable(void)
{
    glDisable(this->gl_id);
}

void GL_Light::update(void)
{
    glLightfv(this->gl_id, GL_AMBIENT, (GLfloat*) &this->ambient.data);
    glLightfv(this->gl_id, GL_DIFFUSE, (GLfloat*) &this->diffuse.data);
    glLightfv(this->gl_id, GL_SPECULAR, (GLfloat*) &this->specular.data);
    glLightfv(this->gl_id, GL_POSITION, (GLfloat*) &this->position.data);
}

}; // namespace video

}; // namespace huge

