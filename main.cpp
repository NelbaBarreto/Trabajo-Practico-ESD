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
  // Lista L;

  if (!validarXml(ARCHIVO_PATH)) {
    cout << "Error: el archivo xml no es válido.";
    exit(1);
  }

  L.Crear(ARCHIVO_PATH);
  L.Mostrar();

  ListaGenerica<Direccion> *direcciones = new ListaGenerica<Direccion>;
  for (int i = 0; i < 2; i++) {
    Direccion d;
    d.setNumero("1");
    d.setCalle("Tiny road");
    d.setPais("Froggyland");
    d.setRegion("Ps la mejor");
    d.setEpn("Y esto k es");
    d.setCiudad("FroggyCity");
    direcciones->add(d);
  }

  ListaGenerica<Telefono> *telefonos = new ListaGenerica<Telefono>;
  for (int i = 0; i < 2; i++) {
    Telefono t;
    t.setInterno("1");
    t.setNumero("1231232");
    t.setTipo("1");
    telefonos->add(t);
  }

  Telefono tel = telefonos->get(0);
  cout << tel.getNumero();
  return 0;
}
