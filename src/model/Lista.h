#include <string>
#include "Nodo.h"
using namespace std;

void almacenarDatos() {
  Nodo *nuevo = new Nodo();
  // nuevo->dato = ;
  if (primero == NULL) {
    primero = nuevo;
    primero->siguiente = NULL;
    primero->atras = NULL;
    ultimo->primero;
  } else {
    ultimo->siguiente = nuevo;
    nuevo->siguiente = NULL;
    nuevo->atras = ultimo;
    ultimo = nuevo;
  }
}