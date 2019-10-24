#include <string>
using namespace std;
class Nodo {
 public:
  Nodo();
  ~Nodo(){};
  string data;
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
    path = path->next;
    delete del;
  }
}

void Pila::push(string e) {
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

string Pila::pop() {
  string temp = getTop();
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

string Pila::getTop() {
  if (top != NULL) {
    return top->data;
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
