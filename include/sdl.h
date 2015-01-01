#ifndef _sdl_h_
#define _sdl_h_
/*
        Copyright 2012-2014 Infinitycoding all rights reserved
        This file is part of the HugeUniversalGameEngine.

        HUGE is free software: you can redistribute it and/or modify
        it under the terms of the GNU General Public License as published by
        the Free Software Foundation, either version 3 of the License, or
        any later version.

        The Universe Kernel is distributed in the hope that it will be useful,
        but WITHOUT ANY WARRANTY; without even the implied warranty of
        MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
        GNU General Public License for more details.

        You should have received a copy of the GNU General Public License
        along with the Universe Kernel. If not, see <http://www.gnu.org/licenses/>.
*/

#include <SDL2/SDL.h>
#include "video/device.h"

namespace huge
{
namespace sdl
{

int init(void);

class Window
{
    public:
        Window();
        ~Window();

        VideoDevice *video_device;

        virtual void swap(void) = 0;

    protected:
        char *title;
        int width;
        int height;

        SDL_Window *sdl_window;
};

class GLWindow : public Window
{
    public:
        GLWindow();
        ~GLWindow();

        void swap(void);

    protected:
        void create(void);
        SDL_GLContext *sdl_context;
};

};
};

#endif

