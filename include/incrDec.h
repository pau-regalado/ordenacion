#ifndef _INCRDEC_
#define _INCRDEC_

#include "staticSequence.h"

template <class Key>
void sort(StaticSequence<Key>& sequence, int delta, int size){
  Key x; 
  int j;
  //std::cout << " delta = " << delta << std::endl;
  for(int i = delta; i < size; i++){
    x = sequence.at(i);
    j = i;
    while ((j >= delta) && (x < sequence.at(j - delta))){  
      sequence.at(j) = sequence.at(j - delta);
      j = j - delta;
    }
    sequence.at(j) = x;
    //mostrar_v(sequence);
  }
}

template <class Key>
void incr_dec(StaticSequence<Key>* sequence, float alpha, int size){
  int delta = size;
  while(delta > 1){
    delta = int(delta * alpha);
    if (delta < 1) {
      delta = 1;
    }
    sort(sequence, delta, size);
  }
}

#endif