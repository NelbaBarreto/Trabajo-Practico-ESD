#include "Lista.h"
#include <iostream>
#include "../utils/funciones.cpp"
#include "./Direccion.cpp"
#include "./ListaGenerica.cpp"
#include "./Persona.cpp"
#include "./Telefono.cpp"
using namespace std;

int COD_ID = 0;

Lista::Lista() { primero = ultimo = sig = ant = NULL; }

Lista::~Lista() {}

/* -------- Navegacion -------- */
void Lista::Siguiente() {
  actual = actual->sig;
  mostrarPersona();
  system("pause");
}

void Lista::Anterior() {
  actual = actual->ant;
  mostrarPersona();
  system("pause");
}

void Lista::Primero() {
  actual = primero;
  mostrarPersona();
  system("pause");
}

void Lista::Ultimo() {
  actual = ultimo;
  mostrarPersona();
  system("pause");
}

// void mostrarDirecciones(ListaGenerica<Direccion> direcciones) {
//   NodoGenerico<Direccion> *Curr;
//   Curr = direcciones.first;
//   if (direcciones.first == NULL)
//     cout << "No hay ninguna dirección \n";
//   else
//     while (Curr != NULL) {
//       cout << Curr->data.getCiudad() << endl;
//       cout << Curr->data.getCalle() << endl;
//       cout << Curr->data.getNumero() << endl;
//       cout << Curr->data.getEpn() << endl;
//       cout << Curr->data.getPais() << endl;
//       cout << Curr->data.getRegion() << endl;
//       cout << endl << endl;
//       Curr = Curr->next;
//     }
//   cout << endl;
// }

Nodo *Lista::ObtenerNodo(string aux) {
  Nodo *Newnode;
  ifstream archivo;
  Newnode = new Nodo;
  Newnode->dato = *cargaPersona(aux);
  COD_ID++;
  Newnode->dato.setCodigo(COD_ID);
  Newnode->sig = Newnode->ant = NULL;
  return (Newnode);
}

void Lista::Agregar(Nodo *NewNode) {
  if (primero == NULL) {
    primero = NewNode;
    ultimo = NewNode;
  } else {
    ultimo->sig = NewNode;
    NewNode->ant = ultimo;
    NewNode->sig = primero;
    ultimo = NewNode;
  }
  // Ordenar();
}

void Lista::Crear(string const path) {
  string persona, aux;
  Nodo *NewNode;

  sregex_iterator i;
  ifstream arc(path);
  regex CLOSE_TAG("</Persona>");
  smatch m;

  while (getline(arc, persona)) {
    aux += persona + "\n";

    if (regex_search(persona, m, CLOSE_TAG)) {
      NewNode = ObtenerNodo(aux);
      Agregar(NewNode);
      aux = "";
    }
  }
  arc.close();
}

Direccion *Lista::cargaDireccion(string p) {
  Direccion *direccion = new Direccion;
  istringstream arc(p);
  string persona;
  sregex_iterator i;
  regex rp_valor("<(\\w*)>(.*)</.*>");

  while (getline(arc, persona)) {
    for (i = sregex_iterator(persona.begin(), persona.end(), rp_valor);
         i != std::sregex_iterator(); ++i) {
      smatch m = *i;

      string etiqueta = m[1];
      string valor = m[2];

      if (etiqueta == "Ciudad") {
        direccion->setCiudad(valor);
      } else if (etiqueta == "Calle") {
        direccion->setCalle(valor);
      } else if (etiqueta == "Numero") {
        direccion->setNumero(valor);
      } else if (etiqueta == "E_P_N") {
        direccion->setEpn(valor);
      } else if (etiqueta == "Pais") {
        direccion->setPais(valor);
      } else if (etiqueta == "Region") {
        direccion->setRegion(valor);
      } else {
        cout << "Propiedad de Direccion no válida. Verifique el xml.";
        exit(1);
      }
    }
  }

  return direccion;
}
ListaGenerica<Telefono> *Lista::cargaTelefonos(string t) {
  ListaGenerica<Telefono> *telefonos = new ListaGenerica<Telefono>;
  istringstream arc(t);

  string dir_buff = "";
  string dir_found = "";

  bool ban_dir = false;

  while (getline(arc, dir_buff)) {
    if (dir_buff.find("<Telefono")) {
      ban_dir = true;
    }

    if (ban_dir) {
      dir_found += dir_buff + "\n";
    }

    if (dir_buff.find("</Telefono>") != std::string::npos) {
      telefonos->add(obtenerTelefono(dir_found));
      dir_found = "";
      ban_dir = false;
    }
  }

  return telefonos;
}

Telefono *Lista::obtenerTelefono(string t) {
  Telefono *telefono = new Telefono;
  istringstream arc(t);
  string direccion;
  sregex_iterator i;
  while (getline(arc, direccion)) {
    regex rp_valor("<(\\w*)>(.*)</.*>");
    for (i = sregex_iterator(direccion.begin(), direccion.end(), rp_valor);
         i != std::sregex_iterator(); ++i) {
      smatch m = *i;

      string etiqueta = m[1];
      string valor = m[2];

      if (etiqueta == "Tipo") {
        telefono->setTipo(valor);
      } else if (etiqueta == "Numero") {
        telefono->setNumero(valor);
      } else if (etiqueta == "Interno") {
        telefono->setInterno(valor);
      }
    }
  }

  return telefono;
}

Persona *Lista::cargaPersona(string p) {
  Persona *persona = new Persona;

  Direccion *direccion;
  Telefono *telefono;
  istringstream arc(p);
  string agenda;
  sregex_iterator i;

  while (getline(arc, agenda)) {
    regex rp_valor("<(\\w*)>(.*</.*>)?");
    for (i = sregex_iterator(agenda.begin(), agenda.end(), rp_valor);
         i != std::sregex_iterator(); ++i) {
      smatch m = *i;

      string etiqueta = m[1];
      string valor = m[2];
      if (etiqueta == "Nombres") {
        persona->setNombre(valor);
      } else if (etiqueta == "Apellidos") {
        persona->setApellido(valor);
      } else if (etiqueta == "FechaNacimiento") {
        persona->setFechaNacimiento(valor);
      } else if (etiqueta == "Sexo") {
        persona->setSexo(valor == "1" ? "F" : valor == "2" ? "M" : "Queer");
      } else if (etiqueta == "NumeroDocumento") {
        persona->setNumeroDocumento(valor);
      } else if (etiqueta == "TipoDocumento") {
        if (valor == "1")
          persona->setTipoDocumento("CI");
        else if (valor == "2")
          persona->setTipoDocumento("RUC");
        else
          persona->setTipoDocumento("Otro");
      } else if (etiqueta == "EstadoCivil") {
        if (valor == "1")
          persona->setEstadoCivil("Soltero/a");
        else if (valor == "2")
          persona->setEstadoCivil("Casado/a");
        else if (valor == "3")
          persona->setEstadoCivil("Viudo/a");
        else if (valor == "4")
          persona->setEstadoCivil("Divorciado/a");
        else if (valor == "5")
          persona->setEstadoCivil("Divorciado/a");
      } else if (etiqueta == "Nacionalidad") {
        persona->setNacionalidad(valor);
      } else if (etiqueta == "Email") {
        persona->setEmail(valor);
      } else if (etiqueta == "Direcciones") {
        // persona->setDirecciones(cargaDirecciones(p));
      } else if (etiqueta == "Telefonos") {
        persona->setTelefonos(cargaTelefonos(p));
      }
    }
  }

  mostrarTelefonos(persona->getTelefonos());

  return persona;
}

/* -------- Operaciones -------- */
void Lista::Insertar() { 
  cout << "INSERTAR" << endl; 
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
  system("pause");
}

void Lista::Modificar() {
  cout << "MODIFICAR" << endl;
  Nodo *actual = new Nodo();
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
  system("pause");
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
      system("pause");
      break;
    }
    actual = actual->sig;
    actual = actual->sig;
  }
  if (!ban) cout << "No existe ninguna persona con ese código";
}

void Lista::AlmacenarDatos() {
  Nodo *nuevo = new Nodo();
  // nuevo->dato = ;
  if (primero == NULL) {
    primero = nuevo;
    primero->sig = NULL;
    primero->ant = NULL;
    ultimo->primero;
  } else {
    ultimo->sig = nuevo;
    nuevo->sig = NULL;
    nuevo->ant = ultimo;
    ultimo = nuevo;
  }
}
