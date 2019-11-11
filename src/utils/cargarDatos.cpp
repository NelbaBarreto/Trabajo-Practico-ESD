#include <regex>

int COD_ID = 0;

Nodo *Lista::ObtenerNodo(Persona p) {
  Nodo *Newnode;
  Newnode = new Nodo;
  Newnode->dato = p;
  COD_ID++;
  setCantidad(COD_ID);
  Newnode->dato.setCodigo(COD_ID);
  Newnode->sig = Newnode->ant = NULL;
  return (Newnode);
}

void Lista::Agregar(Nodo *NewNode) {
  if (primero == NULL) {
    primero = NewNode;
    ultimo = NewNode;
    primero->ant = ultimo;
    ultimo->sig = primero;
  } else if (primero == ultimo) {
    if (primero->dato.getApellido() > NewNode->dato.getApellido()) {
      NewNode->sig = primero;
      primero->ant = NewNode;
      ultimo = primero;
      primero = NewNode;
    } else {
      primero->sig = NewNode;
      NewNode->ant = primero;
      NewNode->sig = primero;
      primero->ant = NewNode;
      ultimo = NewNode;
    }
  } else {
    Nodo *tmp;
    tmp = primero;
    do {
      if (NewNode->dato.getApellido() > tmp->dato.getApellido()) {
        tmp->ant->sig = NewNode;
        NewNode->sig = tmp;
        NewNode->ant = tmp->ant;
        tmp->ant = NewNode;
        break;
      }
      tmp = tmp->sig;
    } while (tmp->ant != ultimo);
    // ultimo->sig = NewNode;
    // NewNode->ant = ultimo;
    // NewNode->sig = primero;
    // ultimo = NewNode;
    // primero->ant = ultimo;
  }
  actual = NewNode;
}

void Lista::Crear(string const path) {
  string persona, aux;
  Nodo *NewNode;

  sregex_iterator i;
  ifstream arc(path);
  regex CLOSE_TAG("</Persona>");
  smatch m;

  while (getline(arc, persona)) {
    aux += persona + "\n";

    if (regex_search(persona, m, CLOSE_TAG)) {
      NewNode = ObtenerNodo(*cargaPersona(aux));
      Agregar(NewNode);
      aux = "";
    }
  }
  arc.close();
}

ListaGenerica<Direccion> *Lista::cargaDirecciones(string d) {
  ListaGenerica<Direccion> *direcciones = new ListaGenerica<Direccion>;
  istringstream arc(d);

  string dir_buff = "";
  string dir_found = "";

  bool ban_dir = false;

  while (getline(arc, dir_buff)) {
    if (dir_buff.find("<Direccion>") != std::string::npos) {
      ban_dir = true;
    }

    if (ban_dir) {
      dir_found += dir_buff + "\n";
    }

    if (dir_buff.find("</Direccion>") != std::string::npos) {
      direcciones->add(obtenerDireccion(dir_found));
      dir_found = "";
      ban_dir = false;
    }
  }

  return direcciones;
}

Direccion *Lista::obtenerDireccion(string p) {
  Direccion *direccion = new Direccion;
  istringstream arc(p);
  string persona;
  sregex_iterator i;
  regex rp_valor("<(\\w*)>(.*)</.*>");

  while (getline(arc, persona)) {
    for (i = sregex_iterator(persona.begin(), persona.end(), rp_valor);
         i != std::sregex_iterator(); ++i) {
      smatch m = *i;

      string etiqueta = m[1];
      string valor = m[2];

      if (etiqueta == "Ciudad") {
        direccion->setCiudad(valor);
      } else if (etiqueta == "Calle") {
        direccion->setCalle(valor);
      } else if (etiqueta == "Numero") {
        direccion->setNumero(valor);
      } else if (etiqueta == "E_P_N") {
        direccion->setEpn(valor);
      } else if (etiqueta == "Pais") {
        direccion->setPais(valor);
      } else if (etiqueta == "Region") {
        direccion->setRegion(valor);
      } else {
        cout << "Propiedad de Direccion no válida. Verifique el xml.";
        exit(1);
      }
    }
  }

  return direccion;
}
ListaGenerica<Telefono> *Lista::cargaTelefonos(string t) {
  ListaGenerica<Telefono> *telefonos = new ListaGenerica<Telefono>;
  istringstream arc(t);

  string tel_buff = "";
  string tel_found = "";

  bool ban_tel = false;

  while (getline(arc, tel_buff)) {
    if (tel_buff.find("<Telefono>") != std::string::npos) {
      ban_tel = true;
    }

    if (ban_tel) {
      tel_found += tel_buff + "\n";
    }

    if (tel_buff.find("</Telefono>") != std::string::npos) {
      telefonos->add(obtenerTelefono(tel_found));
      tel_found = "";
      ban_tel = false;
    }
  }

  return telefonos;
}

Telefono *Lista::obtenerTelefono(string t) {
  Telefono *telefono = new Telefono;
  istringstream arc(t);
  string direccion;
  sregex_iterator i;
  while (getline(arc, direccion)) {
    regex rp_valor("<(\\w*)>(.*)</.*>");
    for (i = sregex_iterator(direccion.begin(), direccion.end(), rp_valor);
         i != std::sregex_iterator(); ++i) {
      smatch m = *i;

      string etiqueta = m[1];
      string valor = m[2];

      if (etiqueta == "Tipo") {
        telefono->setTipo(valor);
      } else if (etiqueta == "Numero") {
        telefono->setNumero(valor);
      } else if (etiqueta == "Interno") {
        telefono->setInterno(valor);
      }
    }
  }

  return telefono;
}

Persona *Lista::cargaPersona(string p) {
  Persona *persona = new Persona;

  Direccion *direccion;
  Telefono *telefono;
  istringstream arc(p);
  string agenda;
  sregex_iterator i;

  persona->setTelefonos(cargaTelefonos(p));
  persona->setDirecciones(cargaDirecciones(p));

  while (getline(arc, agenda)) {
    regex rp_valor("<(\\w*)>(.*)</.*>");
    for (i = sregex_iterator(agenda.begin(), agenda.end(), rp_valor);
         i != std::sregex_iterator(); ++i) {
      smatch m = *i;

      string etiqueta = m[1];
      string valor = m[2];
      if (etiqueta == "Nombres") {
        persona->setNombre(valor);
      } else if (etiqueta == "Apellidos") {
        persona->setApellido(valor);
      } else if (etiqueta == "FechaNacimiento") {
        persona->setFechaNacimiento(valor);
      } else if (etiqueta == "Sexo") {
        persona->setSexo(valor == "1" ? "FEMENINO" : "MASCULINO");
      } else if (etiqueta == "NumeroDocumento") {
        persona->setNumeroDocumento(valor);
      } else if (etiqueta == "TipoDocumento") {
        if (valor == "1")
          persona->setTipoDocumento("CI");
        else if (valor == "2")
          persona->setTipoDocumento("RUC");
        else
          persona->setTipoDocumento("Otro");
      } else if (etiqueta == "EstadoCivil") {
        if (valor == "1")
          persona->setEstadoCivil("Soltero/a");
        else if (valor == "2")
          persona->setEstadoCivil("Casado/a");
        else if (valor == "3")
          persona->setEstadoCivil("Viudo/a");
        else if (valor == "4")
          persona->setEstadoCivil("Divorciado/a");
        else if (valor == "5")
          persona->setEstadoCivil("Divorciado/a");
      } else if (etiqueta == "Nacionalidad") {
        persona->setNacionalidad(valor);
      } else if (etiqueta == "Email") {
        persona->setEmail(valor);
      }
    }
  }
  return persona;
}

void Lista::AlmacenarDatos() {
  Nodo *nuevo = new Nodo();
  // nuevo->dato = ;
  if (primero == NULL) {
    primero = nuevo;
    primero->sig = NULL;
    primero->ant = NULL;
    ultimo->primero;
  } else {
    ultimo->sig = nuevo;
    nuevo->sig = NULL;
    nuevo->ant = ultimo;
    ultimo = nuevo;
  }
}
