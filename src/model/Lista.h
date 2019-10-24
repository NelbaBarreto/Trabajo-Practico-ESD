#include <string>
#include "Nodo.h"
using namespace std;
 
class Lista{
  private:
    void Siguiente();
    void Anterior();
    void Primero();
    void Insertar();
    void Borrar();
    void Modificar();
    string Consultar(int);
    void ImprimirOpciones();
    void Navegacion();
    void AlmacenarDatos();
  public:
    Lista();
    ~Lista();
};

void Lista::AlmacenarDatos() {
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