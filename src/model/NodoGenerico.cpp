#include <string>
using namespace std;

template <class T>
class NodoGenerico {
 public:
  T data;
  NodoGenerico<T> *next;
};
