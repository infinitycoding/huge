#ifndef _huge_opengl_shader_h_
#define _huge_opengl_shader_h_
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

#include <GL/glew.h>
#include <GL/gl.h>

namespace huge
{

namespace video
{

class GLSL_Program;

class GLSL_Shader
{
        friend class GLSL_Program;

    public:
        GLSL_Shader();
        GLSL_Shader(GLuint type, const char *source, int len);
        ~GLSL_Shader();

        void compile(GLuint type, const char *source, int len);

    private:
        GLuint gl_id;
};

class GLSL_Program
{
    public:
        GLSL_Program();
        ~GLSL_Program();

        void attach(GLSL_Shader *shader);
        void link(void);
        void use(void);

        //private:
        GLuint gl_id;
};

}; // namespace video

}; // namespace huge

#endif

