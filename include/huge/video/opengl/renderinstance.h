#ifndef _huge_opengl_renderinstance_h_
#define _huge_opengl_renderinstance_h_
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

#include <huge/object/mesh.h>
#include <huge/video/opengl/buffer.h>

namespace huge
{

namespace video
{

class GL_RenderInstance
{
    public:
        GL_RenderInstance();
        GL_RenderInstance(Mesh *mesh);
        ~GL_RenderInstance();

        void render(void);

    private:
        GLuint vao_id;
        unsigned int num_indices;
        GL_Buffer *indices;
        GL_Buffer *vertices;
        GL_Buffer *normals;
        GL_Buffer *texcoords;
};

}; // namespace video

}; // namespace huge

#endif

