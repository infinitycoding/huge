#ifndef _huge_material_h_
#define _huge_material_h_
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

#include <huge/color.h>
#include <huge/video/device.h>

namespace huge
{

class Material
{
    public:
        Material();
        Material(Color4f color_);
        Material(Color4f color_, float roughness_);
        Material(Color4f color_, Color4f emission_);
        Material(Color4f color_, Color4f emission_, float roughness_);
        ~Material();

        Color4f color;
        Color4f emission;
        float roughness;

        void use(video::Device *device);
        void useOld(video::Device *device);
};

}; // namespace huge

#endif

