int COD_ID = 0;

Nodo *Lista::ObtenerNodo(string aux) {
  Nodo *Newnode;
  ifstream archivo;
  Newnode = new Nodo;
  Newnode->dato = *cargaPersona(aux);
  COD_ID++;
  Newnode->dato.setCodigo(COD_ID);
  Newnode->sig = Newnode->ant = NULL;
  return (Newnode);
}

void Lista::Agregar(Nodo *NewNode) {
  if (primero == NULL) {
    primero = NewNode;
    ultimo = NewNode;
  } else {
    ultimo->sig = NewNode;
    NewNode->ant = ultimo;
    NewNode->sig = primero;
    ultimo = NewNode;
  }
  // Ordenar();
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
      NewNode = ObtenerNodo(aux);
      Agregar(NewNode);
      aux = "";
    }
  }
  arc.close();
}
Direccion *Lista::cargaDireccion(string p) {
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

  string dir_buff = "";
  string dir_found = "";

  bool ban_dir = false;

  while (getline(arc, dir_buff)) {
    if (dir_buff.find("<Telefono")) {
      ban_dir = true;
    }

    if (ban_dir) {
      dir_found += dir_buff + "\n";
    }

    if (dir_buff.find("</Telefono>") != std::string::npos) {
      telefonos->add(obtenerTelefono(dir_found));
      dir_found = "";
      ban_dir = false;
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

  while (getline(arc, agenda)) {
    regex rp_valor("<(\\w*)>(.*</.*>)?");
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
        persona->setSexo(valor == "1" ? "F" : valor == "2" ? "M" : "Queer");
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
      } else if (etiqueta == "Direcciones") {
        // persona->setDirecciones(cargaDirecciones(p));
      } else if (etiqueta == "Telefonos") {
        persona->setTelefonos(cargaTelefonos(p));
      }
    }
  }

  mostrarTelefonos(persona->getTelefonos());

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
