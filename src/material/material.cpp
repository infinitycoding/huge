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

/*
	@author Michael Sippel <micha@infinitycoding.de>
 */

#include <huge/material/material.h>
#include <huge/video/device.h>

namespace huge
{

Material::Material()
{
    this->color = Color4f(1.0f, 1.0f, 1.0f, 1.0f);
    this->emission = Color4f(0.0f, 0.0f, 0.0f, 1.0f);
    this->roughness = 0.8f;
}

Material::Material(Color4f color_)
    : color(color_)
{
    this->emission = Color4f();
    this->roughness = 0.8f;
}

Material::Material(Color4f color_, float roughness_)
    :color(color_), roughness(roughness_)
{
    this->emission = Color4f(0.0f, 0.0f, 0.0f, 1.0f);
}

Material::Material(Color4f color_, Color4f emission_)
    :color(color_), emission(emission_)
{
    this->roughness = 0.8f;
}

Material::Material(Color4f color_, Color4f emission_, float roughness_)
    :color(color_), emission(emission_), roughness(roughness_)
{
}


Material::~Material()
{
}

void Material::useOld(video::Device *device)
{
    Color4f diffuse = this->color;
    diffuse *= this->roughness;
    Color4f specular = this->color;
    specular *= (1.0f- this->roughness);

    device->material_ambient(this->color);
    device->material_diffuse(diffuse);
    device->material_specular(specular);
    device->material_emission(this->emission);
    device->material_shininess(1.0f-this->roughness);
}

}; // namespace huge

