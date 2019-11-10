#include "Lista.h"
#include <iostream>
#include <regex>
#include "../utils/cargarDatos.cpp"
#include "../utils/funciones.cpp"
#include "./Direccion.cpp"
#include "./ListaGenerica.cpp"
#include "./Persona.cpp"
#include "./Telefono.cpp"
using namespace std;

Lista::Lista() { primero = ultimo = sig = ant = NULL; }

Lista::~Lista() {}

/* -------- Navegacion -------- */
void Lista::Siguiente() {
  actual = actual->sig;
  mostrarPersona();

  Navegacion();
}

void Lista::Anterior() {
  actual = actual->ant;
  mostrarPersona();
  Navegacion();
}

void Lista::Primero() {
  actual = primero;
  mostrarPersona();
  Navegacion();
}

void Lista::Ultimo() {
  actual = ultimo;
  mostrarPersona();
  Navegacion();
}

void Lista::Mostrar() {
  if (primero == NULL)
    cout << "La lista está vacía \n";
  else if (primero == ultimo)
    mostrarPersona();
  else {
    Nodo* aux = actual;
    actual = primero;

    do {
      cout << "--------------------------------\n";
      mostrarPersona();
      cout << endl;
      actual = actual->sig;
    } while (actual->ant != ultimo);

    actual = aux;
  }

  Navegacion();
}

/* -------- Operaciones -------- */
void Lista::Insertar() {
  cout << "INSERTAR" << endl;
  Nodo* nuevo = new Nodo();
  int COMPARADOR = 0;
  int BAND = 0;
  string CI, nombre, apellido, estadocivil, birthday, nacionalidad, email;
  int sexo, tipo_doc, estado_civil;

  do {
    if (nuevo->dato.getCodigo() == COMPARADOR) {
      COMPARADOR++;
    } else {
      cout << "Ingrese su nombre" << endl;
      cin >> nombre;
      nuevo->dato.setNombre(nombre);
      cout << "Ingrese su apellido" << endl;
      cin >> apellido;
      nuevo->dato.setApellido(apellido);
      cout << "Ingrese su fecha de nacimiento" << endl;
      cin >> birthday;
      nuevo->dato.setFechaNacimiento(birthday);
      cout << "Ingrese su sexo" << endl;
      while (sexo != 1 && sexo != 2) {
        cin >> sexo;
      }
      sexo == 1 ? nuevo->dato.setSexo("FEMENINO")
                : nuevo->dato.setSexo("MASCULINO");
      cout << "Ingrese su numero de documento" << endl;
      cin >> CI;
      nuevo->dato.setNumeroDocumento(CI);
      cout << "Ingrese su estado civil (1-Soltero/a, 2-Casado/a, 3-Viudo/a, "
              "4-Divorciado/a, 5-Separado/a)"
           << endl;
      cin >> estado_civil;
      if (estado_civil == 1)
        nuevo->dato.setEstadoCivil("Soltero/a");
      else if (estado_civil == 2)
        nuevo->dato.setEstadoCivil("Casado/a");
      else if (estado_civil == 3)
        nuevo->dato.setEstadoCivil("Viudo/a");
      else if (estado_civil == 4)
        nuevo->dato.setEstadoCivil("Divorciado/a");
      else if (estado_civil == 5)
        nuevo->dato.setEstadoCivil("Separado/a");
      cout << "Ingrese su nacionalidad" << endl;
      cin >> nacionalidad;
      nuevo->dato.setNacionalidad(nacionalidad);
      cout << "Ingrese su email" << endl;
      cin >> email;
      nuevo->dato.setEmail(email);
      if (primero == NULL) {
        primero = nuevo;
        ultimo = nuevo;
        primero->sig = primero;
        primero->ant = ultimo;
      } else {
        ultimo->sig = nuevo;
        nuevo->ant = ultimo;
        nuevo->sig = primero;
        ultimo = nuevo;
        primero->ant = ultimo;
      }
      BAND = 1;
    }

  } while (BAND != 0);
}

void Lista::Borrar() {
  cout << "BORRAR" << endl;
  actual = primero;
  bool encontrado = false;
  int CodigoBuscado = 0;
  cout << "Ingrese el código de la persona que desea eliminar: ";
  cin >> CodigoBuscado;
  if (primero != NULL) {
    do {
      if (actual->dato.getCodigo() == CodigoBuscado) {
        cout << "\nPersona encontrada";

        if (actual == primero) {
          primero->ant = ultimo;
          ultimo->sig = primero;
          primero = primero->sig;
        } else if (actual == ultimo) {
          ultimo = ant;
          ultimo->sig = primero;
          primero->ant = ultimo;
        } else {
          ant->sig = actual->sig;
          actual->ant->sig = actual->sig;
        }
        cout << "\n Persona eliminada\n\n";
        encontrado = true;
      }
      ant = actual;
      actual = actual->sig;
    } while (actual != primero && encontrado != true);

    if (!encontrado) {
      cout << "\n Persona no encontrada\n\n";
    }

  } else {
    cout << "\n La lista se Encuentra Vacia\n\n";
  }
  // system("pause");
}

void Lista::Modificar() {
  cout << "MODIFICAR" << endl;
  Nodo* actual = new Nodo();
  actual = primero;
  bool encontrado = false;
  int IDBuscado;
  string buscar, pasar;
  cout << " Ingrese el id de la persona a Buscar para Modificar: ";
  cin >> IDBuscado;
  if (primero != NULL) {
    do {
      if (actual->dato.getCodigo() == IDBuscado) {
        cout << "\n Persona encontrada";
        cout << "\n Ingrese el tipo de dato que desea modificar ";
        cin >> buscar;
        if ("nombre" == buscar) {
          cin >> pasar;
          actual->dato.setNombre(mayuscula(pasar));
        } else if ("apellido" == buscar) {
          cin >> pasar;
          actual->dato.setApellido(mayuscula(pasar));
          // Ordenar();
        } else if ("fechanacimiento" == buscar) {
          cin >> pasar;
          actual->dato.setFechaNacimiento(mayuscula(pasar));
        } else if ("sexo" == buscar) {
          cin >> pasar;
          actual->dato.setSexo(mayuscula(pasar));
        } else if ("numerodocumento" == buscar) {
          cin >> pasar;
          actual->dato.setNumeroDocumento(mayuscula(pasar));
        } else if ("tipodocumento" == buscar) {
          cin >> pasar;
          actual->dato.setTipoDocumento(mayuscula(pasar));
        } else if ("estadocivil" == buscar) {
          cin >> pasar;
          actual->dato.setEstadoCivil(mayuscula(pasar));
        } else if ("nacionalidad" == buscar) {
          cin >> pasar;
          actual->dato.setNacionalidad(mayuscula(pasar));
        } else if ("email" == buscar) {
          cin >> pasar;
          actual->dato.setEmail(mayuscula(pasar));
          // }else if("direcciones" == buscar){
          //       cin >>pasar;
          //       actual->dato.setDirecciones(pasar);
          // }else if("telefonos" == buscar){
          //       cin >>pasar;
          //       actual->dato.setTelefonos(pasar);
        }
        cout << "\n Dato modificado\n\n";
        encontrado = true;
      }
      actual = actual->sig;
    } while (actual != primero && encontrado != true);
    if (!encontrado) {
      cout << "\n Dato no encontrado\n\n";
    }
  } else {
    cout << "\n La lista se Encuentra Vacia\n\n";
  }
  // system("pause");
}

void Lista::Consultar() {
  actual = primero;
  int cod = 0;
  bool ban = false;

  cout << "Ingrese el código de la persona a buscar: ";
  cin >> cod;

  while (actual != NULL) {
    if (actual->dato.getCodigo() == cod) {
      ban = true;
      mostrarPersona();
      // system("pause");
      break;
    }
    actual = actual->sig;
    actual = actual->sig;
  }
  if (!ban) cout << "No existe ninguna persona con ese código";
}
