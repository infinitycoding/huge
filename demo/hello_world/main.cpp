#include <stdio.h>
#include "huge.h"
#include "video/opengl.h"

using namespace huge;

VideoDevice *current_video_device;

int main(int argc, char **argv)
{
    printf("Hello World!\n");
    test();

    sdl::init();
    sdl::Window *window = new sdl::GLWindow();

    VideoDevice *dev = new OpenGLDevice();
    window->video_device = dev;
    current_video_device = dev;

    Camera *cam = new Camera();

    cam->usePerspective();
    dev->translatef(Vector3f(0.0f, 0.0f, -5.0f));

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

