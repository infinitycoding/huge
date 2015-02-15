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

#include <stddef.h>
#include <stdio.h>

#include <huge/video/context.h>

namespace huge
{

namespace video
{

thread_local Context *Context::current = (Context*) NULL;

Context::Context()
{
}

Context::~Context()
{
}

void Context::activate(void)
{
    if(this != video::Context::current)
    {
        this->activate_();
        video::Context::current = this;
    }
}

inline void Context::activate_(void)
{
    printf("No specific context created.\n");
}

}; // namespace video

}; // namespace huge

