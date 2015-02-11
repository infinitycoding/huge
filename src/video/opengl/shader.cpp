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

#include <stdio.h>
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include <huge/video/opengl/shader.h>

namespace huge
{

namespace video
{

GLSL_Shader::GLSL_Shader()
{
}

GLSL_Shader::GLSL_Shader(GLuint type, const char *source, int len)
{
    this->compile(type, source, len);
}

GLSL_Shader::~GLSL_Shader()
{
    glDeleteShader(this->gl_id);
}

void GLSL_Shader::compile(GLuint type, const char *source, int len)
{
    this->gl_id = glCreateShader(type);

    glShaderSource(this->gl_id, 1, (const GLchar**) &source, &len);
    glCompileShader(this->gl_id);

    int llen;
    glGetShaderiv(this->gl_id, GL_INFO_LOG_LENGTH , &llen);
    GLchar log[llen+1];
    glGetShaderInfoLog(this->gl_id, llen+1, &llen, (GLchar*) &log);

    const char *shadertype;
    switch(type)
    {
        case GL_VERTEX_SHADER:
            shadertype = "vertexshader";
            break;
        case GL_GEOMETRY_SHADER:
            shadertype = "geometryshader";
            break;
        case GL_FRAGMENT_SHADER:
            shadertype = "fragmentshader";
            break;
    }

    if(llen > 1)
    {
        printf("compiling %s:\n%s\n", shadertype, log);
    }
    else
    {
        printf("shader compiled\n");
    }
}

GLSL_Program::GLSL_Program()
{
    this->gl_id = glCreateProgram();
}

GLSL_Program::~GLSL_Program()
{
    glDeleteProgram(this->gl_id);
}

void GLSL_Program::attach(GLSL_Shader *shader)
{
    glAttachShader(this->gl_id, shader->gl_id);
}

void GLSL_Program::link(void)
{
    glLinkProgram(this->gl_id);

    int len;
    glGetProgramiv(this->gl_id, GL_INFO_LOG_LENGTH , &len);
    char log[len+1];
    glGetProgramInfoLog(this->gl_id, len+1, &len, (GLchar*) &log);

    if(len > 1)
    {
        printf("linking program:\n%s\n", log);
    }
    else
    {
        printf("program linked\n");
    }
}

void GLSL_Program::use(void)
{
    glUseProgram(this->gl_id);
}

GLuint GLSL_Program::getUniformLocation(const char *name)
{
    return glGetUniformLocation(this->gl_id, (const GLchar*) name);
}

}; // namespace video

}; // namespace huge

