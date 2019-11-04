#include "Lista.h"
#include "../utils/funciones.cpp"
#include "./Persona.h"
#include "iostream"
using namespace std;

Lista::Lista() { primero = ultimo = NULL; }

Lista::~Lista() {}

void Lista::Siguiente() {}

void Lista::Anterior() {}

void Lista::Primero() {}

void Lista::Ultimo() {}

Nodo *Lista::ObtenerNodo(Persona *persona) {
  Nodo *Newnode;
  ifstream archivo;
  Newnode = new Nodo;
  Newnode->dato = *persona;
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
      NewNode = ObtenerNodo(cargaPersona(aux));
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
Telefono *Lista::cargaTelefono(string p) {
  Telefono *telefono = new Telefono;
  istringstream arc(p);
  string persona;
  sregex_iterator i;

  while (getline(arc, persona)) {
    regex rp_valor("<(\\w*)>(.*)</.*>");
    for (i = sregex_iterator(persona.begin(), persona.end(), rp_valor);
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
      } else {
        cout << "Propiedad de Telefono no válida. Verifique el xml.";
        exit(1);
      }
    }
  }

  return telefono;
}
Persona *Lista::cargaPersona(string p) {
  Persona *persona = new Persona;
  ListaGenerica<Direccion> *direcciones;
  Direccion *direccion;
  ListaGenerica<Telefono> *telefonos;
  Telefono *telefono;
  istringstream arc(p);
  string agenda;
  sregex_iterator i;

  bool banDir = false;
  bool banTel = false;
  string strDir = "";
  string strTel = "";

  while (getline(arc, agenda)) {
    regex rp_valor("<[/]?(\\w*)>(.*)?(</.*>)?");
    for (i = sregex_iterator(agenda.begin(), agenda.end(), rp_valor);
         i != std::sregex_iterator(); ++i) {
      smatch m = *i;

      string match = m[0];
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
        direcciones = new ListaGenerica<Direccion>;
        banDir = true;
      } else if (etiqueta == "Telefonos") {
        telefonos = new ListaGenerica<Telefono>;
      }

      if (banDir) {

        if( SIZE_MAX != match.find("</Direccion>") ){
          cout << endl << strDir << endl;
          direcciones->add(cargaDireccion(strDir));
          strDir = "";
        }
        strDir = strDir + match;
      }

      if (banTel) {
        strTel = strTel + match;
      }

      if (match == "</Direcciones>"){
        banDir = false;
      }
      if (match == "</Telefonos>"){
        banDir = false;
      }
    }
  }

  return persona;
}

void Lista::Insertar() { cout << "INSERTAR" << endl; }

void Lista::Borrar() { cout << "BORRAR" << endl; }

void Lista::Modificar() { cout << "MODIFICAR" << endl; }

void Lista::Consultar() {
  Nodo *temp = primero;
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

void Lista::Mostrar() {
  Nodo *Curr;
  Curr = primero;
  if (primero == NULL)
    cout << "La lista está vacía \n";
  else
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
      cout << endl << endl;
      Curr = Curr->sig;
    }
  cout << endl;
}