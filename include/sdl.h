#ifndef _sdl_h_
#define _sdl_h_
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

#include <SDL2/SDL.h>
#include "math/vector.h"
#include "video/context.h"
#include "video/device.h"

namespace huge
{
namespace sdl
{

int init(void);

class Window
{
        friend class GLContext;

    public:
        Window();
        Window(char *title_);
        Window(Vector2i size_);
        Window(char *title_, Vector2i size_);
        ~Window();

        virtual void swap(void) = 0;

    protected:
        char *title;
        Vector2i size;

        SDL_Window *sdl_window;
};

class GLContext : public video::Context
{
    public:
        GLContext();
        GLContext(Window *window_);
        ~GLContext();

        Window *window;

    private:
        inline void activate_(void);
        SDL_GLContext *sdl_context;
};

class GLWindow : public Window
{
    public:
        GLWindow();
        GLWindow(char *title_);
        GLWindow(Vector2i size_);
        GLWindow(char *title_, Vector2i size_);

        ~GLWindow();

        void swap(void);

    private:
        void create(void);
};

};
};

#endif

