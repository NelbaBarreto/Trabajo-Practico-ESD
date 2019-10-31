#include <string>
using namespace std;

class Telefono {
 private:
  string tipo;
  string numero;
  string interno;

 public:
  Telefono(/* args */);
  ~Telefono();
  void setTipo(string);
  void setNumero(string);
  void setInterno(string);

  string getTipo();
  string getNumero();
  string getInterno();
};

Telefono::Telefono(/* args */) {}

Telefono::~Telefono() {}
