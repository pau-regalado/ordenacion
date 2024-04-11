#ifndef __RADIXSORT__
#define _RADIXSORT_

#include <math.h>
#include "staticSequence.h"

const int kDigits = 4;

template <class Key>
void radixSort(StaticSequence<Key>& sequence, int size, bool traceMode){
  for (int i = 0; i < kDigits; i++) {
    std::vector<std::vector<int>> cubetas;
    cubetas.resize(15);
    
    for (int j = 0; j < size; j++) {
      cubetas[(long(sequence[j]) / int(pow(10, i))) % 10].push_back(sequence[j]);
    }
    int index = 0;
    for (int k = 0; k <cubetas.size(); k++) {
      for (int l = 0; l < cubetas[k].size(); l++) {
        sequence[index++] = Key(cubetas[k][l]);
      }
    }
    if (traceMode) {
      mostrar_v(sequence);
    }
  }
}
#endif