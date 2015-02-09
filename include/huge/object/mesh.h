#ifndef _huge_mesh_h_
#define _huge_mesh_h_
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
#include <huge/math/vector.h>
#include <huge/math/transformation.h>
#include <huge/video/device.h>
#include <huge/object/face.h>

namespace huge
{

class Mesh
{
    public:
        Mesh();
        Mesh(int num_vertices_, Vector3f *vertices_, int num_faces_, Face **faces_);
        Mesh(int num_vertices_, Vector3f *vertices_, int num_texcoords_, Vector2f *texcoords_, int num_faces_, Face **faces_);
        ~Mesh();

        void calc_normals(void);

        void renderImmediate(video::Device *device);

    private:
        int num_vertices;
        Vector3f *vertices;
        Vector3f *normals;

        int num_texcoords;
        Vector2f *texcoords;

        int num_faces;
        Face **faces;
};

namespace loader
{
List<Mesh*> *load_obj(const char *path);
}; // namespace loader

}; // namespace huge

#endif

