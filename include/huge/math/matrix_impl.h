#ifndef _huge_math_matrix_impl_h_
#define _huge_math_matrix_impl_h_
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

namespace huge
{

template <int M, int N, typename T>
inline Vector<M, Vector<N, T> >& Vector<M, Vector<N, T> >::operator=(T v)
{
    int i;
    for(i = 0; i < M; i++)
        this->data[i] = v;

    return *this;
}

template <int M, int N, typename T>
inline Vector<M, Vector<N, T> >& Vector<M, Vector<N, T> >::operator+=(T v)
{
    int i;
    for(i = 0; i < M; i++)
        this->data[i] += v;

    return *this;
}

template <int M, int N, typename T>
inline Vector<M, Vector<N, T> >& Vector<M, Vector<N, T> >::operator-=(T v)
{
    int i;
    for(i = 0; i < M; i++)
        this->data[i] -= v;

    return *this;
}

template <int M, int N, typename T>
inline Vector<M, Vector<N, T> >& Vector<M, Vector<N, T> >::operator*=(T v)
{
    int i;
    for(i = 0; i < M; i++)
        this->data[i] *= v;

    return *this;
}

template <int M, int N, typename T>
inline Vector<M, Vector<N, T> >& Vector<M, Vector<N, T> >::operator/=(T v)
{
    int i;
    for(i = 0; i < M; i++)
        this->data[i] /= v;

    return *this;
}


}; // namespace huge

#endif

