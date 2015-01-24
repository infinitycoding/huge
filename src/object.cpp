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

#include <stdlib.h>

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
    : num_vertices(num_vertices_), vertices(vertices_),
      num_faces(num_faces_), faces(faces_)
{
    this->calc_normals();
}

Mesh::Mesh(int num_vertices_, Vector3f *vertices_, int num_texcoords_, Vector2f *texcoords_, int num_faces_, Face **faces_)
    : num_vertices(num_vertices_), vertices(vertices_),
      num_texcoords(num_texcoords_), texcoords(texcoords_),
      num_faces(num_faces_), faces(faces_)
{
    this->calc_normals();
}

Mesh::~Mesh()
{
}

void Mesh::calc_normals(void)
{
    this->normals = (Vector3f*) calloc(this->num_vertices, sizeof(Vector3f));

    int i, j;
    int *common_face_count = (int*) calloc(this->num_vertices, sizeof(int));

    for(i = 0; i < this->num_faces; i++)
    {
        Face *face = this->faces[i];

        Vector3f edge1 = Vector3f(this->vertices[face->vertices[0]], this->vertices[face->vertices[1]]);
        Vector3f edge2 = Vector3f(this->vertices[face->vertices[1]], this->vertices[face->vertices[2]]);

        face->normal = cross(edge1, edge2);
        face->normal.normalize();

        for(j = 0; j < face->num_vertices; j++)
        {
            this->normals[face->vertices[j]] += face->normal;
            common_face_count[face->vertices[j]]++;
        }
    }

    for(i = 0; i < this->num_vertices; i++)
    {
        this->normals[i] /= (float) common_face_count[i];
        this->normals[i].normalize();
    }

    free(common_face_count);
}

void Mesh::renderImmediate(video::Device *device)
{
    int i,j;

    for(i = 0; i < this->num_faces; i++)
    {
        Face *face = this->faces[i];

        device->begin(video::POLYGON);

        //device->normal(face->normal);

        for(j = 0; j < face->num_vertices; j++)
        {
            int id = face->vertices[j];
            if(id < this->num_vertices)
            {
                if(this->normals != NULL)
                    device->normal(this->normals[id]);

                if(this->vertices != NULL)
                    device->vertex(this->vertices[id]);
            }
        }

        device->end();
    }
}

};

