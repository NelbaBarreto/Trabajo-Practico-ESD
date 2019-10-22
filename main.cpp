#include <iostream>
#include <fstream>
#include <regex>
using namespace std;

class Nodo {
 public:
  Nodo();
  ~Nodo(){};
  char data;
  Nodo *next;
};

Nodo::Nodo() {
  data = ' ';
  next = NULL;
}

class Pila {
 public:
  Pila() { top = NULL; }
  ~Pila();
  Nodo *top;
  void push(char);
  char pop();
  char getTop();
  bool isEmpty();
  int isBalanced(string);
};

Pila::~Pila() {
  Nodo *path = top;
  Nodo *del;
  while (path != NULL) {
    del = path;
    path = path->next;
    delete del;
  }
}

void Pila::push(char e) {
  Nodo *nuevo = new Nodo;
  nuevo->data = e;
  nuevo->next = NULL;
  if (top == NULL) {
    top = nuevo;
  } else {
    nuevo->next = top;
    top = nuevo;
  }
}

char Pila::pop() {
  char temp = getTop();
  Nodo *p = top->next;
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

char Pila::getTop() {
  if (top != NULL) {
    return top->data;
  }
  return ' ';
}

int Pila::isBalanced(string expresion) {
  int i = 0;
  char caracter = ' ';
  for (i = 0; i < expresion.size(); i++) {
    caracter = expresion[i];
    if (/*etiqueta de apertura*/) {
      push(caracter);
    }
    
    if /*es la expresion para cerrar*/ {
      if (!isEmpty() && getTop() == /*la etiqueta actual*/) {
        pop();
      } else {
        return 0;
      }
    }
  }

  if(isEmpty()) return 1;
}


int main() {
  string Agenda;
  ifstream archivo;

  archivo.open("res/agenda.xml");
  if(!archivo) {
    cout << "Error, no se pudo abrir el archivo.";
    exit(1);
  }

  while(archivo >> Agenda) {
    cout << Agenda;
  }

  archivo.close();
  return 0;
}