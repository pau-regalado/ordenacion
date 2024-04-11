#ifndef __STATIC_SEQUENCE__
#define __STATIC_SEQUENCE__

#include <vector>
#include <iostream>
#include <random>
#include "sequence.h"
 
template <class Key>
class StaticSequence: public Sequence<Key>{

  public:
    StaticSequence(const int size = 0) {
      this->size = size;
      this->self.resize(size);     
    }

    StaticSequence(std::string filename) {
      std::ifstream file("data/" + filename);
      if (!file.is_open()) {
        throw std::runtime_error("Error al abrir el archivo.");
      }
      
      std::string line;
      file >> line;
      this->size = line.size();
      this->self.resize(line.size()); 
      for (int i = 0; i < line.size(); ++i) {
        self[i] = line[i] - '0';
      } 
    }

    ~StaticSequence(void) {}

    Key& operator[](const Position& p) {
      return self[p.getX()];
    }

    void randomInitializing() {
      const int MAX_INT = 99999999;
      const int MIN_INT = 0;
      std::random_device rd;
      std::mt19937 gen(rd());
      std::uniform_int_distribution<int> dis(MIN_INT, MAX_INT);
      for (int i = 0; i < this->size; i++) {
        self[i] = Key(dis(gen)); // Para trabajar con nifs poner solo Key() para llamar a su constrructor aleatorio
      }
    }

    void manualInitializing() {
      std::cout << "Manually initializing the sequence" << std::endl;
      int value;
      for (int i = 0; i < this->size; i++) {
        std::cout << "Enter " << i << " element> ";
        std::cin >> value;
        self[i] = Key(value);
      }
    }

    unsigned getSize() {
      return size;
    }

  private:
    int size;
    std::vector<Key> self;
};

#endif