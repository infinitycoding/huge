#ifndef _transformation_h_
#define _transformation_h_
/*
        Copyright 2012-2014 Infinitycoding all rights reserved
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
#include "vector.h"

namespace huge
{

template <typename T>
class Transformation2
{
    public:
        Transformation2()
        {
            this->position_ = new Vector<2, T>();
            this->rotation_ = new T();
            this->scaling_ = new Vector<2, T>();
        }
        ~Transformation2() {}

        inline Vector<2, T>& position(void)
        {
            return *this->position_;
        }
        inline T& rotation(void)
        {
            return *this->rotation_;
        }
        inline Vector<2, T>& scaling(void)
        {
            return *this->scaling_;
        };

        inline void move(Vector<2, T> v)
        {
            this->position_ += v;
        }
        inline void rotate(T v)
        {
            this->rotation_ += v;
        }
        inline void scale(Vector<2, T> v)
        {
            this->scaling_ += v;
        }

        void use(void);

        inline void parent(Transformation2<T>& parent)
        {
            this->parent_position(parent);
            this->parent_rotation(parent);
            this->parent_scaling(parent);
        }

        inline void parent_position(Transformation2<T>& parent)
        {
            this->position_ = parent.position_;
        }
        inline void parent_rotation(Transformation2<T>& parent)
        {
            this->rotation_ = parent.rotation_;
        }
        inline void parent_scaling(Transformation2<T>& parent)
        {
            this->scaling_ = parent.scaling_;
        }

    private:
        Vector<2, T> *position_;
        T *rotation_;
        Vector<2, T> *scaling_;
};

template <typename T>
class Transformation3
{
    public:
        Transformation3() {}
        ~Transformation3() {}

        // TODO: Quaternions
};

typedef Transformation2<int> Transformation2i;
typedef Transformation3<int> Transformation3i;

typedef Transformation2<float> Transformation2f;
typedef Transformation3<float> Transformation3f;

typedef Transformation2<double> Transformation2d;
typedef Transformation3<double> Transformation3d;

};

#endif

