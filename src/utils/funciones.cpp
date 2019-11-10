#include <cstring>
#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include "../model/Pila.cpp"
using namespace std;
#pragma once

string mayuscula(string cadena) {
  char c = cadena[0];
  string res(1, toupper(c));
  return res;
}

bool validarXml(string path) {
  Pila p;
  string etiqueta;
  string agenda;
  sregex_iterator i;

  cout << "Validando..." << endl;
  fstream arc(path);

  if (!arc) {
    cout << "Error, no se pudo abrir el archivo.";
    exit(1);
  }

  while (getline(arc, agenda)) {
    regex r("</?(\\w*?)>");
    regex rp("<\\w*>");

    for (i = sregex_iterator(agenda.begin(), agenda.end(), r);
         i != std::sregex_iterator(); ++i) {
      smatch m = *i;
      etiqueta = m.str();

      if (regex_search(etiqueta, r)) {
        if (regex_search(etiqueta, rp)) {
          p.push(etiqueta);
        } else {
          smatch match;
          string curr;
          if (regex_search(etiqueta, match, r)) {
            curr = match[1];
          }
          string top = p.getTop();
          if (regex_search(top, match, r)) {
            top = match[1];
          }

          if (curr != top) {
            return false;
          }
          p.pop();
        }
      }
    }
  }
  arc.close();
  return true;
}

void Lista::mostrarPersona() {
  cout << actual->dato.getCodigo() << endl;
  cout << actual->dato.getNombre() << endl;
  cout << actual->dato.getApellido() << endl;
  cout << actual->dato.getFechaNacimiento() << endl;
  cout << actual->dato.getSexo() << endl;
  cout << actual->dato.getNumeroDocumento() << endl;
  cout << actual->dato.getTipoDocumento() << endl;
  cout << actual->dato.getEstadoCivil() << endl;
  cout << actual->dato.getNacionalidad() << endl;
  cout << actual->dato.getEmail() << endl;
  mostrarTelefonos(actual->dato.getTelefonos());
  // mostrarDirecciones(Curr->dato.getDirecciones());
  Navegacion();
}

void Lista::mostrarDirecciones(ListaGenerica<Direccion> *direcciones) {
  if (direcciones->getSize() == 0) {
    cout << "No hay ninguna direccion \n";
    return;
  }
  cout << "Direcciones\n";

  for (int i = 0; i < direcciones->getSize(); i++) {
    cout << "\tDireccion\n";
    cout << "\t\t" << direcciones->get(i)->getCiudad() << endl;
    cout << "\t\t" << direcciones->get(i)->getCalle() << endl;
    cout << "\t\t" << direcciones->get(i)->getNumero() << endl;
    cout << "\t\t" << direcciones->get(i)->getEpn() << endl;
    cout << "\t\t" << direcciones->get(i)->getPais() << endl;
    cout << "\t\t" << direcciones->get(i)->getRegion() << endl;
  }
}

void Lista::mostrarTelefonos(ListaGenerica<Telefono> *telefonos) {
  if (telefonos->getSize() == 0) {
    cout << "No hay ningun telfono\n";
    return;
  }
  cout << "Telefonos\n";
  for (int i = 0; i < telefonos->getSize(); i++) {
    cout << " Telefono\n";
    cout << "  " << telefonos->get(i)->getTipo() << endl;
    cout << "  " << telefonos->get(i)->getNumero() << endl;
    cout << "  " << telefonos->get(i)->getInterno() << endl;
  }
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
  actual = primero;
  int cont = 0;
  bool ban = false;

  if (primero == NULL)
    cout << "La lista está vacía \n";
  else {
    while (!ban) {
      mostrarPersona();
      cout << endl << endl;
      actual = actual->sig;
      cont++;
      ban = actual->dato.getCodigo() == 1 && cont != 1;
    }
  }
  cout << endl;
}
