#include <cstring>
#include <fstream>
#include "Nodo.h"
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
  void Ordenar();
  void ImprimirOpciones();
  void AlmacenarDatos();
  Direccion* cargaDireccion(string);
  ListaGenerica<Telefono>* cargaTelefonos(string);
  Telefono* obtenerTelefono(string);

 public:
  Lista();
  ~Lista();
  Nodo* primero;
  Nodo* ultimo;
  Nodo* sig;
  Nodo* ant;
  Nodo* actual;
  Nodo* ObtenerNodo(string);
  Persona* cargaPersona(string);
  void Crear(string const);
  void mostrarPersona();
  void Agregar(Nodo*);
  void Navegacion();
  void Mostrar();
  void mostrarTelefonos(ListaGenerica<Telefono>*);
};

#endif