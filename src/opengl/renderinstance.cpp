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
        along with HUGE. If not, see <http://www.gnu.org/licenses/>.
*/

/*
	@author Michael Sippel <micha@infinitycoding.de>
 */

#include <GL/glew.h>
#include <GL/gl.h>
#include <stdlib.h>

#include <huge/video/opengl/renderinstance.h>


namespace huge
{

namespace video
{

GL_RenderInstance::GL_RenderInstance(Mesh *mesh)
{
    int i,j,l;

    // indices
    this->num_indices = 0;
    unsigned int num_vertices = 0;
    for(i = 0; i < mesh->num_faces; i++)
    {
        this->num_indices += mesh->faces[i]->num_vertices - 2;
        num_vertices += mesh->faces[i]->num_vertices;
    }

    this->num_indices *= 3;
    unsigned int *index_buf = (unsigned int*) calloc(this->num_indices, sizeof(unsigned int));
    Vector3f *vertex_buf = (Vector3f*) calloc(num_vertices, sizeof(Vector3f));
    Vector3f *normal_buf = (Vector3f*) calloc(num_vertices, sizeof(Vector3f));
    Vector2f *texcoord_buf = (Vector2f*) calloc(num_vertices, sizeof(Vector2f));

	// triangulate mesh
    int cur_index = 0;
    int cur_vertex = 0;
    for(i = 0; i < mesh->num_faces; i++)
    {
        Face *face = mesh->faces[i];
        for(j = 0; j < face->num_vertices-2; j++)
        {
            for(l = 0; l < j+3; l++)
            {
                index_buf[cur_index] = cur_vertex + l;
                cur_index++;

                if(l == 0) l = j;
            }
        }

        for(j = 0; j < face->num_vertices; j++)
        {
            vertex_buf[cur_vertex].x() = mesh->vertices[face->vertices[j]].x();
            vertex_buf[cur_vertex].y() = mesh->vertices[face->vertices[j]].y();
            vertex_buf[cur_vertex].z() = mesh->vertices[face->vertices[j]].z();

            if(mesh->normals != NULL)
            {
                normal_buf[cur_vertex].x() = mesh->normals[face->vertices[j]].x();
                normal_buf[cur_vertex].y() = mesh->normals[face->vertices[j]].y();
                normal_buf[cur_vertex].z() = mesh->normals[face->vertices[j]].z();
            }

            if(mesh->texcoords != NULL && face->texcoords != NULL)
            {
                texcoord_buf[cur_vertex].x() = mesh->texcoords[face->texcoords[j]].x();
                texcoord_buf[cur_vertex].y() = mesh->texcoords[face->texcoords[j]].y();
            }

            cur_vertex++;
        }
    }

	this->indices = new GL_Buffer(GL_ELEMENT_ARRAY_BUFFER);
	this->vertices = new GL_Buffer(GL_ARRAY_BUFFER);
	this->normals = new GL_Buffer(GL_ARRAY_BUFFER);
	this->texcoords = new GL_Buffer(GL_ARRAY_BUFFER);

    this->indices->loadData(this->num_indices*sizeof(unsigned int), index_buf, GL_STATIC_DRAW);
    this->vertices->loadData(num_vertices*sizeof(Vector3f), vertex_buf, GL_STATIC_DRAW);
    this->normals->loadData(num_vertices*sizeof(Vector3f), normal_buf, GL_STATIC_DRAW);
    this->texcoords->loadData(num_vertices*sizeof(Vector2f), texcoord_buf, GL_STATIC_DRAW);

	glGenVertexArrays(1, &this->vao_id);
	glBindVertexArray(this->vao_id);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	this->normals->bind();
	glNormalPointer(GL_FLOAT, 0, NULL);

	this->vertices->bind();
	glVertexPointer(3, GL_FLOAT, 0, NULL);

	this->texcoords->bind();
	glTexCoordPointer(2, GL_FLOAT, 0, NULL);

	glBindVertexArray(0);
}

GL_RenderInstance::~GL_RenderInstance()
{
    delete this->indices;
    delete this->vertices;
    delete this->normals;
    delete this->texcoords;
}

void GL_RenderInstance::render(void)
{
	glBindVertexArray(this->vao_id);

	this->indices->bind();
	glDrawElements(GL_TRIANGLES, this->num_indices, GL_UNSIGNED_INT, NULL);
}

}; // namespace video

}; // namespace huge

