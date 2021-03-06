/*
        Copyright 2012-2014 Infinitycoding all rights reserved
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

/*
	@author Michael Sippel <micha@infinitycoding.de>
 */

#include <huge/math/vector.h>
#include <huge/sdl.h>

namespace huge
{

namespace sdl
{

int init(void)
{
    return SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
}

Window::Window()
    : title(NULL), size(Vector2i(800, 600))
{
}

Window::Window(char *title_)
    : title(title_), size(Vector2i(800, 600))
{
}

Window::Window(Vector2i size_)
    : title(NULL), size(size_)
{
}

Window::Window(char *title_, Vector2i size_)
    : title(title_), size(size_)
{
}

Window::~Window()
{
}

GLContext::GLContext()
{
    GLContext(new GLWindow());
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
    SDL_GL_DeleteContext(this->sdl_context);
}

void GLContext::activate_(void)
{
    SDL_GL_MakeCurrent(this->window->sdl_window, this->sdl_context);
}


GLWindow::GLWindow()
{
    this->create();
}

GLWindow::GLWindow(char *title_)
{
    this->title = title_;
    this->create();
}

GLWindow::GLWindow(Vector2i size_)
{
    this->size = size_;
    this->create();
}


GLWindow::GLWindow(char *title_, Vector2i size_)
{
    this->title = title_;
    this->size = size_;
    this->create();
}

GLWindow::~GLWindow()
{
    SDL_DestroyWindow(this->sdl_window);
}

void GLWindow::swap(void)
{
    SDL_GL_SwapWindow(this->sdl_window);
}

void GLWindow::create(void)
{
    this->sdl_window = SDL_CreateWindow(this->title, 0, 0, this->size.x(), this->size.y(), SDL_WINDOW_OPENGL);
    if(this->sdl_window == NULL)
    {
        printf("SDL window creation failed!\n");
    }
}

}; // namespace sdl

}; // namespace huge

