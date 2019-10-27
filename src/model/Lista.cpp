#include "Lista.h"
#include "iostream"
using namespace std;

Lista::Lista() {}

Lista::~Lista() {}

void Lista::Siguiente() {}

void Lista::Anterior() {}

void Lista::Primero() {}

void Lista::Ultimo() {}

void Lista::Insertar() {}

void Lista::Borrar() {}

void Lista::Modificar() {}

string Lista::Consultar() {
  Nodo *temp = primero;
  while (temp != NULL) {
    if (temp->dato == "codigo") {
      return temp->dato;
    }
    temp = temp->sig;
  }
}

void Lista::AlmacenarDatos() {
  Nodo *nuevo = new Nodo();
  // nuevo->dato = ;
  if (primero == NULL) {
    primero = nuevo;
    primero->sig = NULL;
    primero->atras = NULL;
    ultimo->primero;
  } else {
    ultimo->sig = nuevo;
    nuevo->sig = NULL;
    nuevo->atras = ultimo;
    ultimo = nuevo;
  }
}

void Lista::ImprimirOpciones() {
  cout << "NAVEGACIÓN" << endl;
  cout << "Siguiente (S)" << endl;
  cout << "Anterior (A)" << endl;
  cout << "Primero (P)" << endl;
  cout << "Último (U)" << endl;
  cout << "Siguiente (S)" << endl << endl;
  cout << "OPERACIONES" << endl;
  cout << "Insertar (I)" << endl;
  cout << "Borrar (B)" << endl;
  cout << "Modificar (M)" << endl;
  cout << "Consultar (C)" << endl << endl;
  cout << "SALIR (Q)" << endl;
}

void Lista::Navegacion() {
  ImprimirOpciones();
  string res = " ";
  while (1) {
    getline(cin, res);
    if (res == "S") Siguiente();
    if (res == "A") Anterior();
    if (res == "P") Primero();
    if (res == "U") Ultimo();
    if (res == "I") Insertar();
    if (res == "B") Borrar();
    if (res == "M") Modificar();
    if (res == "C") Consultar();
    if (res == "Q") break;
  }
}
