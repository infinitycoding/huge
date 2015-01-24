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

#include "math/vector.h"
#include "math/transformation.h"
#include "video/device.h"
#include "object.h"

namespace huge
{

Face::Face()
    : num_vertices(0), vertices(NULL)
{
}

Face::Face(int num_vertices_, int *vertices_)
    : num_vertices(num_vertices_), vertices(vertices_)
{
}

Face::~Face()
{
}

Mesh::Mesh()
    : num_vertices(0), vertices(NULL), num_faces(0), faces(NULL)
{
}

Mesh::Mesh(int num_vertices_, Vector3f *vertices_, int num_faces_, Face **faces_)
    : num_vertices(num_vertices_), vertices(vertices_), num_faces(num_faces_), faces(faces_)
{
}

Mesh::~Mesh()
{
}

void Mesh::renderImmediate(video::Device *device)
{
    int i,j;

    for(i = 0; i < this->num_faces; i++)
    {
        Face *face = this->faces[i];

        device->begin(video::POLYGON);

        for(j = 0; j < face->num_vertices; j++)
        {
            int id = face->vertices[j];
            if(id < this->num_vertices)
                device->vertex3(this->vertices[id]);
        }

        device->end();
    }
}

};

