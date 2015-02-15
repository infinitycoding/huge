#ifndef _huge_video_device_h_
#define _huge_video_device_h_
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
#include <stdio.h>

#include <huge/color.h>
#include <huge/list.h>
#include <huge/math/vector.h>
#include <huge/video/context.h>

namespace huge
{

template <typename T> class Transformation2;
template <typename T> class Transformation3;
class Light;
class Material;
class Viewport;
template <unsigned int N, typename T> class Texture;
class Mesh;

namespace video
{

#define xstr(s) str(s)
#define str(s) #s

#define DUMMY(X) virtual X { not_supported(str(X)); }
#define IDUMMY(X) virtual inline X { not_supported(str(X)); }

enum device_type
{
    NULL_DEVICE,
    OPENGL_DEVICE
};

enum buffer
{
    COLOR_BUFFER_BIT = 0x1,
    DEPTH_BUFFER_BIT = 0x2
};

enum primitive
{
    POINTS, LINES, TRIANGLES, QUADS, POLYGON
};

enum matrix_mode
{
    MODELVIEW, PROJECTION, TEXTURE, COLOR
};

typedef unsigned int bitfield_t;

struct abstraction_entry
{
    void *abstract;
    void *specific;
};

class Device
{
    public:
        Device();
        Device(Context *context_);
        ~Device();

        static const enum device_type type = NULL_DEVICE;
        Context *context;

        List<struct abstraction_entry> *device_objects;
        virtual inline List<struct abstraction_entry>*& type_objects(void) = 0;

        void *getDeviceObject(void *obj);
        void addDeviceObject(void *abstract, void *specific);

        void *getTypeObject(void *obj);
        void addTypeObject(void *abstract, void *specific);

        template <typename T1, typename T2>
        T1 *deviceObject(T2 *a)
        {
            T1 *s = (T1*) this->getDeviceObject((void*) a);
            if(s == NULL)
            {
                s = new T1(a);
                this->addDeviceObject((void*) a, (void*) s);
            }
            return s;
        }

        template <typename T1, typename T2>
        T1 *typeObject(T2 *a)
        {
            T1 *s = (T1*) this->getTypeObject((void*) a);
            if(s == NULL)
            {
                s = new T1(a);
                this->addTypeObject((void*) a, (void*) s);
            }
            return s;
        }

        //
        // wrappers for better use
        //

        template <typename T> void transform(Transformation2<T> t)
        {
            t.useTransformation(this);
        }
        template <typename T> void transform(Transformation3<T> t)
        {
            t.useTransformation(this);
        }

        void useViewport(Viewport *viewport);

        //
        // specific virtual functions
        //

        // buffer
        DUMMY(void clear(bitfield_t buffers));
        DUMMY(void clearColor(Color4d col));
        DUMMY(void setViewport(Vector2i position, Vector2i size));
        DUMMY(void begin(enum primitive t));
        DUMMY(void end(void));

        // matrix
        DUMMY(void setMatrixMode(enum matrix_mode m));
        DUMMY(void setPerspective(double fovy, double aspect, double znear, double zfar));
        DUMMY(void loadIdentity(void));
        DUMMY(void pushMatrix(void));
        DUMMY(void popMatrix(void));

        DUMMY(void translate(Vector3f v));
        DUMMY(void translate(Vector3d v));
        DUMMY(void rotate(Vector3f v, float angle));
        DUMMY(void rotate(Vector3d v, double angle));
        DUMMY(void scale(Vector3f v));
        DUMMY(void scale(Vector3d v));

        // vertex data
        DUMMY(void vertex(Vector2f v));
        DUMMY(void vertex(Vector2d v));
        DUMMY(void vertex(Vector3f v));
        DUMMY(void vertex(Vector3d v));

        // normal data
        DUMMY(void normal(Vector3f v));
        DUMMY(void normal(Vector3d v));

        // texcoord data
        DUMMY(void texcoord(Vector2f v));

        // color data
        DUMMY(void color(Color3b c));
        DUMMY(void color(Color3ub c));
        DUMMY(void color(Color3s c));
        DUMMY(void color(Color3us c));
        DUMMY(void color(Color3i c));
        DUMMY(void color(Color3ui c));
        DUMMY(void color(Color3f c));
        DUMMY(void color(Color3d c));

        DUMMY(void color(Color4b c));
        DUMMY(void color(Color4ub c));
        DUMMY(void color(Color4s c));
        DUMMY(void color(Color4us c));
        DUMMY(void color(Color4i c));
        DUMMY(void color(Color4ui c));
        DUMMY(void color(Color4f c));
        DUMMY(void color(Color4d c));

        // light data
        DUMMY(void enableLight(Light *light));
        DUMMY(void disableLight(Light *light));
        DUMMY(void updateLight(Light *light));

        // material
        DUMMY(void material_ambient(Color4f c));
        DUMMY(void material_diffuse(Color4f c));
        DUMMY(void material_specular(Color4f c));
        DUMMY(void material_emission(Color4f c));
        DUMMY(void material_shininess(float v));

        // texture
        DUMMY(void enableTexture(unsigned int layer));
        DUMMY(void disableTexture(unsigned int layer));
        DUMMY(void bindTexture(unsigned int layer, Texture<2, unsigned char> *texture));

        // mesh rendering
        DUMMY(void renderMesh(Mesh *mesh));

    private:
        virtual void not_supported(const char *str);

};

#undef DUMMY
#undef str
#undef xstr

}; // namespace video

}; // namespace huge

#endif

