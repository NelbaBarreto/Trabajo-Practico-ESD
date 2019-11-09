#include "ListaGenerica.h"

template <class T>
void ListaGenerica<T>::add(T* data) {
  if (first == NULL) {
    first = new NodoGenerico<T>;
    first->data = data;
    first->next = NULL;
    last = first;
  } else {
    if (last == first) {
      last = new NodoGenerico<T>;
      last->data = data;
      last->next = NULL;
      first->next = last;
    } else {
      NodoGenerico<T> *insdata = new NodoGenerico<T>;
      insdata->data = data;
      insdata->next = NULL;
      last->next = insdata;
      last = insdata;
    }
  }
  size++;
}

template <class T>
T* ListaGenerica<T>::get(int index) {
  if (index == 0) {
    return this->first->data;
  } else {
    NodoGenerico<T> *curr = this->first;
    for (int i = 0; i < index; ++i) {
      curr = curr->next;
    }
    return curr->data;
  }
}
