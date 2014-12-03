
#include "huge.h"
#include "sdl.h"

#include <GL/gl.h>

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
	this->create();
}

Window::~Window()
{
}

void Window::clear(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::swap(void)
{
	SDL_GL_SwapWindow(this->sdl_window);
}

void Window::create(void)
{
	this->sdl_window = SDL_CreateWindow(this->title, 0, 0, this->width, this->height, SDL_WINDOW_OPENGL);
    if(this->sdl_window == NULL)
    {
        printf("SDL window creation failed!\n");
        return;
    }

    this->sdl_context = (SDL_GLContext*) SDL_GL_CreateContext(this->sdl_window);
    if(this->sdl_context == NULL)
    {
        printf("OpenGL context creation failed!\n");
        return;
    }
}

};
};

