#include <stdio.h>
#include "huge.h"
#include "video/opengl.h"

using namespace huge;

int main(int argc, char **argv)
{
    printf("Hello World!\n");
    test();

    sdl::init();
    sdl::Window *window1 = new sdl::GLWindow("Window 1", Vector2i(800, 600));
    sdl::Window *window2 = new sdl::GLWindow("Window 2", Vector2i(400, 300));

    VideoContext *context1 = new sdl::GLContext(window1);
    VideoContext *context2 = new sdl::GLContext(window2);

    VideoDevice *dev1 = new OpenGLDevice(context1);
    VideoDevice *dev2 = new OpenGLDevice(context2);

    if(glewInit() != GLEW_OK)
    {
        printf("GLEW init failed!\n");
    }

    Camera *cam1 = new Camera();
    Viewport *view = new Viewport(Vector2i(0, 0), Vector2i(800, 600), cam1);
    dev1->useViewport(view);

    cam1->translation() = Vector3f(0.0f, 0.0f, -5.0f);
    cam1->useTransformation(dev1);

    while(1)
    {
        SDL_Event e;
        while(SDL_PollEvent(&e))
        {
            switch(e.type)
            {
                case SDL_WINDOWEVENT:
                    switch(e.window.event)
                    {
                        case SDL_WINDOWEVENT_CLOSE:
                            SDL_Event quit;
                            quit.type = SDL_QUIT;
                            SDL_PushEvent(&quit);
                            break;
                    }
                    break;
                case SDL_QUIT:
                    exit(0);
            }
        }

        dev1->clear(COLOR_BUFFER_BIT | DEPTH_BUFFER_BIT);
        dev2->clear(COLOR_BUFFER_BIT | DEPTH_BUFFER_BIT);

        dev1->begin(TRIANGLES);
        dev2->begin(TRIANGLES);

        dev1->color4(Color4ub(0xff, 0x4c, 0x00, 0xff));
        dev2->color4(Color4ub(0x4c, 0xff, 0x00, 0xff));

        dev1->vertex3(Vector3f( 0.0f, 1.0f, 0.0f));
        dev2->vertex3(Vector3f( 0.0f, 1.0f, 0.0f));
        dev1->vertex3(Vector3f( 1.0f,-1.0f, 0.0f));
        dev2->vertex3(Vector3f( 1.0f,-1.0f, 0.0f));
        dev1->vertex3(Vector3f(-1.0f,-1.0f, 0.0f));
        dev2->vertex3(Vector3f(-1.0f,-1.0f, 0.0f));

        dev1->end();
        window1->swap();

        dev2->end();
        window2->swap();
    }

    return 0;
}

