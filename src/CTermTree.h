#ifndef __CTermTree_h__
#define __CTermTree_h__

#include "CTerm.h"
template <class T>
class CTermTree {
public:
    CTermTree       (void);
    ~CTermTree      (void);

    bool insert     (T key);
    void deleteKey  (const T key);
    bool search     (const T delKey);
    void printBalance();
    void printInOrder();
    void renderInOrder();
    T findMin();

private:
    CTerm<T> *root;

    CTerm<T>* rotateLeft          ( CTerm<T> *a );
    CTerm<T>* rotateRight         ( CTerm<T> *a );
    CTerm<T>* rotateLeftThenRight ( CTerm<T> *n );
    CTerm<T>* rotateRightThenLeft ( CTerm<T> *n );
    CTerm<T>* findMin             ( CTerm<T> *n );
    void rebalance                  ( CTerm<T> *n );
    int height                      ( CTerm<T> *n );
    void setBalance                 ( CTerm<T> *n );
    void printBalance               ( CTerm<T> *n );
    void printInOrder               ( CTerm<T> *n );
    void renderInOrder              (CTerm<T> *n, int level);
    void clearNode                  ( CTerm<T> *n );
};
#endif
