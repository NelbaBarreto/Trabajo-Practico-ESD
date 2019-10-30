#include <string>
#include "Nodo.h"
#include <fstream>
using namespace std;

#ifndef LISTA_H
#define LISTA_H

class Lista {
 private:
  void Siguiente();
  void Anterior();
  void Primero();
  void Ultimo();
  void Insertar();
  void Borrar();
  void Modificar();
  void Consultar();
  void ImprimirOpciones();
  void AlmacenarDatos();

 public:
  Lista();
  ~Lista();
  Nodo* primero;
  Nodo* ultimo;
  Nodo* sig;
  Nodo* ant;
  Nodo* ObtenerNodo(Persona*);
  Persona *cargaPersona(string);
  void Crear(string const);
  void Agregar(Nodo*);
  void Navegacion();
  void Mostrar();
};

#endif 
