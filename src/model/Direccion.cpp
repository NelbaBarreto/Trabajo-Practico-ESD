#include "Direccion.h"

Direccion::Direccion() {
  ciudad = "";
  calle = "";
  numero = "";
  epn = "";
  pais = "";
  region = "";
}
Direccion::~Direccion() {}

void Direccion::setCiudad(string ciudad) { this->ciudad = ciudad; }
void Direccion::setCalle(string calle) { this->calle = calle; }
void Direccion::setNumero(string numero) { this->numero = numero; }
void Direccion::setEpn(string epn) { this->epn = epn; }
void Direccion::setPais(string pais) { this->pais = pais; }
void Direccion::setRegion(string region) { this->region = region; }

string Direccion::getCiudad() { return ciudad; }
string Direccion::getCalle() { return calle; }
string Direccion::getNumero() { return numero; }
string Direccion::getEpn() { return epn; }
string Direccion::getPais() { return pais; }
string Direccion::getRegion() { return region; }
