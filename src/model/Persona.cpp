#include "Persona.h"

Persona::Persona() {
  nombre = "";
  apellido = "";
  fechaNacimiento = "";
  sexo = "";
  numeroDocumento = "";
  tipoDocumento = "";
  estadoCivil = "";
  nacionalidad = "";
  email = "";
  codigo = 0;
}

Persona::~Persona() {}

void Persona::setCodigo(int codigo) { this->codigo = codigo; }
void Persona::setNombre(string nombre) { this->nombre = nombre; }
void Persona::setApellido(string apellido) { this->apellido = apellido; }
void Persona::setFechaNacimiento(string fechaNacimiento) {
  this->fechaNacimiento = fechaNacimiento;
}
void Persona::setSexo(string sexo) { this->sexo = sexo; }
void Persona::setNumeroDocumento(string numeroDocumento) {
  this->numeroDocumento = numeroDocumento;
}
void Persona::setTipoDocumento(string tipoDocumento) {
  this->tipoDocumento = tipoDocumento;
}
void Persona::setEstadoCivil(string estadoCivil) {
  this->estadoCivil = estadoCivil;
}
void Persona::setNacionalidad(string nacionalidad) {
  this->nacionalidad = nacionalidad;
}
void Persona::setEmail(string email) { this->email = email; }
int Persona::getCodigo() { return codigo; }

void Persona::setTelefonos(ListaGenerica<Telefono> *telefonos) {
  this->telefonos = telefonos;
}
// void Persona::setDirecciones(ListaGenerica<Direccion> *direcciones) {
//   this->direcciones = direcciones;
// }
