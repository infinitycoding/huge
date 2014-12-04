#ifndef _vector_h_
#define _vector_h_
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

template <int N, typename T>
class Vector
{
	public:
		Vector()
		{
		}

		~Vector()
		{
		}

		inline void add(T v)
		{
			int i;
			for(i = 0; i < N; i++)
				this->data[i] += v;
		}

		inline void add(Vector<N, T> v)
		{
			int i;
			for(i = 0; i < N; i++)
				this->data[i] += v->data[i];
		}

		void sub(T v);
		void sub(Vector<N, T> v);
		void mul(T v);
		void mul(Vector<N, T> v);
		void div(T v);
		void div(Vector<N, T> v);

		T data[N];
};

};

#endif

