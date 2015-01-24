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

#include "video/device.h"

namespace huge
{

VideoContext *VideoContext::current = (VideoContext*) NULL;

VideoContext::VideoContext()
{
}

VideoContext::~VideoContext()
{
}

void VideoContext::activate(void)
{
    if(this != VideoContext::current)
    {
        this->activate_();
        VideoContext::current = this;
    }
}

void VideoContext::activate_(void)
{
    printf("No specific context created.\n");
}

VideoDevice::VideoDevice()
{
}

VideoDevice::VideoDevice(VideoContext *context_)
    : context(context_)
{
}

VideoDevice::~VideoDevice()
{
}

inline void VideoDevice::not_supported(const char *str)
{
    printf("GraphicsDevice: \"%s\" is not supported.\n", str);
}

};

