#include <string>
using namespace std;

class Nodo {
 public:
  Nodo() {};
  ~Nodo(){};
  string dato;
  Nodo *sig;
  Nodo *atras;
  Nodo *primero;
  Nodo *ultimo;
};