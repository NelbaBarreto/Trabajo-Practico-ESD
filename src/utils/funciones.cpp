#include <cstring>
#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include "../model/Pila.cpp"
using namespace std;
#pragma once

string mayuscula(string cadena) {
  for_each(cadena.begin(), cadena.end(), [](char &c) { c = toupper(c); });
  return cadena;
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

Persona *copiaPersona(Persona ori) {
  Persona *percpy = new Persona;

  percpy->setCodigo(ori.getCodigo());
  percpy->setNombre(ori.getNombre());
  percpy->setApellido(ori.getApellido());
  percpy->setFechaNacimiento(ori.getFechaNacimiento());
  percpy->setSexo(ori.getSexo());
  percpy->setNumeroDocumento(ori.getNumeroDocumento());
  percpy->setTipoDocumento(ori.getTipoDocumento());
  percpy->setTipoDocumento(ori.getTipoDocumento());
  percpy->setTipoDocumento(ori.getTipoDocumento());
  percpy->setEstadoCivil(ori.getEstadoCivil());
  percpy->setEstadoCivil(ori.getEstadoCivil());
  percpy->setEstadoCivil(ori.getEstadoCivil());
  percpy->setEstadoCivil(ori.getEstadoCivil());
  percpy->setEstadoCivil(ori.getEstadoCivil());
  percpy->setNacionalidad(ori.getNacionalidad());
  percpy->setEmail(ori.getEmail());
  percpy->setDirecciones(ori.getDirecciones());
  percpy->setTelefonos(ori.getTelefonos());

  return percpy;
}

void Lista::mostrarPersona() {
  cout << "CÓDIGO: " << actual->dato.getCodigo() << endl;
  cout << "NOMBRE: " << actual->dato.getNombre() << endl;
  cout << "APELLIDO: " << actual->dato.getApellido() << endl;
  cout << "FECHA NAC.: " << actual->dato.getFechaNacimiento() << endl;
  cout << "SEXO: " << actual->dato.getSexo() << endl;
  cout << "CI: " << actual->dato.getNumeroDocumento() << endl;
  cout << "TIPO DOC.: " << actual->dato.getTipoDocumento() << endl;
  cout << "ESTADO CIVIL: " << actual->dato.getEstadoCivil() << endl;
  cout << "NACIONALIDAD: " << actual->dato.getNacionalidad() << endl;
  cout << "EMAIL: " << actual->dato.getEmail() << endl;
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
    cout << "No hay ningun telefono\n";
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


void Lista::MenuPrincipal() {
  cout << "NAVEGACIÓN" << endl;
  cout << "[P]rimero - [U]ltimo - [L]istar todo";
  cout << "\n\nOPERACIONES" << endl;
  cout << "[I]nsertar - [B]orrar - [M]odificar - [C]onsultar";
  cout << "\n\nSALIR <Q>" << endl;
  Navegacion(1);
}

void Lista::MenuRegistro() {
  cout << "NAVEGACIÓN" << endl;
  cout << "[S]iguiente - [A]nterior - [P]rimero - [U]ltimo - [L]istar todo";
  cout << "\n\nOPERACIONES" << endl;
  cout << "[I]nsertar - [B]orrar Actual - [M]odificar Actual - [C]onsultar";
  cout << "\n\nSALIR <Q>\tATRÁS <Y>" << endl;
  Navegacion(2);
}

void Lista::Navegacion(int tipo) {
  string res = "";
  while (1) {
    cout << "¿Qué desea hacer?: ";
    cin >> res;
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
      Borrar(tipo);
    else if (res == "M")
      Modificar(tipo);
    else if (res == "C")
      Consultar();
    else if (res == "Y")
      MenuPrincipal();
    else if (res == "Q")
      exit(0);
    else
      cout << "Ingrese una opcion valida.\n";
  }
}
