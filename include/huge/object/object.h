#ifndef _huge_object_h_
#define _huge_object_h_
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

#include <huge/list.h>
#include <huge/material/material.h>
#include <huge/math/vector.h>
#include <huge/math/transformation.h>
#include <huge/video/device.h>
#include <huge/object/mesh.h>

namespace huge
{

class Object : public Transformation3f
{
    public:
        Object();
        Object(Mesh *mesh_);
        Object(Mesh *mesh_, Vector3f trans);
        Object(Mesh *mesh_, Material *material_);
        Object(Mesh *mesh_, Material *material_, Vector3f trans);
        ~Object();

        Mesh *mesh;
        Material *material;

        void render(video::Device *device);
        void renderImmediate(video::Device *device);
};

}; // namespace huge

#endif

