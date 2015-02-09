#ifndef _huge_video_device_object_h_
#define _huge_video_device_object_h_
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
#include <stdio.h>

namespace huge
{

namespace video
{

class DeviceObject
{
    public:
        DeviceObject();
        ~DeviceObject();

        unsigned int id;

    private:
        static unsigned int object_counter;
};

struct device_object_entry
{
    DeviceObject *abstract;
    void *specific;
};


}; // namespace video

}; // namespace huge

#endif

