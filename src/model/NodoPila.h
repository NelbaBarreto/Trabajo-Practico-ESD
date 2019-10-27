#include <string>
using namespace std;

class NodoPila {
 public:
  NodoPila() {
    data = " ";
    next = NULL;
  };
  ~NodoPila(){};
  string data;
  NodoPila *next;
};
