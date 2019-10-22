#include<string>

class Persona {
 private:
  string nombre;
  string apeelido;
  string fechaNacimiento;
  bool sexo;
  string nroDocumento;
  short tipoDocumento;
  short estadoCivil;
  string nacionalidad;
  string email;
  List<Direccion> direcciones;
 public:
  Persona();
  ~Persona();
};

Persona::Persona() {}

Persona::~Persona() {}
