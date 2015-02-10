#ifndef _huge_math_transformation_h_
#define _huge_math_transformation_h_
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

#include <huge/math/vector.h>
#include <huge/video/device.h>

namespace huge
{

template <typename T>
class Transformation2
{
    public:
        Transformation2();
        ~Transformation2();

        inline Vector<2, T>& translation(void);
        inline T& rotation(void);
        inline Vector<2, T>& scaling(void);

        inline void translate(Vector<2, T> v);
        inline void rotate(T v);
        inline void scale(Vector<2, T> v);

        inline void parent(Transformation2<T>& parent);
        inline void parent_translation(Transformation2<T>& parent);
        inline void parent_rotation(Transformation2<T>& parent);
        inline void parent_scaling(Transformation2<T>& parent);

        void useTransformation(video::Device *device);

    private:
        Vector<2, T> *translation_;
        T *rotation_;
        Vector<2, T> *scaling_;
};

template <typename T>
class Transformation3
{
    public:
        Transformation3();
        ~Transformation3();

        inline Vector<3, T>& translation(void);
        inline Vector<4, T>& rotation(void);
        inline Vector<3, T>& scaling(void);
        inline void translate(Vector<3, T> v);
        inline void rotate(Vector<4, T> v);
        inline void scale(Vector<3, T> v);

        inline void parent(Transformation3<T>& parent);
        inline void parent_translation(Transformation3<T>& parent);
        inline void parent_rotation(Transformation3<T>& parent);
        inline void parent_scaling(Transformation3<T>& parent);

        void useTransformation(video::Device *device);

    protected:
        bool invert;

    private:
        Vector<3, T> *translation_;
        Vector<4, T> *rotation_;
        Vector<3, T> *scaling_;
};

typedef Transformation2<int> Transformation2i;
typedef Transformation3<int> Transformation3i;

typedef Transformation2<float> Transformation2f;
typedef Transformation3<float> Transformation3f;

typedef Transformation2<double> Transformation2d;
typedef Transformation3<double> Transformation3d;

}; // namespace huge

#include "transformation_impl.h"

#endif

