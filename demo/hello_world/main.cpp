#include <stdio.h>
#include "huge.h"
#include "video/opengl.h"

using namespace huge;

int main(int argc, char **argv)
{
    printf("Hello World!\n");
    test();

    sdl::init();
    sdl::Window *window = new sdl::GLWindow();
    VideoContext *context = new sdl::GLContext(window);

    VideoDevice *dev = new OpenGLDevice();
    dev->context = context;

    if(glewInit() != GLEW_OK)
    {
        printf("GLEW init failed!\n");
    }

    Viewport *view = new Viewport();

    view->usePerspective();
    dev->translatef(Vector3f(0.0f, 0.0f, 0.0f));

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
        dev->color4i(Color4ub(0xff, 0x4c, 0x00, 0xff).c2_i());
        dev->vertex3f(Vector3f( 0.0f, 1.0f, 0.0f));
        dev->vertex3f(Vector3f( 1.0f,-1.0f, 0.0f));
        dev->vertex3f(Vector3f(-1.0f,-1.0f, 0.0f));
        dev->end();

        window->swap();
    }

    return 0;
}

