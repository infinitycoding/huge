#ifndef _huge_list_impl_h_
#define _huge_list_impl_h_
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

template <typename T>
List<T>::List()
{
    lock = true;
        dummy = new Node;
        dummy->element = NULL;
        dummy->prev = dummy;
        dummy->next = dummy;
        structCleaner = NULL;
    lock = false;
}

template <typename T>
List<T>::List(List<T> *l)
{
    lock = true;
        structCleaner = l->structCleaner;
        ListIterator<T> *lit = new ListIterator<T>(l);
        dummy = new Node;
        dummy->element = NULL;
        dummy->next = dummy;
        dummy->prev = dummy;
        while(!lit->IsLast())
        {
            T *currentEntry = new T;
            *currentEntry = *lit->GetCurrent();
            PushFront(currentEntry);
            lit->Next();
        }
    lock = false;
}

template <typename T>
List<T>::List(List<T> *l, void(*copyTree)(T *destElement, T *srcElement))
{
    lock = true;
        structCleaner = l->structCleaner;
        ListIterator<T> *srcIt = ListIterator<T>(l);
        dummy = new Node;
        dummy->element = NULL;
        dummy->next = dummy;
        dummy->prev = dummy;
        while(!srcIt->IsLast())
        {
            T *currentEntry = new T;
            *currentEntry = *srcIt->GetCurrent();
            copyTree(currentEntry,srcIt->GetCurrent());
            PushFront(currentEntry);
            srcIt->Next();
        }
    lock = false;
}

template <typename T>
List<T>::~List<T>()
{
    lock = true;
        while(!IsEmpty())
        {
            T *element = PopFront();
            if(structCleaner)
                structCleaner(element);
            delete element;
        }
    lock = false;
}

template <typename T>
void List<T>::PushFront(T *element)
{
    Node *newNode = new Node;
    newNode->element = (void*)element;

    while(lock){}
    lock = true;
        newNode->next = dummy->next;
        newNode->prev = dummy;
        dummy->next->prev = newNode;
        dummy->next = newNode;
    lock = false;
}

template <typename T>
void List<T>::PushBack(T *element)
{
    Node *newNode = new Node;
    newNode->element = element;

    while(lock){}
    lock = true;
        newNode->prev = dummy;
        newNode->next = dummy->next;
        dummy->next->prev = newNode;
        dummy->next = newNode;
    lock = false;
}

template <typename T>
T* List<T>::PopBack()
{
    T* element = dummy->prev->element;
    Remove(dummy->prev);
    return element;
}

template <typename T>
T* List<T>::PopFront()
{
    T* element = (T*)dummy->next->element;
    Remove(dummy->next);
    return element;
}

template <typename T>
bool List<T>::IsEmpty()
{
    if(dummy->next == dummy && dummy->prev == dummy)
        return true;
    return false;
}

template <typename T>
void *List<T>::GetNode(T *element)
{
    lock = true;
        Node *n = dummy->next;
        if(n->element == element)
        {
            lock = false;
            return (void *)n;
        }
        while(n!=dummy)
        {
            if(n->element == element)
            {
                lock = false;
                return (void *)n;
            }

            n = n->next;
        }
    lock = false;
    return NULL;
}

template <typename T>
size_t List<T>::Size()
{
    size_t s = 0;
    lock = true;
        ListIterator<T> i = new ListIterator<T>(this);
        while(!i->IsLast())
        {
            s++;
            i->Next();
        }
    lock = false;
    return s*sizeof(T);
}

template <typename T>
int List<T>::NumOfElements()
{
    int s = 0;
    lock = true;
        ListIterator<T> i = new ListIterator<T>(this);
        while(!i->IsLast())
        {
            s++;
            i->Next();
        }
    lock = false;
    return s;
}

template <typename T>
T *List<T>::Remove(Node *n)
{
    lock = true;
        if(n == dummy)
        {
            lock = false;
            return 0;
        }
        n->prev->next = n->next;
        n->next->prev = n->prev;
        T* element = (T*)n->element;
        delete n;
    lock = false;
    return element;
}

template <typename T>
bool List<T>::Remove(T *element)
{
    ListIterator<T> i = *ListIterator<T>(this).SetFirst();
    while(!i.IsLast())
    {
        if(i.GetCurrent() == element)
        {
            i.Remove();
            return true;
        }
        i.Next();
    }
    return false;
}

template <typename T>
void List<T>::Destroy(Node *n)
{
    lock = true;
        if(n == dummy)
        {
            lock = false;
            return;
        }
        if(structCleaner)
            structCleaner((T*)n->element);
        n->prev->next = n->next;
        n->next->prev = n->prev;
        delete (T*)n->element;
        delete n;
    lock = false;
}

template <typename T>
bool List<T>::alreadyAdded(T *element)
{
    ListIterator<T> i = *ListIterator<T>(this).SetFirst();
    while(!i.IsLast())
    {
        if(i.GetCurrent() == element)
            return true;

        i.Next();
    }
    return false;
}


template <typename T>
ListIterator<T>::ListIterator(List<T> *L)
{
    Instance = L;
    currentNode = L->dummy;
}

template <typename T>
void ListIterator<T>::PushFront(T *element)
{
    Node *newNode = new Node;
    newNode->element = element;

    while(Instance->lock){}
    Instance->lock = true;
        newNode->next = Instance->dummy->next;
        newNode->prev = Instance->dummy;
        Instance->dummy->next->prev = newNode;
        Instance->dummy->next = newNode;
    Instance->lock = false;
}

template <typename T>
void ListIterator<T>::PushBack(T *element)
{
    Node *newNode = new Node;
    newNode->element = element;

    while(Instance->lock){}
    Instance->lock = true;
        newNode->prev = Instance->dummy;
        newNode->next = Instance->dummy->next;
        Instance->dummy->next->prev = newNode;
        Instance->dummy->next = newNode;
    Instance->lock = false;
}

template <typename T>
void ListIterator<T>::InsertAfter(T *element)
{
    Node *newNode = new Node;
    newNode->element = element;

    while(Instance->lock){}
    Instance->lock = true;
        newNode->next = currentNode->next;
        newNode->prev = currentNode;
        currentNode->next->prev = newNode;
        currentNode->next = newNode;
    Instance->lock = false;
}

template <typename T>
void ListIterator<T>::InsertBefore(T *element)
{
    Node *newNode = new Node;
    newNode->element = element;

    while(Instance->lock){}
    Instance->lock = true;
        newNode->prev = currentNode;
        newNode->next = currentNode->next;
        currentNode->next->prev = newNode;
        currentNode->next = newNode;
    Instance->lock = false;
}

template <typename T>
T* ListIterator<T>::PopBack()
{
    T* element = Instance->dummy->prev->element;
    Instance->Remove(Instance->dummy->prev);
    return element;
}

template <typename T>
T* ListIterator<T>::PopFront()
{
    T* element = Instance->dummy->next->element;
    Instance->Remove(Instance->dummy->next);
    return element;
}


template <typename T>
T *ListIterator<T>::Remove()
{
    T *element = (T*)currentNode->element;
    currentNode = currentNode->next;
    Instance->Remove(currentNode->prev);
    return element;
}

template <typename T>
void ListIterator<T>::Destroy()
{
    currentNode = currentNode->next;
    Instance->Destroy(currentNode->prev);
}

template <typename T>
T* ListIterator<T>::GetCurrent()
{
    return (T*)currentNode->element;
}

template <typename T>
T* ListIterator<T>::GetAndNext()
{
    T *element = (T*)currentNode->element;
    Next();
    return element;
}


template <typename T>
ListIterator<T> *ListIterator<T>::Next()
{
    currentNode = currentNode->next;
    return this;
}

template <typename T>
ListIterator<T> *ListIterator<T>::Previous()
{
    currentNode = currentNode->prev;
    return this;
}

template <typename T>
ListIterator<T> *ListIterator<T>::SetLast()
{
    currentNode = Instance->dummy->prev;
    return this;
}

template <typename T>
ListIterator<T> *ListIterator<T>::SetFirst()
{
    currentNode = Instance->dummy->next;
    return this;
}


template <typename T>
bool ListIterator<T>::IsLast()
{
    if(currentNode == Instance->dummy)
        return true;
    return false;
}

template <typename T>
void ListIterator<T>::set(void *n)
{
    currentNode = (Node *)n;
    return this;
}

template <typename T>
bool ListIterator<T>::IsEmpty()
{
    return Instance->IsEmpty();
}

#endif