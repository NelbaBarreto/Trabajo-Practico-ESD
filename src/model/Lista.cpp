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

Lista::Lista() {
  primero = ultimo = sig = ant = NULL;
  cantidad = 0;
}

Lista::~Lista() {}

/* -------- Navegacion -------- */
void Lista::Siguiente() {
  actual = actual->sig;
  string r, op;
  mostrarPersona();
  cout << "Desea realizar una operacion con el registro actual ?";
  cin >> r;
  if (r == "si") {
    cout << "Que operacion desea realizar ([B]orrar / [M]odificar) ?";
    cin >> op;
    op == "B" ? Borrar() : Modificar();
  } else {
    Navegacion();
  }
}

void Lista::Anterior() {
  actual = actual->ant;
  string r, op;
  mostrarPersona();
  cout << "Desea realizar una operacion con el registro actual ?";
  cin >> r;
  if (r == "si") {
    cout << "Que operacion desea realizar ([B]orrar / [M]odificar) ?";
    cin >> op;
    op == "B" ? Borrar() : Modificar();
  } else {
    Navegacion();
  }
}

void Lista::Primero() {
  actual = primero;
  string r, op;
  mostrarPersona();
  cout << "Desea realizar una operacion con el registro actual ?";
  cin >> r;
  if (r == "si") {
    cout << "Que operacion desea realizar ([B]orrar / [M]odificar) ?";
    cin >> op;
    op == "B" ? Borrar() : Modificar();
  } else {
    Navegacion();
  }
}

void Lista::Ultimo() {
  actual = ultimo;
  string r, op;
  mostrarPersona();
  cout << "Desea realizar una operacion con el registro actual ?";
  cin >> r;
  if (r == "si") {
    cout << "Que operacion desea realizar ([B]orrar / [M]odificar) ?";
    cin >> op;
    op == "B" ? Borrar() : Modificar();
  } else {
    Navegacion();
  }
}

void Lista::Mostrar() {
  if (primero == NULL)
    cout << "La lista está vacía \n";
  else if (primero == ultimo)
    mostrarPersona();
  else {
    Nodo* aux = actual;
    actual = primero;
    int cont = 0;

    do {
      cout << "--------------------------------\n";
      cont++;
      mostrarPersona();
      cout << endl;
      actual = actual->sig;
    } while (cont < cantidad);

    actual = aux;
  }

  Navegacion();
}

/* -------- Operaciones -------- */
void Lista::Insertar() {
  cout << "\nINSERTAR" << endl;
  Nodo* nuevo = new Nodo();
  Persona p;
  string CI, nombre, apellido, estadocivil, birthday, nacionalidad, email;
  int sexo = 0, tipo_doc, estado_civil;

  cout << "Ingrese su nombre: ";
  cin >> nombre;
  p.setNombre(mayuscula(nombre));
  cout << "Ingrese su apellido: ";
  cin >> apellido;
  p.setApellido(mayuscula(apellido));
  cout << "Ingrese su fecha de nacimiento: ";
  cin >> birthday;
  p.setFechaNacimiento(birthday);
  cout << "Ingrese su sexo (Femenino = 1/Masculino = 2): ";
  while (sexo != 1 && sexo != 2) {
    cin >> sexo;

  }
  sexo == 1 ? p.setSexo("Femenino") : p.setSexo("Masculino");
  cout << "Ingrese su numero de documento: ";
  cin >> CI;
  p.setNumeroDocumento(CI);
  cout << "Ingrese su estado civil (1-Soltero/a, 2-Casado/a, 3-Viudo/a, "
          "4-Divorciado/a, 5-Separado/a): ";
  cin >> estado_civil;
  if (estado_civil == 1)
    p.setEstadoCivil("Soltero/a");
  else if (estado_civil == 2)
    p.setEstadoCivil("Casado/a");
  else if (estado_civil == 3)
    p.setEstadoCivil("Viudo/a");
  else if (estado_civil == 4)
    p.setEstadoCivil("Divorciado/a");
  else if (estado_civil == 5)
    p.setEstadoCivil("Separado/a");
  cout << "Ingrese su nacionalidad: ";
  cin >> nacionalidad;
  p.setNacionalidad(nacionalidad);
  cout << "Ingrese su email: ";
  cin >> email;
  p.setEmail(email);

  char ans;
  Direccion* d;
  while (1) {
    cout << "\n¿Agregar dirección? (S/N): ";
    cin >> ans;
    if (tolower(ans) == 'n') break;
    p.getDirecciones()->add(InsertarDireccion(d));
  }

  Telefono* t;
  while (1) {
    cout << "\n¿Agregar teléfono? (S/N): ";
    cin >> ans;
    if (tolower(ans) == 'n') break;
    p.getTelefonos()->add(InsertarTelefono(t));
  }

  nuevo = ObtenerNodo(p);
  Agregar(nuevo);
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
        cout << "\nPersona eliminada\n\n";
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
  setCantidad(getCantidad() - 1);
}

void Lista::Modificar() {
  cout << "MODIFICAR" << endl;
  Nodo* actual = new Nodo();
  actual = primero;
  bool encontrado = false;
  int IDBuscado;
  string buscar, pasar;
  cout << "Ingrese el código de la persona a buscar para modificar: ";
  cin >> IDBuscado;
  if (primero != NULL) {
    do {
      if (actual->dato.getCodigo() == IDBuscado) {
        cout << "\nPersona encontrada";
        cout << "\nIngrese el tipo de dato que desea modificar ";
        cin >> buscar;
        if ("nombre" == buscar) {
          cout << "Ingrese el nuevo nombre";
          cin >> pasar;
          actual->dato.setNombre(mayuscula(pasar));
        } else if ("apellido" == buscar) {
          cout << "Ingrese el nuevo apellido";
          cin >> pasar;
          actual->dato.setApellido(mayuscula(pasar));
          // Ordenar();
        } else if ("fechanacimiento" == buscar) {
          cout << "Ingrese la nueva fecha de nacimiento";
          cin >> pasar;
          actual->dato.setFechaNacimiento(mayuscula(pasar));
        } else if ("sexo" == buscar) {
          cout << "Ingrese el nuevo sexo ";
          cin >> pasar;
          actual->dato.setSexo(mayuscula(pasar));
        } else if ("numerodocumento" == buscar) {
          cout << "Ingrese el nuevo numero de documento";
          cin >> pasar;
          actual->dato.setNumeroDocumento(mayuscula(pasar));
        } else if ("tipodocumento" == buscar) {
          cout << "Ingrese el nuevo tipo de documento";
          cin >> pasar;
          actual->dato.setTipoDocumento(mayuscula(pasar));
        } else if ("estadocivil" == buscar) {
          cout << "Ingrese el nuevo estado civil";
          cin >> pasar;
          actual->dato.setEstadoCivil(mayuscula(pasar));
        } else if ("nacionalidad" == buscar) {
          cout << "Ingrese la nueva nacionalidad ";
          cin >> pasar;
          actual->dato.setNacionalidad(mayuscula(pasar));
        } else if ("email" == buscar) {
          cout << "Ingrese el nuevo email";
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
      cout << "\nDato no encontrado\n\n";
    }
  } else {
    cout << "\nLa lista se Encuentra Vacia\n\n";
  }
  // system("pause");
}

void Lista::Consultar() {
  actual = primero;
  int cod = 0, cont = 0;

  cout << "Ingrese el código de la persona a buscar: ";
  cin >> cod;

  while (cont < cantidad) {
    cont++;
    if (actual->dato.getCodigo() == cod) {
      mostrarPersona();
      return;
    }
    actual = actual->sig;
  }
  cout << "No existe ninguna persona con ese código";
}
