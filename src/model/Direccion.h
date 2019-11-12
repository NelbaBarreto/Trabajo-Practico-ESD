#include <string>
using namespace std;

#ifndef DIRECCION_H
#define DIRECCION_H

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

  Direccion operator=(const Direccion direccion) {
    this->ciudad = direccion.ciudad;
    this->calle = direccion.calle;
    this->numero = direccion.numero;
    this->epn = direccion.epn;
    this->pais = direccion.pais;
    this->region = direccion.region;
    return *this;
  }
};

#endif