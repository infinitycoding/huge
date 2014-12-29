#include <stdio.h>
#include "huge.h"
#include "graphics/opengl.h"

using namespace huge;

int main(int argc, char **argv)
{
    printf("Hello World!\n");
    test();

    sdl::init();
    sdl::Window *window = new sdl::GLWindow();

    GraphicsDevice *dev = new OpenGLDevice();
    window->gdev = dev;

	Color3<unsigned char> c = Color3f(0.5, 1.0, 0.3).convert<unsigned char>();
	printf("%i, %i, %i\n", c.r(), c.g(), c.b());
	
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
        dev->color4f(Color4f(1.0f, 0.0f, 0.0f, 1.0f));
        dev->vertex3f(Vector3f( 0.0f, 1.0f, 0.0f));
        dev->vertex3f(Vector3f( 1.0f,-1.0f, 0.0f));
        dev->vertex3f(Vector3f(-1.0f,-1.0f, 0.0f));
        dev->end();

        window->swap();
    }

    return 0;
}

