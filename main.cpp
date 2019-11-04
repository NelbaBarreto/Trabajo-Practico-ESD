#include <iostream>
#include <cstring>
#include "src/utils/funciones.cpp"
#include "src/model/Lista.cpp"

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
  L.Mostrar();

  return 0;
}
