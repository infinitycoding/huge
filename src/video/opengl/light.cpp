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

#include "video/device.h"
#include "video/opengl.h"

#include "light.h"

#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>

namespace huge
{

namespace video
{

namespace gl
{

unsigned int Light::light_counter = 0;

Light::Light()
{
    this->gl_id = GL_LIGHT0 + (GLuint) Light::light_counter++;
}

Light::~Light()
{
}

void Light::set(huge::Light *light)
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

void Light::enable(void)
{
    glEnable(this->gl_id);
}

void Light::disable(void)
{
    glDisable(this->gl_id);
}

void Light::update(void)
{
    glLightfv(this->gl_id, GL_AMBIENT, (GLfloat*) &this->ambient.data);
    glLightfv(this->gl_id, GL_DIFFUSE, (GLfloat*) &this->diffuse.data);
    glLightfv(this->gl_id, GL_SPECULAR, (GLfloat*) &this->specular.data);
    glLightfv(this->gl_id, GL_POSITION, (GLfloat*) &this->position.data);
}

};
};
};

