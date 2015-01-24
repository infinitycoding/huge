#include <stdio.h>
#include "huge.h"
#include "video/opengl.h"

#include <GL/glew.h>

using namespace huge;

int main(int argc, char **argv)
{
    printf("Hello World!\n");
    test();

    // windows
    sdl::init();
    sdl::Window *window1 = new sdl::GLWindow("Window 1", Vector2i(800, 600));
    sdl::Window *window2 = new sdl::GLWindow("Window 2", Vector2i(400, 300));

    video::Context *context1 = new sdl::GLContext(window1);
    video::Context *context2 = new sdl::GLContext(window2);

    video::Device *dev1 = new video::OpenGLDevice(context1);
    video::Device *dev2 = new video::OpenGLDevice(context2);

    if(glewInit() != GLEW_OK)
    {
        printf("GLEW init failed!\n");
    }

    dev1->context->activate();

    GLfloat light_diffuse[] = { 0.5, 0.5, 0.5, 1.0 };
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_position[] = { 0.0, 10.0, -5.0, 0.0 };
    glClearColor (0.0, 0.0, 0.0, 1.0);
    glShadeModel (GL_FLAT);

    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);

    // mesh
    List<Mesh*> *meshes = loader::load_obj("test.obj");
    Mesh *mesh = meshes->popBack();

    // perspective
    Camera *cam1 = new Camera();
    Camera *cam2 = new Camera();
    Viewport *view1 = new Viewport(Vector2i(0, 0), Vector2i(800, 600), cam1);
    Viewport *view2 = new Viewport(Vector2i(0, 0), Vector2i(400, 300), cam2);
    cam1->translate(Vector3f(0.0f, -2.0f, -7.0f));
    cam2->translate(Vector3f(0.0f,  2.0f, -5.0f));
    cam2->rotation() = Vector4f(0.0f, 1.0f, 0.0f, 20.0f);

    // use cameras transformation
    dev1->useViewport(view1);
    dev1->useTransformation(*cam1);

    dev2->useViewport(view2);
    dev2->useTransformation(*cam2);


    while(1)
    {
        // poll events
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

        // clear buffers
        dev1->clear(video::COLOR_BUFFER_BIT | video::DEPTH_BUFFER_BIT);
        dev2->clear(video::COLOR_BUFFER_BIT | video::DEPTH_BUFFER_BIT);

        dev1->pushMatrix();

        // set vertex color
        dev2->color(Color4ub(0x44, 0x55, 0x11, 0xff));

        // render mesh
        mesh->renderImmediate(dev1);
        dev1->translate(Vector3f(3.0f, 0.0f, 0.0f));
        mesh->renderImmediate(dev1);
        dev1->translate(Vector3f(-6.0f, 0.0f, 0.0f));
        mesh->renderImmediate(dev1);

        mesh->renderImmediate(dev2);

        dev1->popMatrix();

        // swap windows
        dev1->context->activate();
        window1->swap();

        dev2->context->activate();
        window2->swap();
    }

    return 0;
}


