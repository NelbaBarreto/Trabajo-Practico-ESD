#include <iostream>  
#include <fstream>
#include <string>    
#include <regex>
#include "../model/Pila.cpp"
#include "../model/Persona.cpp"
using namespace std;

string const ARCHIVO_PATH = "res/agenda.xml";

string mayuscula(string cadena) {
  char c = cadena[0];
  string res(1, toupper(c));
  return res;
}

bool validarXml(ifstream &arc) {
  Pila p;
  string etiqueta;
  string agenda;
  sregex_iterator i;

  arc.open(ARCHIVO_PATH);

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

// Telefono cargaTelefonos(string);
// Direccion cargaDirecciones(string);
Persona *cargaPersona(ifstream &arc) {
  Persona *persona = new Persona;
  string agenda;
  sregex_iterator i;

  arc.open(ARCHIVO_PATH);

  if (!arc) {
    cout << "Error, no se pudo abrir el archivo.";
    exit(1);
  }

  while (getline(arc, agenda)) {
    regex rp_valor("<(\\w*)>(.*)</.*>");
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
      }
    }
  }

  arc.close();
  return persona;
}