#ifndef __RADIXSORT__
#define _RADIXSORT_

#include "staticSequence.h"

template <class Key>
void radixSort(StaticSequence<Key>* vector, int size){
  for (int i = 0; i < kDigits; i++) {
    std::vector<std::vector<int>> cubetas;
    cubetas.resize(10);
    
    for (int j = 0; j < size; j++) {
      cubetas[(vector->at(j) / int(pow(10, i))) % 10].push_back(vector->at(j));
    }
    int index = 0;
    for (int k = 0; k <cubetas.size(); k++) {
      for (int l = 0; l < cubetas[k].size(); l++) {
        vector->at(index++) = cubetas[k][l];
      }
    }
    //mostrar_v(vector);
  }
}
#endif