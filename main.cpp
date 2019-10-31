#include <iostream>
#include <string>
#include "src/utils/funciones.cpp"
#ifndef LISTA
#include "src/model/Lista.cpp"
#endif
#ifndef DIRECCION
#define DIRECCION
#endif
#ifndef TELEFONO
#define TELEFONO
#endif
#ifndef PERSONA
#define PERSONA
#endif
//#include "src/model/Lista.cpp"
// #include "src/model/Direccion.cpp"
// #include "src/model/Telefono.cpp"
// #include "src/model/Persona.cpp"

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
