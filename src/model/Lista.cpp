#include "Lista.h"
#include <iostream>
#include "../utils/funciones.cpp"
#include "./Direccion.cpp"
#include "./ListaGenerica.cpp"
#include "./Persona.cpp"
#include "./Telefono.cpp"
using namespace std;

Lista::Lista() { primero = ultimo = sig = ant = NULL; }

Lista::~Lista() {}

void Lista::Siguiente() {
  actual = actual->sig;
  cout << actual;
  system("pause");
}

void Lista::Anterior() {
  actual = actual->ant;
  cout << actual;
  system("pause");
}

void Lista::Primero() {
  Nodo *actual = new Nodo();
  actual = primero;
  cout << actual;
  system("pause");
}

void Lista::Ultimo() {
  Nodo *actual = new Nodo();
  actual = ultimo;
  cout << actual;
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
void Lista::mostrarTelefonos(ListaGenerica<Telefono> *telefonos) {
  cout << endl << "cuenta" << endl;
  if (telefonos->getSize() == 0) {
    cout << "No hay ningun telfono \n";
    return;
  }
  for (int i = 0; i < telefonos->getSize(); i++) {
    cout << telefonos->get(i)->getTipo() << endl;
    cout << telefonos->get(i)->getNumero() << endl;
    cout << telefonos->get(i)->getInterno() << endl;
  }
}

Nodo *Lista::ObtenerNodo(string aux) {
  Nodo *Newnode;
  ifstream archivo;
  Newnode = new Nodo;
  Newnode->dato = *cargaPersona(aux);
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
    ultimo = NewNode;
  }
  Ordenar();
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

void Lista::Ordenar() {
  Nodo *temp;
  temp = primero;

  string tempdato;
  int contador = 0;
  while (temp) {
    temp = temp->sig;
    contador++;
  }
  temp = primero;

  for (int j = 0; j < contador; j++) {
    while (temp->sig) {
      if (temp->dato.getApellido() > temp->sig->dato.getApellido()) {
        tempdato = temp->dato.getApellido();
        temp->dato.getApellido() = temp->sig->dato.getApellido();
        temp->sig->dato.getApellido() = tempdato;
        temp = temp->sig;
      } else {
        temp = temp->sig;
      }
    }
    temp = primero;
  }
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

void Lista::Insertar() { cout << "INSERTAR" << endl; }

void Lista::Borrar() {
  cout << "BORRAR" << endl;
  Nodo *actual = new Nodo();
  actual = primero;
  Nodo *ant = new Nodo();
  ant = NULL;
  bool encontrado = false;
  int CodigoBuscado = 0;
  cout << " Ingrese el id de la persona a Buscar para Eliminar: ";
  cin >> CodigoBuscado;
  if (primero != NULL) {
    do {
      if (actual->dato.getCodigo() == CodigoBuscado) {
        cout << "\n Persona encontrada";

        if (actual == primero) {
          primero = primero->sig;
          primero->ant = ultimo;
          ultimo->sig = primero;
        } else if (actual == ultimo) {
          ultimo = ant;
          ultimo->sig = primero;
          primero->ant = ultimo;
        } else {
          ant->sig = actual->sig;
          actual->sig->ant = ant;
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
          Ordenar();
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
  Nodo *actual = new Nodo();
  actual = primero;
  bool encontrado = false;
  string NombreP;
  cout << " Ingrese el nombre de la persona a Buscar: ";
  cin >> NombreP;
  if (primero != NULL) {
    do {
      if (actual->dato.getNombre() == mayuscula(NombreP)) {
        cout << "\n Persona encontrada\n\n";
        cout << actual->dato.getNombre() << endl;
        cout << actual->dato.getApellido() << endl;
        cout << actual->dato.getFechaNacimiento() << endl;
        cout << actual->dato.getSexo() << endl;
        cout << actual->dato.getNumeroDocumento() << endl;
        cout << actual->dato.getTipoDocumento() << endl;
        cout << actual->dato.getEstadoCivil() << endl;
        cout << actual->dato.getNacionalidad() << endl;
        cout << actual->dato.getEmail() << endl;
        // cout <<actual->dato.getDirecciones()<<endl;
        // cout <<actual->dato.getTelefonos()<<endl;
        encontrado = true;
      }
      actual = actual->sig;
    } while (actual != primero && encontrado != true);
    if (!encontrado) {
      cout << "\n Persona no encontrada\n\n";
    }
  } else {
    cout << "\n La lista se Encuentra Vacia\n\n";
  }
  system("pause");
  /*Nodo *temp = primero;
  int cod = 0;
  bool ban = false;

  cout << "Ingrese el código de la persona a buscar: ";
  cin >> cod;

  while (temp != NULL) {
    if (temp->dato.getCodigo() == cod) {
      ban = true;
      cout << temp->dato.getNombre();
      break;
    }
    temp = temp->sig;
  }
  if (!ban) cout << "No existe ninguna persona con ese código";*/
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
    if (res == "Z") Mostrar();
    if (res == "Q") break;
  }
}

void Lista::Mostrar() {
  Nodo *Curr;
  Curr = primero;
  if (primero == NULL)
    cout << "La lista está vacía \n";
  else {
    while (Curr != NULL) {
      cout << Curr->dato.getCodigo() << endl;
      cout << Curr->dato.getNombre() << endl;
      cout << Curr->dato.getApellido() << endl;
      cout << Curr->dato.getFechaNacimiento() << endl;
      cout << Curr->dato.getSexo() << endl;
      cout << Curr->dato.getNumeroDocumento() << endl;
      cout << Curr->dato.getTipoDocumento() << endl;
      cout << Curr->dato.getEstadoCivil() << endl;
      cout << Curr->dato.getNacionalidad() << endl;
      cout << Curr->dato.getEmail() << endl;

      mostrarTelefonos(Curr->dato.getTelefonos());
      // mostrarDirecciones(Curr->dato.getDirecciones());
      cout << endl << endl;
      Curr = Curr->sig;
    }
  }
  cout << endl;
}