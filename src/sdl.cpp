
#include "huge.h"
#include "sdl.h"

namespace huge
{
namespace sdl
{

int init(void)
{
    return SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
}

Window::Window()
    : title(NULL), width(800), height(600)
{
}

Window::~Window()
{
}


GLContext::GLContext()
{
}

GLContext::GLContext(Window *window_)
    : window(window_)
{
    this->sdl_context = (SDL_GLContext*) SDL_GL_CreateContext(this->window->sdl_window);
    if(this->sdl_context == NULL)
    {
        printf("OpenGL context creation failed!\n");
    }
}

GLContext::~GLContext()
{
}

void GLContext::activate_(void)
{
    SDL_GL_MakeCurrent(this->window->sdl_window, this->sdl_context);
}


GLWindow::GLWindow()
{
    this->create();
}

GLWindow::~GLWindow()
{
}

void GLWindow::swap(void)
{
    SDL_GL_SwapWindow(this->sdl_window);
}

void GLWindow::create(void)
{
    this->sdl_window = SDL_CreateWindow(this->title, 0, 0, this->width, this->height, SDL_WINDOW_OPENGL);
    if(this->sdl_window == NULL)
    {
        printf("SDL window creation failed!\n");
    }
}

};
};

