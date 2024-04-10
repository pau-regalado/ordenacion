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
    virtual void Sort() = 0;
    
    std::chrono::microseconds sort_time() {
      auto start = std::chrono::high_resolution_clock::now();
      Sort();
      auto stop  = std::chrono::high_resolution_clock::now();
      return std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    }
};   

#endif