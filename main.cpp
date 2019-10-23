#include <fstream>
#include <iostream>
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

// int Pila::isBalanced(string x) {
//   int i = 0;
//    regex r("<\\s+>");
//     for(sregex_iterator i =sregex_iterator(s.begin(), s.end(), r);
//                             i !=sregex_iterator();
//                             ++i )
//     {
//        smatch m = *i;
//        cout << m.str() << " at position " << m.position() << '\n';
//     }

//   char caracter = ' ';
//   for (i = 0; i < x.size(); i++) {
//     caracter = x[i];
//     if (/*etiqueta de apertura*/) {
//       push(caracter);
//     }

//     if /*es la x para cerrar*/ {
//       if (!isEmpty() && getTop() == /*la etiqueta actual*/) {
//         pop();
//       } else {
//         return 0;
//       }
//     }
//   }

//   if(isEmpty()) return 1;
// }

int main() {
  string agenda, etiquetas;
  sregex_iterator i;
  ifstream archivo;

  archivo.open("res/agenda.xml");
  if (!archivo) {
    cout << "Error, no se pudo abrir el archivo.";
    exit(1);
  }

  while (getline(archivo, agenda)) {
    regex r("<[a-zA-Z_]*?>");

    for (i = sregex_iterator(agenda.begin(), agenda.end(), r); i != sregex_iterator(); ++i) {
      smatch m = *i;
      etiquetas = m.str();
    }
  }

  archivo.close();

  return 0;
}