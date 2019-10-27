#include <string>
#include "Nodo.h"
using namespace std;
 
class Lista{
  private:
    void Siguiente();
    void Anterior();
    void Primero();
    void Ultimo();
    void Insertar();
    void Borrar();
    void Modificar();
    string Consultar();
    void Navegacion();
    void AlmacenarDatos();

  public:
    Lista();
    ~Lista();
    Nodo *primero;
    Nodo *ultimo;
    void ImprimirOpciones();
};
