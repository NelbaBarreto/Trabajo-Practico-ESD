#include "Direccion.h"
#include "ListaGenerica.h"
#include "Telefono.h"

#include <cstring>
using namespace std;

#ifndef PERSONA_H
#define PERSONA_H

class Persona {
 private:
  int codigo;
  string nombre;
  string apellido;
  string fechaNacimiento;
  string sexo;
  string numeroDocumento;
  string tipoDocumento;
  string estadoCivil;
  string nacionalidad;
  string email;
  ListaGenerica<Direccion>* direcciones;
  ListaGenerica<Telefono>* telefonos;

 public:
  Persona();
  ~Persona();
  void setCodigo(int);
  void setNombre(string);
  void setApellido(string);
  void setFechaNacimiento(string);
  void setSexo(string);
  void setNumeroDocumento(string);
  void setTipoDocumento(string);
  void setEstadoCivil(string);
  void setNacionalidad(string);
  void setEmail(string);
  void setDirecciones(ListaGenerica<Direccion> *);
  void setTelefonos(ListaGenerica<Telefono> *);

  string getNombre() { return nombre; };
  string getApellido() { return apellido; };
  string getFechaNacimiento() { return fechaNacimiento; };
  string getSexo() { return sexo; };
  string getNumeroDocumento() { return numeroDocumento; };
  string getTipoDocumento() { return tipoDocumento; };
  string getEstadoCivil() { return estadoCivil; };
  string getNacionalidad() { return nacionalidad; };
  string getEmail() { return email; };
  ListaGenerica<Direccion>* getDirecciones() { return direcciones; };
  ListaGenerica<Telefono>* getTelefonos() { return telefonos; }
  int getCodigo();

  Persona operator=(const Persona &persona) {
    this->nombre = persona.nombre;
    this->apellido = persona.apellido;
    this->fechaNacimiento = persona.fechaNacimiento;
    this->sexo = persona.sexo;
    this->numeroDocumento = persona.numeroDocumento;
    this->tipoDocumento = persona.tipoDocumento;
    this->estadoCivil = persona.estadoCivil;
    this->nacionalidad = persona.nacionalidad;
    this->email = persona.email;
    this->direcciones = persona.direcciones;
    this->telefonos = persona.telefonos;
    return *this;
  }
};
#endif