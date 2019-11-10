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
  mostrarDirecciones(actual->dato.getDirecciones());
}

void Lista::mostrarDirecciones(ListaGenerica<Direccion> *direcciones) {
  if (direcciones->getSize() == 0) {
    cout << "No hay ninguna direccion \n";
    return;
  }
  cout << "Direcciones\n";

  for (int i = 0; i < direcciones->getSize(); i++) {
    cout << "->Direccion\n";
    cout << "-->" << direcciones->get(i)->getCiudad() << endl;
    cout << "-->" << direcciones->get(i)->getCalle() << endl;
    cout << "-->" << direcciones->get(i)->getNumero() << endl;
    cout << "-->" << direcciones->get(i)->getEpn() << endl;
    cout << "-->" << direcciones->get(i)->getPais() << endl;
    cout << "-->" << direcciones->get(i)->getRegion() << endl;
  }
}

void Lista::mostrarTelefonos(ListaGenerica<Telefono> *telefonos) {
  if (telefonos->getSize() == 0) {
    cout << "No hay ningun telfono\n";
    return;
  }
  cout << "Telefonos\n";
  for (int i = 0; i < telefonos->getSize(); i++) {
    cout << "->Telefono\n";
    cout << "-->" << telefonos->get(i)->getTipo() << endl;
    cout << "-->" << telefonos->get(i)->getNumero() << endl;
    cout << "-->" << telefonos->get(i)->getInterno() << endl;
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
  cout << "[S]iguiente - [A]nterior - [P]rimero - [U]ltimo - [L]istar todo";
  cout << "\n\nOPERACIONES" << endl;
  cout << "[I]nsertar - [B]orrar - [M]odificar - [C]onsultar";
  cout << "\n\nSALIR <Q>" << endl;
}

void Lista::Navegacion() {
  ImprimirOpciones();
  string res = "";
  while (1) {
    cout << "¿Qué desea hacer?: ";
    getline(cin, res);
    res = mayuscula(res);
    if (res == "S")
      Siguiente();
    else if (res == "A")
      Anterior();
    else if (res == "P")
      Primero();
    else if (res == "U")
      Ultimo();
    else if (res == "L")
      Mostrar();
    else if (res == "I")
      Insertar();
    else if (res == "B")
      Borrar();
    else if (res == "M")
      Modificar();
    else if (res == "C")
      Consultar();
    else if (res == "Q")
      exit(0);
    else
      cout << "Ingrese una opcion valida.\n";
  }
}

