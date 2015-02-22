#ifndef _huge_math_transformation_impl_h_
#define _huge_math_transformation_impl_h_
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

/*
	@author Michael Sippel <micha@infinitycoding.de>
 */

#include <huge/video/device.h>

namespace huge
{

// 2d

template <typename T>
Transformation2<T>::Transformation2()
{
    this->translation_ = new Vector<2, T>();
    this->rotation_ = new T();
    this->scaling_ = new Vector<2, T>();
}

template <typename T>
Transformation2<T>::~Transformation2() {}

template <typename T>
inline Vector<2, T>& Transformation2<T>::translation(void)
{
    return *this->translation_;
}

template <typename T>
inline T& Transformation2<T>::rotation(void)
{
    return *this->rotation_;
}

template <typename T>
inline Vector<2, T>& Transformation2<T>::scaling(void)
{
    return *this->scaling_;
};

template <typename T>
inline void Transformation2<T>::translate(Vector<2, T> v)
{
    *this->translation_ += v;
}

template <typename T>
inline void Transformation2<T>::rotate(T v)
{
    *this->rotation_ += v;
}

template <typename T>
inline void Transformation2<T>::scale(Vector<2, T> v)
{
    *this->scaling_ += v;
}

template <typename T>
inline void Transformation2<T>::parent(Transformation2<T>& parent)
{
    this->parent_translation(parent);
    this->parent_rotation(parent);
    this->parent_scaling(parent);
}

template <typename T>
inline void Transformation2<T>::parent_translation(Transformation2<T>& parent)
{
    this->translation_ = parent.translation_;
}

template <typename T>
inline void Transformation2<T>::parent_rotation(Transformation2<T>& parent)
{
    this->rotation_ = parent.rotation_;
}

template <typename T>
inline void Transformation2<T>::parent_scaling(Transformation2<T>& parent)
{
    this->scaling_ = parent.scaling_;
}

template <typename T>
void Transformation2<T>::useTransformation(video::Device *device)
{
    // TODO
}

// 3d

template <typename T>
Transformation3<T>::Transformation3()
{
    this->translation_ = new Vector<3, T>((T) 0, (T) 0, (T) 0);
    this->rotation_ = new Vector<4, T>((T) 0, (T) 0, (T) 0, (T) 0);
    this->scaling_ = new Vector<3, T>((T) 1, (T) 1, (T) 1);
    this->invert = false;
}

template <typename T>
Transformation3<T>::~Transformation3() {}

template <typename T>
inline Vector<3, T>& Transformation3<T>::translation(void)
{
    return *this->translation_;
}

template <typename T>
inline Vector<4, T>& Transformation3<T>::rotation(void)
{
    return *this->rotation_;
}

template <typename T>
inline Vector<3, T>& Transformation3<T>::scaling(void)
{
    return *this->scaling_;
};

template <typename T>
inline void Transformation3<T>::translate(Vector<3, T> v)
{
    *this->translation_ += v;
}

template <typename T>
inline void Transformation3<T>::rotate(Vector<4, T> v)
{
    *this->rotation_ += v;
}

template <typename T>
inline void Transformation3<T>::scale(Vector<3, T> v)
{
    *this->scaling_ += v;
}

template <typename T>
inline void Transformation3<T>::parent(Transformation3<T>& parent)
{
    this->parent_translation(parent);
    this->parent_rotation(parent);
    this->parent_scaling(parent);
}

template <typename T>
inline void Transformation3<T>::parent_translation(Transformation3<T>& parent)
{
    this->translation_ = parent.translation_;
}

template <typename T>
inline void Transformation3<T>::parent_rotation(Transformation3<T>& parent)
{
    this->rotation_ = parent.rotation_;
}

template <typename T>
inline void Transformation3<T>::parent_scaling(Transformation3<T>& parent)
{
    this->scaling_ = parent.scaling_;
}

template <typename T>
inline void Transformation3<T>::useTransformation(video::Device *device)
{
    if(!this->invert)
    {
        device->scale(this->scaling());
        device->translate(this->translation());
        device->rotate(Vector<3, T>(this->rotation().data[0], this->rotation().data[1], this->rotation().data[2]), this->rotation().data[3]);
    }
    else
    {
        device->scale(Vector3f(1.0f, 1.0f, 1.0f)/this->scaling());
        device->rotate(Vector<3, T>(this->rotation().data[0], this->rotation().data[1], this->rotation().data[2]), -this->rotation().data[3]);
        device->translate(this->translation()*Vector3f(-1.0f, -1.0f, -1.0f));
    }
}


}; // namespace huge

#endif

