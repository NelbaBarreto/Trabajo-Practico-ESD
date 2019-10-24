#include "Lista.h"
#include "iostream"
using namespace std;

Lista::Lista() {}

Lista::~Lista() {}

Lista::Siguiente() {}

Lista::Anterior() {}

Lista::Primero() {}

void Lista::Insertar() {}

void Lista::Borrar() {}

void Lista::Modificar() {}

string Lista::Consultar(int codigo) {
  Nodo *temp = cabeza;
  while (temp != NULL) {
    if (temp->dato == codigo) {
      return temp->dato;
    }
    temp = temp->sig;
  }
  return 0;
}

void Lista::ImprimirOpciones() {
  cout << "NAVEGACIÓN" << endl;
  cout << "Siguiente (S)" << endl;
  cout << "Anterior (A)" << endl;
  cout << "Primero (P)" << endl;
  cout << "Último (U)" << endl;
  cout << "Siguiente (S)" << endl;
  cout << "OPERACIONES" << endl << endl;
  cout << "Insertar (I)" << endl;
  cout << "Borrar (B)" << endl;
  cout << "Modificar (M)" << endl;
  cout << "Consultar (C)" << endl << endl;
  cout << "SALIR (Q)" << endl;
}

void Lista::Navegacion() {
  ImprimirOpciones();
  char res = ' ';
  while (1) {
    getline(cin, res);
    if (res == 'S') Siguiente();
    if (res == 'A') Anterior();
    if (res == 'P') Primero();
    if (res == 'U') Ultimo();
    if (res == 'I') Insertar();
    if (res == 'B') Borrar();
    if (res == 'M') Modificar();
    if (res == 'C') Consultar();
    if (res == 'Q') break;
  }
}
