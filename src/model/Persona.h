#include <string>
using namespace std;

class Persona {
 private:
  static int codigo;
  string nombre;
  string apellido;
  string fechaNacimiento;
  string sexo;
  string numeroDocumento;
  string tipoDocumento;
  string estadoCivil;
  string nacionalidad;
  string email;
  // Lista direcciones;
  // Lista telefonos;
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
  // void setDirecciones(Lista direcciones);
  // void setTelefonos(Lista telefonos);
  string getNombre() { return nombre; };
  string getApellido() { return apellido; };
  string getFechaNacimiento() { return fechaNacimiento; };
  string getSexo() { return sexo; };
  string getNumeroDocumento() { return numeroDocumento; };
  string getTipoDocumento() { return tipoDocumento; };
  string getEstadoCivil() { return estadoCivil; };
  string getNacionalidad() { return nacionalidad; };
  string getEmail() { return email; };
  static int getCodigo(); 
};


