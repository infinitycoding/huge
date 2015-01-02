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
#include "camera.h"
#include "viewport.h"
#include "video/device.h"

namespace huge
{

Viewport::Viewport()
{
    this->size = Vector2i(800, 600);
    this->camera = new Camera();
}

Viewport::Viewport(Vector2i size_)
    : size(size_)
{
    this->camera = new Camera();
}

Viewport::Viewport(Camera *camera_)
    : camera(camera_)
{
    this->size = Vector2i(800, 600);
}

Viewport::Viewport(Vector2i size_, Camera *camera_)
    : size(size_), camera(camera_)
{
}

Viewport::~Viewport()
{
}

void Viewport::useViewport(void)
{
    // TODO
}

void Viewport::usePerspective(void)
{
    double aspect = (double)this->size.x() / (double)this->size.y();

    // TODO
    //current_video_device->setMatrixMode(MODELVIEW);
    //current_video_device->loadIdentity();
    //current_video_device->setPerspective(this->camera->fov, aspect, this->camera->near_clip, this->camera->far_clip);
}

};

