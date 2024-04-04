#ifndef __SORTMETHOD__
#define __SORTMETHOD__

#include <iostream>
#include <vector>
#include <climits>
#include <chrono>

#include "commons.h"
#include "staticSequence.h"

template<class Key>
class SortMethod {
  protected:
    unsigned size;
    StaticSequence<Key> sequence;
    int timer_;

  public:
    SortMethod(StaticSequence<Key>& s, unsigned size): sequence(s), size(size) {}
    SortMethod(std::string filename);
    virtual void Sort() = 0;
    
    std::chrono::microseconds sort_time() {
      auto start = std::chrono::high_resolution_clock::now();
      Sort();
      auto stop  = std::chrono::high_resolution_clock::now();
      return std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    }

};

template<class Key>
SortMethod<Key>::SortMethod(std::string filename) {
  std::ifstream file("data/" + filename);
  if (!file.is_open()) {
    throw std::runtime_error("Error al abrir el archivo.");
  }
  std::string line;
  file >> line;
  this->sequence = StaticSequence<Key>(line.size());

  for (int i = 0; i < line.size(); ++i) {
    int value = line[i] - '0';
    this->sequence[Position(i)] = Key(value);
    std::cout << "GUARDE: " << value << std::endl;
  }
}    

#endif