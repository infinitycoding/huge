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
#include <GL/glu.h>

#include <huge/video/device.h>
#include <huge/video/opengl/device.h>
#include <huge/video/opengl/light.h>
#include <huge/video/opengl/texture.h>
#include <huge/video/opengl/renderinstance.h>

#include <huge/light.h>
#include <huge/material/material.h>
#include <huge/object/mesh.h>

namespace huge
{

namespace video
{

#define lenof(x) (sizeof(x) / sizeof(x[0]))

static GLenum gl_buffer[] =
{
    GL_COLOR_BUFFER_BIT, GL_DEPTH_BUFFER_BIT
};

static GLenum gl_primitive[] =
{
    GL_POINTS, GL_LINES, GL_TRIANGLES, GL_QUADS, GL_POLYGON
};

static GLenum gl_matrix_mode[] =
{
    GL_MODELVIEW, GL_PROJECTION, GL_TEXTURE, GL_COLOR
};

List<struct abstraction_entry> *OpenGLDevice::gl_objects = new List<struct abstraction_entry>();

OpenGLDevice::OpenGLDevice()
{
}

OpenGLDevice::OpenGLDevice(video::Context *context_)
{
    this->context = context_;
}

OpenGLDevice::~OpenGLDevice()
{
}

inline List<struct abstraction_entry>*& OpenGLDevice::type_objects(void)
{
    return this->gl_objects;
}

#define ACTIVATE	this->context->activate();

// buffers
void OpenGLDevice::clear(bitfield_t buffers)
{
    ACTIVATE;
    GLbitfield b = 0;

    unsigned int i;
    for(i = 0; i < lenof(gl_buffer); i++)
    {
        if(buffers & (1<<i))
            b |= gl_buffer[i];
    }

    glClear(b);
}

void OpenGLDevice::clearColor(Color4d c)
{
    ACTIVATE;
    glClearColor(c.data[0], c.data[1], c.data[2], c.data[3]);
}

void OpenGLDevice::setViewport(Vector2i position, Vector2i size)
{
    ACTIVATE;
    glViewport(position.data[0], position.data[1], size.data[0], size.data[1]);
}

void OpenGLDevice::begin(enum primitive t)
{
    ACTIVATE;
    glBegin(gl_primitive[t]);
}

void OpenGLDevice::end(void)
{
    ACTIVATE;
    glEnd();
}

// matrix
void OpenGLDevice::setMatrixMode(enum matrix_mode m)
{
    ACTIVATE;
    glMatrixMode(gl_matrix_mode[m]);
}

void OpenGLDevice::setPerspective(double fovy, double aspect, double znear, double zfar)
{
    ACTIVATE;
    gluPerspective((GLdouble) fovy, (GLdouble) aspect, (GLdouble) znear, (GLdouble) zfar);
}

void OpenGLDevice::loadIdentity(void)
{
    ACTIVATE;

    glLoadIdentity();
}

void OpenGLDevice::pushMatrix(void)
{
    ACTIVATE;
    glPushMatrix();
}
void OpenGLDevice::popMatrix(void)
{
    ACTIVATE;
    glPopMatrix();
}

void OpenGLDevice::translate(Vector3f v)
{
    ACTIVATE;
    glTranslatef(v.data[0], v.data[1], v.data[2]);
}

void OpenGLDevice::translate(Vector3d v)
{
    ACTIVATE;
    glTranslated(v.data[0], v.data[1], v.data[2]);
}

void OpenGLDevice::rotate(Vector3f v, float angle)
{
    ACTIVATE;
    glRotatef(angle, v.data[0], v.data[1], v.data[2]);
}
void OpenGLDevice::rotate(Vector3d v, double angle)
{
    ACTIVATE;
    glRotated(angle, v.data[0], v.data[1], v.data[2]);
}

void OpenGLDevice::scale(Vector3f v)
{
    ACTIVATE;
    glScalef(v.data[0], v.data[1], v.data[2]);
}
void OpenGLDevice::scale(Vector3d v)
{
    ACTIVATE;
    glScaled(v.data[0], v.data[1], v.data[2]);
}

// vertex data
void OpenGLDevice::vertex(Vector2f v)
{
    ACTIVATE;
    glVertex2fv((GLfloat*) &v.data);
}

void OpenGLDevice::vertex(Vector3f v)
{
    ACTIVATE;
    glVertex3fv((GLfloat*) &v.data);
}

void OpenGLDevice::vertex(Vector2d v)
{
    ACTIVATE;
    glVertex2dv((GLdouble*) &v.data);
}

void OpenGLDevice::vertex(Vector3d v)
{
    ACTIVATE;
    glVertex3dv((GLdouble*) &v.data);
}

// normal data
void OpenGLDevice::normal(Vector3f v)
{
    ACTIVATE;
    glNormal3fv((GLfloat*) &v.data);
}

void OpenGLDevice::normal(Vector3d v)
{
    ACTIVATE;
    glNormal3dv((GLdouble*) &v.data);
}

// texcoord data
void OpenGLDevice::texcoord(Vector2f v)
{
    ACTIVATE;
    glMultiTexCoord2fv(GL_TEXTURE0, (GLfloat*) &v.data);
    glMultiTexCoord2fv(GL_TEXTURE1, (GLfloat*) &v.data);
}

// color data
void OpenGLDevice::color(Color3b c)
{
    ACTIVATE;
    glColor3bv((GLbyte*) &c.data);
}

void OpenGLDevice::color(Color4b c)
{
    ACTIVATE;
    glColor4bv((GLbyte*) &c.data);
}

void OpenGLDevice::color(Color3ub c)
{
    ACTIVATE;
    glColor3ubv((GLubyte*) &c.data);
}

void OpenGLDevice::color(Color4ub c)
{
    ACTIVATE;
    glColor3ubv((GLubyte*) &c.data);
}

void OpenGLDevice::color(Color3s c)
{
    ACTIVATE;
    glColor3sv((GLshort*) &c.data);
}

void OpenGLDevice::color(Color4s c)
{
    ACTIVATE;
    glColor3sv((GLshort*) &c.data);
}

void OpenGLDevice::color(Color3us c)
{
    ACTIVATE;
    glColor3usv((GLushort*) &c.data);
}

void OpenGLDevice::color(Color4us c)
{
    ACTIVATE;
    glColor4usv((GLushort*) &c.data);
}

void OpenGLDevice::color(Color3i c)
{
    ACTIVATE;
    glColor3iv((GLint*) &c.data);
}

void OpenGLDevice::color(Color4i c)
{
    ACTIVATE;
    glColor4iv((GLint*) &c.data);
}

void OpenGLDevice::color(Color3ui c)
{
    ACTIVATE;
    glColor3uiv((GLuint*) &c.data);
}

void OpenGLDevice::color(Color4ui c)
{
    ACTIVATE;
    glColor4uiv((GLuint*) &c.data);
}

void OpenGLDevice::color(Color3f c)
{
    ACTIVATE;
    glColor3fv((GLfloat*) &c.data);
}

void OpenGLDevice::color(Color4f c)
{
    ACTIVATE;
    glColor4fv((GLfloat*) &c.data);
}

void OpenGLDevice::color(Color3d c)
{
    ACTIVATE;
    glColor3dv((GLdouble*) &c.data);
}

void OpenGLDevice::color(Color4d c)
{
    ACTIVATE;
    glColor4dv((GLdouble*) &c.data);
}

// light data
void OpenGLDevice::enableLight(Light *light)
{
    ACTIVATE;
    this->deviceObject<GL_Light, Light>(light)->enable();
};

void OpenGLDevice::disableLight(Light *light)
{
    ACTIVATE;
    this->deviceObject<GL_Light, Light>(light)->disable();
};

void OpenGLDevice::updateLight(Light *light)
{
    ACTIVATE;
    GL_Light *gll = this->deviceObject<GL_Light, Light>(light);
    gll->set(light);
    gll->update();
};

// material data

void OpenGLDevice::material_ambient(Color4f c)
{
    ACTIVATE;
    glMaterialfv(GL_FRONT, GL_AMBIENT, (GLfloat*) &c.data);
}

void OpenGLDevice::material_diffuse(Color4f c)
{
    ACTIVATE;
    glMaterialfv(GL_FRONT, GL_DIFFUSE, (GLfloat*) &c.data);
}

void OpenGLDevice::material_specular(Color4f c)
{
    ACTIVATE;
    glMaterialfv(GL_FRONT, GL_SPECULAR, (GLfloat*) &c.data);
}

void OpenGLDevice::material_emission(Color4f c)
{
    ACTIVATE;
    glMaterialfv(GL_FRONT, GL_EMISSION, (GLfloat*) &c.data);
}

void OpenGLDevice::material_shininess(float v)
{
    ACTIVATE;
    glMaterialfv(GL_FRONT, GL_SHININESS, (GLfloat*) &v);
}

// texture
void OpenGLDevice::enableTexture(unsigned int layer)
{
    ACTIVATE;
    glActiveTexture(GL_TEXTURE0 + layer);
    glEnable(GL_TEXTURE_2D);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
}

void OpenGLDevice::disableTexture(unsigned int layer)
{
    ACTIVATE;
    glActiveTexture(GL_TEXTURE0 + layer);
    glDisable(GL_TEXTURE_2D);
}

void OpenGLDevice::bindTexture(unsigned int layer, Texture2ub *texture)
{
    ACTIVATE;
    glActiveTexture(GL_TEXTURE0 + layer);
    this->deviceObject<GL_Texture, Texture2ub>(texture)->bind();
}

void OpenGLDevice::renderMesh(Mesh *mesh)
{
    ACTIVATE;
    this->deviceObject<GL_RenderInstance, Mesh>(mesh)->render();
}

void OpenGLDevice::not_supported(const char *str)
{
    printf("OpenGLDevice: \"%s\" is not supported.\n", str);
}

}; // namespace video

}; // namespace huge

