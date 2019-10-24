#include <fstream>
#include <iostream>
#include <regex>
using namespace std;
using namespace std;

class Nodo {
 public:
  Nodo();
  ~Nodo(){};
  string dato;
  Nodo *siguiente;
  Nodo *atras;
}*primero,*ultimo;

Nodo::Nodo() {
  dato = ' ';
  siguiente = NULL;
}

class Pila {
 public:
  Pila() { top = NULL; }
  ~Pila();
  Nodo *top;
  void push(string);
  string pop();
  string getTop();
  bool isEmpty();
  int isBalanced();
};

Pila::~Pila() {
  Nodo *path = top;
  Nodo *del;
  while (path != NULL) {
    del = path;
    path = path->siguiente;
    delete del;
  }
}

void Pila::push(string e) {
  Nodo *nuevo = new Nodo;
  nuevo->dato = e;
  nuevo->siguiente = NULL;
  if (top == NULL) {
    top = nuevo;
  } else {
    nuevo->siguiente = top;
    top = nuevo;
  }
}

string Pila::pop() {
  string temp = getTop();
  Nodo *p = top->siguiente;
  if (top != NULL) {
    delete top;
    top = p;
  }

  return temp;
}

bool Pila::isEmpty() {
  if (top != NULL) {
    return false;
  }

  return true;
}

string Pila::getTop() {
  if (top != NULL) {
    return top->dato;
  }
  return " ";
}

int Pila::isBalanced() {
  int i = 0;
  while (i) {
    if (i) {
      if (!isEmpty() && getTop() == "") {
        pop();
      } else {
        return 0;
      }
    }
  }

  if (isEmpty()) return 1;
}

int main() {
  Pila p;
  string agenda, etiqueta;
  sregex_iterator i;
  ifstream archivo;

  archivo.open("res/agenda.xml");
  if (!archivo) {
    cout << "Error, no se pudo abrir el archivo.";
    exit(1);
  }

  while (getline(archivo, agenda)) {
    regex r("<[/]?\\w*?>");
    regex rp("<\\w*>");
    smatch m = *i;
    etiqueta = m.str();
    if (regex_match(etiqueta, rp)) {
      p.push(etiqueta);
    } else {
      if (p.getTop == "texto de etiqueta") {
        /* code */
      }
    }
  }
  
  archivo.close();
  return 0;
}


