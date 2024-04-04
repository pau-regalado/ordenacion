#ifndef __STATIC_SEQUENCE__
#define __STATIC_SEQUENCE__

#include <vector>
#include <iostream>
#include "sequence.h"
 
template <class Key>
class StaticSequence: public Sequence<Key>{

  public:
    StaticSequence(const int size = 0) {
      this->size = size;
      this->self.resize(size);
    }

    ~StaticSequence(void) {}

    Key& operator[](const Position& p) {
      return self[p.getX()];
    }

    void randomInitializing() {
      for (int i = 0; i < this->size; i++) {
        self[i] = Key(std::rand());
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