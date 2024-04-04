#ifndef _INCRDEC_
#define _INCRDEC_

#include "staticSequence.h"

template <class Key>
void sort(StaticSequence<Key>* vector, int delta, int size){
  Key x; 
  int j;
  //std::cout << " delta = " << delta << std::endl;
  for(int i = delta; i < size; i++){
    x = vector->at(i);
    j = i;
    while ((j >= delta) && (x < vector->at(j - delta))){  
      vector->at(j) = vector->at(j - delta);
      j = j - delta;
    }
    vector->at(j) = x;
    //mostrar_v(vector);
  }
}

template <class Key>
void incr_dec(StaticSequence<Key>* vector, float alpha, int size){
  int delta = size;
  while(delta > 1){
    delta = int(delta * alpha);
    if (delta < 1) {
      delta = 1;
    }
    sort(vector, delta, size);
  }
}

#endif