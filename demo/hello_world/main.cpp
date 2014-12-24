#include <stdio.h>
#include "huge.h"
#include "graphics/opengl.h"

using namespace huge;

int main(int argc, char **argv)
{
    printf("Hello World!\n");
    test();

    // vector test
    Vector3f *vec = new Vector3f();
    *vec = Vector3f(5.0f, 2.0f, 7.0f) + Vector3f(2.2f, 4.3f, 5.6f);
    *vec *= 5.303f;
    *vec /= 2.04f;

    vec->x() = 2.0f;

    printf("vec: %f, %f, %f\n", vec->x(), vec->y(), vec->z());


    Vector<1, Vector3i > *vec2 = new Vector<1, Vector3i >();
    vec2->data[0].data[0] = 0;
    vec2->data[0].data[1] = 0;
    vec2->data[0].data[2] = 0;

    *vec2 += 1;
    *vec2 += Vector3i(1, 2, 3);

    printf("vec2: %d, %d, %d\n", vec2->data[0].data[0], vec2->data[0].data[1], vec2->data[0].data[2]);


    // Transformation
    Transformation2f trans = Transformation2f();
    Transformation2f trans2 = Transformation2f();

    trans.translation() = Vector2f(1.0f, 2.0f);
    trans2.parent_translation(trans);

    printf("%f, %f - %f, %f\n", trans.translation().x(), trans.translation().y(), trans2.translation().x(), trans2.translation().y());


    Color3f c = Color3f(0xca, 0x12, 0xef);
    printf("%f, %f, %f\n", c.r(), c.g(), c.b());

    // opengl test
    sdl::init();
    sdl::Window *window = new sdl::Window();

    GraphicsDevice *dev = new OpenGLDevice();

    while(1)
    {
        SDL_Event e;
        while(SDL_PollEvent(&e))
        {
            if(e.type == SDL_QUIT)
            {
                exit(0);
            }
        }

        dev->clear(COLOR_BUFFER_BIT | DEPTH_BUFFER_BIT);

        dev->begin(TRIANGLES);

        glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
        dev->vertex3f(Vector3f( 0.0f, 1.0f, 0.0f));
        dev->vertex3f(Vector3f( 1.0f,-1.0f, 0.0f));
        dev->vertex3f(Vector3f(-1.0f,-1.0f, 0.0f));

        dev->end();

        window->swap();
    }

    return 0;
}

