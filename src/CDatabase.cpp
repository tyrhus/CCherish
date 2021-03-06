#include <string>
#include "CDatabase.h"

template <class T>
CDatabase<T>::CDatabase(int s)
{
  size = s;
  index = 0;
}

template <class T>
CDatabase<T>::~CDatabase<T>(void)
{
}

template <class T>
bool CDatabase<T>::insert(T key, float priority)
{
  if (index > size - 1)
  {
    T res = PTree.deleteMin();
    DTree.deleteKey(res);
    index--;
  }
  PTree.insert(key, priority);
  DTree.insert(key);
  index++;
  return true;
}

template <class T>
T CDatabase<T>::deleteKey(const T key)
{
  T res;
  if (index < 1)
    return res;

  bool s = DTree.search(key);
  if (s == true) {
    PTree.deleteKey(key);
    DTree.deleteKey(key);

    index--;
  }

  return key;
}

template <class T>
void CDatabase<T>::display()
{
  cout << ">>>>>>>>>>>>>DB" << endl;
  PTree.printHeap();
  DTree.printInOrder();
  cout << "DB>>>>>>>>>>>>>" << endl;
}

template <class T>
T CDatabase<T>::search(const T key)
{
  T ret = T();
  bool s = DTree.search(key);

  if (!s)
  {
    return ret;
  }

  return key;
}
