#include "Telefono.h"

Telefono::Telefono() {}
Telefono::~Telefono() {}

void Telefono::setTipo(string tipo) { this->tipo = tipo; }
void Telefono::setNumero(string numero) { this->numero = numero; }
void Telefono::setInterno(string interno) { this->interno = interno; }

string Telefono::getTipo() { return tipo; }
string Telefono::getNumero() { return numero; }
string Telefono::getInterno() { return interno; }