
#include <cstring>
using namespace std;

#ifndef TELEFONO_H
#define TELEFONO_H

class Telefono {
 private:
  string tipo;
  string numero;
  string interno;

 public:
  Telefono();
  ~Telefono();
  void setTipo(string);
  void setNumero(string);
  void setInterno(string);

  string getTipo();
  string getNumero();
  string getInterno();

  Telefono operator=(const Telefono telefono) {
    this->numero = telefono.numero;
    this->tipo = telefono.tipo;
    this->interno = telefono.interno;
    return *this;
  }
};

#endif