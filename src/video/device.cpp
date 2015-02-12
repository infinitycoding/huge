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

/*
	@author Michael Sippel <micha@infinitycoding.de>
 */

#include <huge/video/device.h>
#include <huge/viewport.h>
#include <huge/material/material.h>

namespace huge
{

namespace video
{

Device::Device()
{
    this->device_objects = new List<struct abstraction_entry>();
    if(this->type_objects() != NULL)
    {
        this->type_objects() = new List<struct abstraction_entry>();
    }
}

Device::Device(video::Context *context_)
    : context(context_)
{
    this->device_objects = new List<struct abstraction_entry>();
    if(this->type_objects() != NULL)
    {
        this->type_objects() = new List<struct abstraction_entry>();
    }
}

Device::~Device()
{
}

inline List<struct abstraction_entry>*& Device::type_objects(void)
{
    List<struct abstraction_entry>* null = NULL;
    return null;
}

void* Device::getDeviceObject(void *obj)
{
    ListIterator<struct abstraction_entry> it = ListIterator<struct abstraction_entry>(this->device_objects);
    it.setFirst();

    while(!it.isLast())
    {
        struct abstraction_entry entry = it.getCurrent();
        if(entry.abstract == obj)
        {
            return entry.specific;
        }

        it.next();
    }

    return NULL;
}

void* Device::getTypeObject(void *obj)
{
    if(this->type_objects() != NULL)
    {
        ListIterator<struct abstraction_entry> it = ListIterator<struct abstraction_entry>(this->type_objects());
        it.setFirst();

        while(!it.isLast())
        {
            struct abstraction_entry entry = it.getCurrent();
            if(entry.abstract == obj)
            {
                return entry.specific;
            }

            it.next();
        }
    }

    return NULL;
}

void Device::addDeviceObject(void *abstract, void *specific)
{
    struct abstraction_entry entry;
    entry.abstract = abstract;
    entry.specific = specific;

    this->device_objects->pushBack(entry);
};

void Device::addTypeObject(void *abstract, void *specific)
{
    if(this->type_objects() != NULL)
    {
        struct abstraction_entry entry;
        entry.abstract = abstract;
        entry.specific = specific;

        this->type_objects()->pushBack(entry);
    }
};


inline void Device::not_supported(const char *str)
{
    printf("GraphicsDevice: \"%s\" is not supported.\n", str);
}

void Device::useViewport(Viewport *viewport)
{
    viewport->useViewport(this);
    viewport->usePerspective(this);
}

}; // namespace video

}; // namespace huge

