#include <iostream>  
#include <string>    
using namespace std;

string mayuscula(string cadena) {
  char c = cadena[0];
  string res(1, toupper(c));
  return res;
}
