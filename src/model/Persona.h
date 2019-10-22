#include <string>
using namespace std;

class Persona {
 private:
  string nombre;
  string apellido;
  string fechaNacimiento;
  bool sexo;
  string nroDocumento;
  short tipoDocumento;
  short estadoCivil;
  string nacionalidad;
  string email;
  //List<Direccion> direcciones;
  string correoElectronico;
  //List<Telefono> telefonos;
 public:
  Persona();
  ~Persona();
};

Persona::Persona() {}

Persona::~Persona() {}
