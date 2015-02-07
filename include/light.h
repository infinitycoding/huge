#ifndef _huge_light_h_
#define _huge_light_h_
/*
        Copyright 2012-2015 Infinitycoding all rights reserved
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

/**
 * @author Michael Sippel <micha@infinitycoding.de>
 */
#include "math/transformation.h"
#include "video/device.h"
#include "color.h"

namespace huge
{

enum light_type
{
    POINT,
    PARALLEL,
    SPOT
};

class Light : public Transformation3f, public video::DeviceObject
{
    public:
        Light();
        Light(Color4f color);
        ~Light();

        Color4f color;
        enum light_type type;

        void enable(video::Device *device);
        void disable(video::Device *device);
        void update(video::Device *device);
};

};

#endif

