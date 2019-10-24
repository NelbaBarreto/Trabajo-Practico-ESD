#include <string>
using namespace std;

class Nodo {
 public:
  Nodo();
  ~Nodo(){};
  string dato;
  Nodo *siguiente;
  Nodo *atras;
}*primero,*ultimo;