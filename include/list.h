#ifndef _huge_list_h_
#define _huge_list_h_
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

struct Node
{
    struct Node *next;
    struct Node *prev;
    void *element;
};

template <typename T>

class List
{
    public:
        List();
        List(List<T> *l);
        List(List<T> *l,void(*copyTree)(T *destElement, T *srcElement));
        ~List();

        void PushFront(T *element);
        void PushBack(T *element);
        T *PopBack();
        T *PopFront();


        bool IsEmpty();
        void *GetNode(T *element);

        size_t Size();
        int NumOfElements();

        bool Remove(T *element);
        T *Remove(Node *n);
        void Destroy(Node *n);

        void (*structCleaner)(T *element);
        bool lock;

        bool alreadyAdded(T *element);

        Node *dummy;
};

template <typename T>

class ListIterator
{
    public:
        ListIterator(List<T> *L);

        void PushFront(T *element);
        void PushBack(T *element);

        void InsertAfter(T *element);
        void InsertBefore(T *element);

        T *PopBack();
        T *PopFront();

        T *Remove();
        void Destroy();
        T *GetCurrent();
        bool IsEmpty();
        T *GetAndNext();

        ListIterator<T> *Next();
        ListIterator<T> *Previous();
        ListIterator<T> *SetLast();
        ListIterator<T> *SetFirst();

        bool IsLast();
        void set(void *n);

        Node *currentNode;
        List<T> *Instance;
};

#define foreach(LIST,NAME,TYPE) \
	ListIterator<TYPE> Iterator = ListIterator<TYPE>(LIST); \
	TYPE *NAME; \
	for(NAME = Iterator.GetCurrent(); !Iterator.IsLast(); NAME = Iterator.GetAndNext())

#include "list_impl.h"

#endif

