#include "Lista.h"
#include <iostream>
#include "../utils/funciones.cpp"
#include "./Direccion.cpp"
#include "./ListaGenerica.cpp"
#include "./Persona.cpp"
#include "./Telefono.cpp"
#include "../utils/cargarDatos.cpp"
using namespace std;

Lista::Lista() { primero = ultimo = sig = ant = NULL; }

Lista::~Lista() {}

/* -------- Navegacion -------- */
void Lista::Siguiente() {
  actual = actual->sig;
<<<<<<< HEAD
<<<<<<< HEAD
  cout << actual->dato.getNombre() << endl;
  cout << actual->dato.getApellido() << endl;
  cout << actual->dato.getFechaNacimiento() << endl;
  cout << actual->dato.getSexo() << endl;
  cout << actual->dato.getNumeroDocumento() << endl;
  cout << actual->dato.getTipoDocumento() << endl;
  cout << actual->dato.getEstadoCivil() << endl;
  cout << actual->dato.getNacionalidad() << endl;
  cout << actual->dato.getEmail() << endl;
=======
  mostrarPersona();
>>>>>>> b4cdcbcd73a2481448fe2950678d67c2d05fed7d
=======
  mostrarPersona();
>>>>>>> b4cdcbcd73a2481448fe2950678d67c2d05fed7d
  system("pause");
}

void Lista::Anterior() {
  actual = actual->ant;
<<<<<<< HEAD
<<<<<<< HEAD
  cout << actual->dato.getNombre() << endl;
  cout << actual->dato.getApellido() << endl;
  cout << actual->dato.getFechaNacimiento() << endl;
  cout << actual->dato.getSexo() << endl;
  cout << actual->dato.getNumeroDocumento() << endl;
  cout << actual->dato.getTipoDocumento() << endl;
  cout << actual->dato.getEstadoCivil() << endl;
  cout << actual->dato.getNacionalidad() << endl;
  cout << actual->dato.getEmail() << endl;
=======
  mostrarPersona();
>>>>>>> b4cdcbcd73a2481448fe2950678d67c2d05fed7d
=======
  mostrarPersona();
>>>>>>> b4cdcbcd73a2481448fe2950678d67c2d05fed7d
  system("pause");
}

void Lista::Primero() {
  actual = primero;
<<<<<<< HEAD
<<<<<<< HEAD
  cout << actual->dato.getNombre() << endl;
  cout << actual->dato.getApellido() << endl;
  cout << actual->dato.getFechaNacimiento() << endl;
  cout << actual->dato.getSexo() << endl;
  cout << actual->dato.getNumeroDocumento() << endl;
  cout << actual->dato.getTipoDocumento() << endl;
  cout << actual->dato.getEstadoCivil() << endl;
  cout << actual->dato.getNacionalidad() << endl;
  cout << actual->dato.getEmail() << endl;
=======
  mostrarPersona();
>>>>>>> b4cdcbcd73a2481448fe2950678d67c2d05fed7d
=======
  mostrarPersona();
>>>>>>> b4cdcbcd73a2481448fe2950678d67c2d05fed7d
  system("pause");
}

void Lista::Ultimo() {
  actual = ultimo;
<<<<<<< HEAD
<<<<<<< HEAD
  cout << actual->dato.getNombre() << endl;
  cout << actual->dato.getApellido() << endl;
  cout << actual->dato.getFechaNacimiento() << endl;
  cout << actual->dato.getSexo() << endl;
  cout << actual->dato.getNumeroDocumento() << endl;
  cout << actual->dato.getTipoDocumento() << endl;
  cout << actual->dato.getEstadoCivil() << endl;
  cout << actual->dato.getNacionalidad() << endl;
  cout << actual->dato.getEmail() << endl;
=======
  mostrarPersona();
>>>>>>> b4cdcbcd73a2481448fe2950678d67c2d05fed7d
=======
  mostrarPersona();
>>>>>>> b4cdcbcd73a2481448fe2950678d67c2d05fed7d
  system("pause");
}

/* -------- Operaciones -------- */
void Lista::Insertar() { 
  cout << "INSERTAR" << endl; 
<<<<<<< HEAD
}

<<<<<<< HEAD
void Lista::Insertar() { 
  cout << "INSERTAR" << endl; 
  Nodo* nuevo = new Nodo();
	int COMPARADOR = 0;
	int BAND = 0;
	string nombre,apellido,sexo,estadocivil,nacionalidad,email,sexo;
	int birthday,CI,sex,estadovicil;
	do{
		if(nuevo->dato.getCodigo() == COMPARADADOR ){
			COMPARADOR ++ ;
		}else{
			cout <<"Ingrese su nombre"<<endl;
			cin >> nombre;
			nuevo->dato.setNombre(nombre);
			cout <<"Ingrese su apellido"<<endl;
			cin >> apellido;
			nuevo->dato.setApellido(apellido);
			cout <<"Ingrese su fecha de nacimiento"<<endl;
			cin >> birthday;
			nuevo->dato.setFechaNacimiento(birthday);
			cout <<"Ingrese su sexo"<<endl;
			cin >> sexo;
				if(mayuscula(sexo) == "FEMENINO"){
					sex = 1;
				}else{
					sex = 2;
				}
			nuevo->dato.setSexo(sex);
			cout <<"Ingrese su numero de documento"<<endl;
			cin >> CI;
			nuevo->dato.setNumeroDocumento(CI);
			cout <<"Ingrese su estado civil"<<endl;
			cin >> estadocivil;
				if(mayuscula(estadocivil) == "CASADO" || mayuscula(estadocivil) == "CASADA"){
					estadovicil = 1;
				}else{
					estadovicil = 2;
				}
			nuevo->dato.setEstadoCivil(estadovicil);
			cout <<"Ingrese su nacionalidad"<<endl;
			cin >> nacionalidad;
			nuevo->dato.setNacionalidad(nacionalidad);
			cout <<"Ingrese su email"<<endl;
			cin >> email;
			nuevo->dato.setEmail(email);
				if(primero==NULL){
					primero = nuevo;
					ultimo = nuevo;
					primero->sig = primero;
					primero->ant = ultimo;
				}else{
					ultimo->sig = nuevo;
					nuevo->ant = ultimo;
					nuevo->sig = primero;
					ultimo = nuevo;
					primero->ant = ultimo;
				}
		BAND = 1;
		}
	}while(BAND != 0);
}

=======
>>>>>>> b4cdcbcd73a2481448fe2950678d67c2d05fed7d
=======
}

>>>>>>> b4cdcbcd73a2481448fe2950678d67c2d05fed7d
void Lista::Borrar() {
  cout << "BORRAR" << endl;
  actual = primero;
  bool encontrado = false;
  int CodigoBuscado = 0;
  cout << "Ingrese el código de la persona que desea eliminar: ";
  cin >> CodigoBuscado;
  if (primero != NULL) {
    do {
      if (actual->dato.getCodigo() == CodigoBuscado) {
        cout << "\nPersona encontrada";

        if (actual == primero) {
          primero->ant = ultimo;
          ultimo->sig = primero;
          primero = primero->sig;
        } else if (actual == ultimo) {
          ultimo = ant;
          ultimo->sig = primero;
          primero->ant = ultimo;
        } else {
          ant->sig = actual->sig;
          actual->ant->sig = actual->sig;
        }
        cout << "\n Persona eliminada\n\n";
        encontrado = true;
      }
      ant = actual;
      actual = actual->sig;
    } while (actual != primero && encontrado != true);

    if (!encontrado) {
      cout << "\n Persona no encontrada\n\n";
    }

  } else {
    cout << "\n La lista se Encuentra Vacia\n\n";
  }
  system("pause");
}

void Lista::Modificar() {
  cout << "MODIFICAR" << endl;
  Nodo *actual = new Nodo();
  actual = primero;
  bool encontrado = false;
  int IDBuscado;
  string buscar, pasar;
  cout << " Ingrese el id de la persona a Buscar para Modificar: ";
  cin >> IDBuscado;
  if (primero != NULL) {
    do {
      if (actual->dato.getCodigo() == IDBuscado) {
        cout << "\n Persona encontrada";
        cout << "\n Ingrese el tipo de dato que desea modificar ";
        cin >> buscar;
        if ("nombre" == buscar) {
          cin >> pasar;
          actual->dato.setNombre(mayuscula(pasar));
        } else if ("apellido" == buscar) {
          cin >> pasar;
          actual->dato.setApellido(mayuscula(pasar));
          // Ordenar();
        } else if ("fechanacimiento" == buscar) {
          cin >> pasar;
          actual->dato.setFechaNacimiento(mayuscula(pasar));
        } else if ("sexo" == buscar) {
          cin >> pasar;
          actual->dato.setSexo(mayuscula(pasar));
        } else if ("numerodocumento" == buscar) {
          cin >> pasar;
          actual->dato.setNumeroDocumento(mayuscula(pasar));
        } else if ("tipodocumento" == buscar) {
          cin >> pasar;
          actual->dato.setTipoDocumento(mayuscula(pasar));
        } else if ("estadocivil" == buscar) {
          cin >> pasar;
          actual->dato.setEstadoCivil(mayuscula(pasar));
        } else if ("nacionalidad" == buscar) {
          cin >> pasar;
          actual->dato.setNacionalidad(mayuscula(pasar));
        } else if ("email" == buscar) {
          cin >> pasar;
          actual->dato.setEmail(mayuscula(pasar));
          // }else if("direcciones" == buscar){
          //       cin >>pasar;
          //       actual->dato.setDirecciones(pasar);
          // }else if("telefonos" == buscar){
          //       cin >>pasar;
          //       actual->dato.setTelefonos(pasar);
        }
        cout << "\n Dato modificado\n\n";
        encontrado = true;
      }
      actual = actual->sig;
    } while (actual != primero && encontrado != true);
    if (!encontrado) {
      cout << "\n Dato no encontrado\n\n";
    }
  } else {
    cout << "\n La lista se Encuentra Vacia\n\n";
  }
  system("pause");
}

void Lista::Consultar() {
  actual = primero;
  int cod = 0;
  bool ban = false;

  cout << "Ingrese el código de la persona a buscar: ";
  cin >> cod;

  while (actual != NULL) {
    if (actual->dato.getCodigo() == cod) {
      ban = true;
      mostrarPersona();
      system("pause");
      break;
    }
    actual = actual->sig;
    actual = actual->sig;
  }
  if (!ban) cout << "No existe ninguna persona con ese código";
}
