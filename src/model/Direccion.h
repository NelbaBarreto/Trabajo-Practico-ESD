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
  void setCiudad(string);
  void setCalle(string);
  void setNumero(string);
  void setEpn(string);
  void setPais(string);
  void setRegion(string);

  string getCiudad();
  string getCalle();
  string getNumero();
  string getEpn();
  string getPais();
  string getRegion();
};

Direccion::Direccion() {}
Direccion::~Direccion() {}