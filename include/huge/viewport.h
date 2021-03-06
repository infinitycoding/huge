#ifndef _huge_viewport_h_
#define _huge_viewport_h_
/*
        Copyright 2012-2015 Infinitycoding all rights reserved
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

/*
	@author Michael Sippel <micha@infinitycoding.de>
 */

#include <huge/camera.h>
#include <huge/video/device.h>

namespace huge
{

class Viewport
{
    public:
        Viewport();
        Viewport(Vector2i position, Vector2i size_);
        Viewport(Camera *camera_);
        Viewport(Vector2i position, Vector2i size_, Camera *camera_);
        ~Viewport();

        Vector2i position;
        Vector2i size;
        Camera *camera;

        void useViewport(video::Device *device);
        void usePerspective(video::Device *device);
};

}; // namespace huge

#endif

