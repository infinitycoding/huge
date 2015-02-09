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

Camera::Camera()
    : fov(90.0f), near_clip(1.0f), far_clip(1000.0f)
{
}

Camera::Camera(double fov_)
    : fov(fov_), near_clip(1.0f), far_clip(1000.0f)
{
}

Camera::Camera(double near_clip_, double far_clip_)
    : fov(90.0f), near_clip(near_clip_), far_clip(far_clip_)
{
}

Camera::Camera(double fov_, double near_clip_, double far_clip_)
    : fov(fov_), near_clip(near_clip_), far_clip(far_clip_)
{
}

Camera::~Camera()
{
}

}; // namespace huge

