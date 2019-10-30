#include "../model/Persona.cpp"

#ifndef NODO_H
#define NODO_H

class Nodo {
 public:
  Nodo() {};
  ~Nodo(){};
  Persona dato;
  Nodo *sig;
  Nodo *ant;
  Nodo *primero;
  Nodo *ultimo;
};

#endif 