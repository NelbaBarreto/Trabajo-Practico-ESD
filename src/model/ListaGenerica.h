#include <cstring>
using namespace std;
#include "NodoGenerico.h"

#ifndef LISTA_GENERICA_H
#define LISTA_GENERICA_H

template <class T>
class ListaGenerica {
 private:
  int size = 0;

 public:
  NodoGenerico<T> *first;
  NodoGenerico<T> *last;
  ListaGenerica<T>() {
    first = NULL;
    last = NULL;
  }

  void add(T* data);
  T get(int index);
  int getSize() { return size; };
};

#endif