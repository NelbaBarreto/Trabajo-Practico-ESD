#include <iostream>
#include <fstream>
using namespace std;

int main() {
  string Agenda;
  ifstream archivo;

  archivo.open("res/agenda.xml");
  if(!archivo) {
    cout << "Error";
    exit(1);
  }

  while(archivo >> Agenda) {
    cout << Agenda;
  }

  archivo.close();
  return 0;
}