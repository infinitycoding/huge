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
        along with the Universe Kernel. If not, see <http://www.gnu.org/licenses/>.
*/

/**
 * @author Michael Sippel <micha@infinitycoding.de>
 */
#include "video/device.h"
#include "color.h"
#include "light.h"

namespace huge
{

unsigned int Light::light_counter = 0;

Light::Light()
{
    Light(Color4f(1.0f, 1.0f, 1.0f, 1.0f));
}

Light::Light(Color4f color)
{
    this->id = Light::light_counter++;

    this->ambient = color * 0.1f;
    this->diffuse = color * 0.8f;
    this->specular = color;
    this->position = Vector4f(0.0f, 0.0f, 0.0f, 1.0f);
}

Light::~Light()
{
}

void Light::update(video::Device *device)
{
    device->light_enable(this->id);
    device->light_ambient(this->id, this->ambient);
    device->light_diffuse(this->id, this->diffuse);
    device->light_specular(this->id, this->specular);
    device->light_position(this->id, this->position);
}

};

