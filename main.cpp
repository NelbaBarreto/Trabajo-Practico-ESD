#include <fstream>
#include <iostream>

// #include "./src/model/Lista.cpp"
// #include "./src/model/Pila.cpp"
#include "./src/utils/funciones.cpp"
using namespace std;

int main() {
  system("cls");
  ifstream archivo;
  if (!validarXml(archivo)) {
    cout << "Error: el archivo xml no es válido.";
    exit(1);
  }

  Persona *persona = cargaPersona(archivo);

  cout << persona->getCodigo() << endl;
  cout << persona->getNombre() << endl;
  cout << persona->getApellido() << endl;
  cout << persona->getFechaNacimiento() << endl;
  cout << persona->getSexo() << endl;
  cout << persona->getNumeroDocumento() << endl;
  cout << persona->getTipoDocumento() << endl;
  cout << persona->getEstadoCivil() << endl;
  cout << persona->getNacionalidad() << endl;
  cout << persona->getEmail() << endl;

  return 0;
}



