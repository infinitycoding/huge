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

    dev1->context->activate();
    if(glewInit() != GLEW_OK)
    {
        printf("GLEW init failed!\n");
    }

    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    Light *light = new Light();

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
        dev1->translate(Vector3f(10.0f, 5.0f, 0.0f));
        light->update(dev1);
        dev1->popMatrix();

        // set vertex color
        dev1->color(Color4ub(0xff, 0xff, 0xff, 0xff));
        dev2->color(Color4ub(0x44, 0x55, 0x11, 0xff));

        // render mesh
        dev1->pushMatrix();
        mesh->renderImmediate(dev1);
        dev1->translate(Vector3f(3.0f, 0.0f, 0.0f));
        mesh->renderImmediate(dev1);
        dev1->translate(Vector3f(-6.0f, 0.0f, 0.0f));
        mesh->renderImmediate(dev1);
        dev1->popMatrix();

        dev1->pushMatrix();
        dev1->translate(Vector3f(0.0f, 0.0f, -3.0f));
        mesh->renderImmediate(dev1);
        dev1->translate(Vector3f(3.0f, 0.0f, 0.0f));
        mesh->renderImmediate(dev1);
        dev1->translate(Vector3f(-6.0f, 0.0f, 0.0f));
        mesh->renderImmediate(dev1);
        dev1->popMatrix();

        mesh->renderImmediate(dev2);

        // swap windows
        dev1->context->activate();
        window1->swap();

        dev2->context->activate();
        window2->swap();
    }

    return 0;
}


