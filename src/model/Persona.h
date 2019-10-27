#include <string>
using namespace std;

class Persona {
 private:
  string nombre;
  string apellido;
  string fechaNacimiento;
  bool sexo;
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
  void setSexo(bool);
  void setNumeroDocumento(string);
  void setTipoDocumento(string);
  void setEstadoCivil(string);
  void setNacionalidad(string);
  void setEmail(string);
  // void setDirecciones(Lista direcciones);
  // void setTelefonos(Lista telefonos);
  string getNombre() { return nombre; };
};
