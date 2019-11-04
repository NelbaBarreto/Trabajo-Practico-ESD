#include <cstring>
using namespace std;

#ifndef NODO_GENERICO_H
#define NODO_GENERICO_H
template <class T>
class NodoGenerico {
 public:
  T data;
  NodoGenerico<T> *next;
};
#endif
