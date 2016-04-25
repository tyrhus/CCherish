#include "CPriorityHeap.h"

#include <vector>

template <class T>
CPriorityHeap<T>::CPriorityHeap(int s)
{
  size = s;
  index = 0;
}

template <class T>
CPriorityHeap<T>::~CPriorityHeap<T>(void)
{
  heap.erase(heap.begin(), heap.end());
  size = index = 0;
}


template <class T>
bool CPriorityHeap<T>::insert(T key, float priority)
{
  CPriority<string> temp(key, priority);
  heap.push_back( temp );
  index++;

  if (index <= size)
    return true;

  return false;
}

template <class T>
T CPriorityHeap<T>::findMin()
{
  return heap[0];
}

template <class T>
void CPriorityHeap<T>::printHeap() {

    for(typename vector< CPriority<T> >::iterator it = heap.begin(); it != heap.end(); ++it)
      cout << it->priority << "-" << it->key << " ,";

    cout << endl;
}

template <class T>
void CPriorityHeap<T>::deleteKey(const T key)
{
  for(typename vector<T>::iterator it = heap.begin(); it != heap.end(); ++it) {
    if (key.key == it.key)
      if (key.priority == it.priority)
        {
          heap.erase(it);
          index--;
        }

  }
}
