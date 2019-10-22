#include <string>
using namespace std;

class Direccion {
 private:
  string ciudad;
  string calle;
  string numero;
  string epn;
  string pais;
  string region;

 public:
  Direccion();
  ~Direccion();
};

Direccion::Direccion() {}
Direccion::~Direccion() {}