#ifndef _video_device_context_h_
#define _video_device_context_h_
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

namespace huge
{

namespace video
{

class Context
{
    public:
        Context();
        ~Context();

        void activate(void);

    protected:
        virtual inline void activate_(void);

    private:
        static thread_local Context *current;
};

};
};

#endif

