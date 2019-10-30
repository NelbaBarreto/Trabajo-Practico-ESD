#include <string>
using namespace std;

#ifndef NODOPILA_H
#define NODOPILA_H

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

#endif 
