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
  mostrarPersona();
  MenuRegistro();
}

void Lista::Anterior() {
  actual = actual->ant;
  mostrarPersona();
  MenuRegistro();
}

void Lista::Primero() {
  actual = primero;
  mostrarPersona();
  MenuRegistro();
}

void Lista::Ultimo() {
  actual = ultimo;
  mostrarPersona();
  MenuRegistro();
}

void Lista::Mostrar() {
  if (primero == NULL)
    cout << "\n\nLa lista está vacía\n\n";
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

  MenuPrincipal();
}

/* -------- Operaciones -------- */
void Lista::Insertar() {
  cout << "\nINSERTAR" << endl;
  Nodo* nuevo = new Nodo();
  Persona p;
  string CI, nombre, apellido, estadocivil, birthday, nacionalidad, email;
  int sexo = 0, tipo_doc = 0, estado_civil = 0;

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
  cout << "Ingrese su tipo de documento: (1-CI, 2-RUC, 3-Otro): ";
  while (tipo_doc < 1 || tipo_doc > 3) {
    cin >> tipo_doc;
  }
  if (tipo_doc == 1)
    p.setTipoDocumento("CI");
  else if (tipo_doc == 2)
    p.setTipoDocumento("RUC");
  else if (tipo_doc == 3)
    p.setTipoDocumento("Otro");
  cout << "Ingrese su nacionalidad: ";
  cin >> nacionalidad;
  p.setNacionalidad(nacionalidad);
  cout << "Ingrese su email: ";
  cin >> email;
  p.setEmail(email);

  char ans;
  while (1) {
    cout << "\n¿Agregar dirección? (S/N): ";
    cin >> ans;
    if (tolower(ans) == 'n') break;

    Direccion* dir = InsertarDireccion();
    p.getDirecciones()->add(dir);
  }

  while (1) {
    cout << "\n¿Agregar teléfono? (S/N): ";
    cin >> ans;
    if (tolower(ans) == 'n') break;

    cin.ignore();
    Telefono* tel = InsertarTelefono();
    p.getTelefonos()->add(tel);
  }

  nuevo = ObtenerNodo(p);
  Agregar(nuevo);

  MenuPrincipal();
}

void Lista::Borrar(int tipo) {
  if (tipo != 3) cout << "BORRAR" << endl;
  bool encontrado = false;
  Nodo* temp;
  temp = primero;

  if (primero == NULL) {
    cout << "\n\nLa lista está vacía" << endl;

    return;
  }
  MenuPrincipal();

  int CodigoBuscado = 0, cont = 0;

  if (tipo == 1) {
    cout << "Ingrese el código de la persona que desea eliminar: ";
    cin >> CodigoBuscado;
  } else {
    CodigoBuscado = actual->dato.getCodigo();
  }

  while (cont < getCantidad()) {
    cont++;
    if (temp->dato.getCodigo() == CodigoBuscado) {
      if (temp == primero) {
        if (temp == primero && temp == ultimo) {
          primero = NULL;
          ultimo = NULL;
          delete temp;
        } else {
          primero = primero->sig;
          primero->ant = ultimo;
          ultimo->sig = primero;
          delete temp;
        }
      } else {
        if (temp == ultimo) {
          ultimo = temp->ant;
          (temp->ant)->sig = primero;
          primero->ant = ultimo;
          delete temp;
        } else {
          (temp->ant)->sig = temp->sig;
          (temp->sig)->ant = temp->ant;
          delete temp;
        }
      }
      encontrado = true;
      if (tipo != 3) cout << "\nPersona eliminada\n" << endl;
      setCantidad(getCantidad() - 1);
    }
    temp = temp->sig;
  }
  if (!encontrado) cout << "No existe una persona con ese código" << endl;
   MenuPrincipal();

}

void Lista::Modificar(int tipo) {
  cout << "MODIFICAR" << endl;

  bool encontrado = false;
  int IDBuscado = 0, cont = 0;
  string buscar, pasar;

  if (tipo == 1) {
    cout << "Ingrese el código de la persona a buscar para modificar: ";
    cin >> IDBuscado;
  } else {
    IDBuscado = actual->dato.getCodigo();
  }

  actual = primero;

  if (primero != NULL) {
    do {
      cont++;
      if (actual->dato.getCodigo() == IDBuscado) {
        cout << "\nPersona encontrada : [" << actual->dato.getCodigo() << "] "
             << actual->dato.getNombre() << " " << actual->dato.getApellido();

        cout << "\nIngrese el tipo de dato que desea modificar: ";
        cin >> buscar;
        buscar = mayuscula(buscar);

        if ("NOMBRE" == buscar) {
          cout << "Ingrese el nuevo nombre: ";
          cin >> pasar;
          actual->dato.setNombre(mayuscula(pasar));
        } else if ("APELLIDO" == buscar) {
          cout << "Ingrese el nuevo apellido: ";
          cin >> pasar;

          if (actual->dato.getApellido() != mayuscula(pasar)) {
            int banana = COD_ID;
            Nodo* nodo = new Nodo;
            nodo->dato = *copiaPersona(actual->dato);

            nodo->dato.setCodigo(actual->dato.getCodigo());
            nodo->dato.setApellido(mayuscula(pasar));

            Borrar(3);
            Agregar(nodo);

            cantidad++;
            COD_ID = banana;
          } else {
            actual->dato.setApellido(mayuscula(pasar));
          }

        } else if ("FECHA DE NACIMIENTO" == buscar) {
          cout << "Ingrese la nueva fecha de nacimiento: ";
          cin >> pasar;
          actual->dato.setFechaNacimiento(mayuscula(pasar));
        } else if ("SEXO" == buscar) {
          cout << "Ingrese el nuevo sexo (1- Femenino, 2-Masculino): ";
          while (pasar != "1" && pasar != "2") {
            cin >> pasar;
          }
          actual->dato.setSexo(
              mayuscula(pasar == "1" ? "Femenino" : "Masculino"));
        } else if ("NUMERO DE DOCUMENTO" == buscar) {
          cout << "Ingrese el nuevo numero de documento: ";
          cin >> pasar;
          actual->dato.setNumeroDocumento(mayuscula(pasar));
        } else if ("TIPO DE DOCUMENTO" == buscar) {
          string tipo_doc[3] = {"CI", "RUC", "Otro"};
          cout << "Ingrese el nuevo tipo de documento (1-CI, 2-RUC, 3-Otro): ";
          while (pasar != "1" && pasar != "2" && pasar != "3") {
            cin >> pasar;
          }
          actual->dato.setTipoDocumento(tipo_doc[stoi(pasar) - 1]);
        } else if ("ESTADO CIVIL" == buscar) {
          string estado_civ[5] = {"Soltero/a", "Casado/a", "Viudo/a",
                                  "Divorciado/a", "Separado/a"};
          cout << "Ingrese el nuevo estado civil (1-Soltero/a, 2-Casado/a, "
                  "3-Viudo/a, 4-Divorciado/a, 5-Separado/a): ";
          pasar = "0";
          while (stoi(pasar) < 1 || stoi(pasar) > 5) {
            cin >> pasar;
          }
          actual->dato.setEstadoCivil(estado_civ[stoi(pasar) - 1]);
        } else if ("NACIONALIDAD" == buscar) {
          cout << "Ingrese la nueva nacionalidad: ";
          cin >> pasar;
          actual->dato.setNacionalidad(mayuscula(pasar));
        } else if ("EMAIL" == buscar) {
          cout << "Ingrese el nuevo email: ";
          cin >> pasar;
          actual->dato.setEmail(mayuscula(pasar));
        } else {
          cout << "No existe ningún campo " << buscar << endl;
           MenuPrincipal();
          return;
        }
        cout << "\nDato modificado\n\n";
        encontrado = true;
      }
      actual = actual->sig;
    } while (cont < getCantidad() && encontrado != true);
    if (!encontrado) {
      cout << "\nDato no encontrado\n\n";
    }
  } else {
    cout << "\nLa lista se Encuentra Vacia\n\n";
  }

   MenuPrincipal();
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

 MenuPrincipal();

}
