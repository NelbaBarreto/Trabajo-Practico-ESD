#include "ListaGenerica.cpp"
#include "Direccion.cpp"
#include "Telefono.cpp"

#include <string>
using namespace std;

class Persona {
 private:
  static int COD_ID;

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
  ListaGenerica<Direccion> direcciones;
  ListaGenerica<Telefono> telefonos;
 public:
  Persona();
  ~Persona();
  void setNombre(string);
  void setApellido(string);
  void setFechaNacimiento(string);
  void setSexo(string);
  void setNumeroDocumento(string);
  void setTipoDocumento(string);
  void setEstadoCivil(string);
  void setNacionalidad(string);
  void setEmail(string);
  void setDirecciones(ListaGenerica<Direccion> direcciones);
  void setTelefonos(ListaGenerica<Telefono> telefonos);
  
  string getNombre() { return nombre; };
  string getApellido() { return apellido; };
  string getFechaNacimiento() { return fechaNacimiento; };
  string getSexo() { return sexo; };
  string getNumeroDocumento() { return numeroDocumento; };
  string getTipoDocumento() { return tipoDocumento; };
  string getEstadoCivil() { return estadoCivil; };
  string getNacionalidad() { return nacionalidad; };
  string getEmail() { return email; };
  ListaGenerica<Direccion> getDirecciones(){return direcciones;}
  ListaGenerica<Telefono> getTelefonos(){return telefonos;}
  int getCodigo(); 
};


