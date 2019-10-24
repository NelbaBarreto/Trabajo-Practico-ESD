#include <fstream>
#include <iostream>
#include <regex>

#include "./src/model/Pila.cpp"
using namespace std;

bool validarXml();

int main() {
  system("cls");

 cout<<  validarXml() <<" ";
  return 0;
}

bool validarXml() {
  Pila p;
  string etiqueta;
  string agenda;
  sregex_iterator i;
  ifstream archivo;

  archivo.open("res/agenda.xml");

  if (!archivo) {
    cout << "Error, no se pudo abrir el archivo.";
    exit(1);
  }

  while (getline(archivo, agenda)) {
    regex r("</?(\\w*?)>");
    regex rp("<\\w*>");

    for (i = sregex_iterator(agenda.begin(), agenda.end(), r);
         i != std::sregex_iterator(); ++i) {

      smatch m = *i;
      etiqueta = m.str();

      if (regex_match(etiqueta, r)) {
        if (regex_match(etiqueta, rp)) {
          p.push(etiqueta);
        } else {
          smatch match;
          string curr;
          if (regex_search(etiqueta, match, r)) {
            curr = match.position(1);
          }
          string top = p.getTop();
          if (regex_search(top, match, r)) {
            top = match.position(1);
          }

          if (curr != top) {
            return false;  
          }
        }
      }
    }
  }
  archivo.close();
  return true;
}
