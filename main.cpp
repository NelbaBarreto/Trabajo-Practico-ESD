#include <fstream>
#include <iostream>
#include <regex>

#include "./src/model/Persona.cpp"
#include "./src/model/Pila.cpp"
#include "./src/model/Lista.cpp"
using namespace std;

string const ARCHIVO_PATH = "res/agenda.xml";

bool validarXml(ifstream &);
Persona *cargaPersona(ifstream &arc);
// Telefono cargaTelefonos(string);
// Direccion cargaDirecciones(string);

int main() {
  system("cls");
  ifstream archivo;
  if (!validarXml(archivo)) {
    cout << "Error: el archivo xml no es válido.";
    exit(1);
  }

  cargaPersona(archivo);

  return 0;
}

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

      cout << "k: " << etiqueta << "; v: " << valor << endl;

      if (etiqueta == "Nombres") {
        persona->setNombre(valor);
        continue;
      }
      if (etiqueta == "Apellidos") {
        persona->setApellido(valor);
        continue;
      }
      if (etiqueta == "FechaNacimiento") {
        persona->setFechaNacimiento(valor);
        continue;
      }
      if (etiqueta == "Sexo") {
        persona->setSexo(valor == "1" ? true : false);
        continue;
      }
      if (etiqueta == "NumeroDocumento") {
        persona->setNumeroDocumento(valor);
        continue;
      }
      if (etiqueta == "TipoDocumento") {
        if (valor == "1")
          persona->setTipoDocumento("CI");
        else if (valor == "2")
          persona->setTipoDocumento("RUC");
        else
          persona->setTipoDocumento("Otro");
        continue;
      }
      if (etiqueta == "EstadoCivil") {
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
        continue;
      }
      if (etiqueta == "Nacionalidad") {
        persona->setNacionalidad(valor);
        continue;
      }
      if (etiqueta == "Email") {
        persona->setEmail(valor);
        continue;
      }
    }
  }

  cout << endl << persona->getNombre() << endl;
  arc.close();
  return persona;
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
