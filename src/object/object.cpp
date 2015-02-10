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

#include <huge/object/object.h>
#include <huge/object/mesh.h>
#include <huge/video/device.h>
#include <huge/material/material.h>

namespace huge
{

Object::Object()
{
}

Object::Object(Mesh *mesh_)
    : mesh(mesh_)
{
}

Object::Object(Mesh *mesh_, Vector3f trans)
    : mesh(mesh_)
{
    this->translation() = trans;
}

Object::Object(Mesh *mesh_, Material *material_)
    : mesh(mesh_), material(material_)
{
}

Object::Object(Mesh *mesh_, Material *material_, Vector3f trans)
    : mesh(mesh_), material(material_)
{
    this->translation() = trans;
}

Object::~Object()
{
}

void Object::renderImmediate(video::Device *device)
{
    if(this->material != NULL)
    {
        this->material->useOld(device);
    }

    device->pushMatrix();
    this->useTransformation(device);
    this->mesh->renderImmediate(device);
    device->popMatrix();
}

}; // namespace huge

