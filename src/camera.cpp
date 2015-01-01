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
#include "video/device.h"

extern huge::VideoDevice *current_video_device;

namespace huge
{

Camera::Camera()
    : fov(90.0f), aspect(8.0f/6.0f), near_clip(1.0f), far_clip(1000.0f)
{
}

Camera::~Camera()
{
}

void Camera::usePerspective(void)
{
    current_video_device->setMatrixMode(MODELVIEW);
    current_video_device->loadIdentity();
    current_video_device->setPerspective(this->fov, this->aspect, this->near_clip, this->far_clip);
}

};

