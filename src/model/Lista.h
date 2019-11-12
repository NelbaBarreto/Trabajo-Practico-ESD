#include <cstring>
#include <fstream>
#include "Nodo.h"
using namespace std;

#ifndef LISTA_H
#define LISTA_H

class Lista {
 private:
  int cantidad;
  void Siguiente();
  void Anterior();
  void Primero();
  void Ultimo();
  void Insertar();
  void Borrar(int);
  void Modificar(int);
  void Consultar();
  void MenuRegistro();
  void Navegacion(int);
  Direccion* InsertarDireccion();
  Telefono* InsertarTelefono();
  Direccion* obtenerDireccion(string);
  ListaGenerica<Direccion>* cargaDirecciones(string);
  Telefono* obtenerTelefono(string);
  ListaGenerica<Telefono>* cargaTelefonos(string);

 public:
  Lista();
  ~Lista();
  Nodo* primero;
  Nodo* ultimo;
  Nodo* sig;
  Nodo* ant;
  Nodo* actual;
  Nodo* ObtenerNodo(Persona);
  Persona* cargaPersona(string);
  void setCantidad(int cantidad) { this->cantidad = cantidad; }
  int getCantidad() { return cantidad; }
  void Crear(string const);
  void mostrarPersona();
  void Agregar(Nodo*);
  void MenuPrincipal();
  void Mostrar();
  void mostrarTelefonos(ListaGenerica<Telefono>*);
  void mostrarDirecciones(ListaGenerica<Direccion>*);
};

#endif