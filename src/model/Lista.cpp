#include "Lista.h"
#include "../utils/funciones.cpp"
#include "iostream"
using namespace std;

Lista::Lista() { primero = ultimo = NULL;}

Lista::~Lista() {}

void Lista::Siguiente() {}

void Lista::Anterior() {}

void Lista::Primero() {}

void Lista::Ultimo() {}

void Lista::Insertar() { 
  cout << "INSERTAR" << endl; 
}

void Lista::Borrar() { cout << "BORRAR" << endl; }

void Lista::Modificar() { cout << "MODIFICAR" << endl; }

void Lista::Consultar() {
  Nodo *temp = primero;
  int cod = 0;
  bool ban = false;

  cout << "Ingrese el código de la persona a buscar: ";
  cin >> cod;

  while (temp != NULL) {
    if (temp->dato.codigo == cod) {
      ban = true;
      cout << temp->dato.nombre;
      break;
    }
    temp = temp->sig;
  }
  if(!ban) cout << "No existe ninguna persona con ese código";
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
  cout << "[S]iguiente - [A]nterior - [P]rimero - [U]ltimo";
  cout << "\n\nOPERACIONES" << endl;
  cout << "[I]nsertar - [B]orrar - [M]odificar - [C]onsultar";
  cout << "\n\nSALIR <Q>" << endl;
  system("pause");
  system("cls");
}

void Lista::Navegacion() {
  ImprimirOpciones();
  string res = " ";
  while (1) {
    cout << "¿Qué desea hacer?: ";
    getline(cin, res);
    res = mayuscula(res);
    system("cls");
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

int main() {
  Lista L;
  L.Navegacion();
}