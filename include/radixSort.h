#ifndef __RADIXSORT__
#define _RADIXSORT_

#include <math.h>
#include "staticSequence.h"

const int kDigits = 4;

template <class Key>
void radixSort(StaticSequence<Key>& sequence, int size){
  for (int i = 0; i < kDigits; i++) {
    std::vector<std::vector<int>> cubetas;
    cubetas.resize(10);
    
    for (int j = 0; j < size; j++) {
      cubetas[(sequence.at(j) / int(pow(10, i))) % 10].push_back(sequence.at(j));
    }
    int index = 0;
    for (int k = 0; k <cubetas.size(); k++) {
      for (int l = 0; l < cubetas[k].size(); l++) {
        sequence.at(index++) = cubetas[k][l];
      }
    }
    //mostrar_v(sequence);
  }
}
#endif