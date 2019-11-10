#include <cstring>
#include <iostream>
#include "src/model/Lista.cpp"
#include "src/utils/funciones.cpp"

using namespace std;

int main() {
  system("cls");
  string const ARCHIVO_PATH = "res/agenda.xml";
  Lista L;

  if (!validarXml(ARCHIVO_PATH)) {
    cout << "Error: el archivo xml no es válido.";
    exit(1);
  }

  L.Crear(ARCHIVO_PATH);
  L.Navegacion();

  return 0;
}
