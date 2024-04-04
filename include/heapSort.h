#ifndef _HEAPSORT_
#define _HEAPSORT_

#include "staticSequence.h"

template <class Key>
void baja(StaticSequence<Key>* vector, int index, int size){

  while(2 * index <= size){
    int h1 = 2 * index;
    int h2 = h1+1;
    int h;

    if (h1 == size){ h = h1;
    } else if(vector->at(h1 - 1) > vector->at(h2 - 1)){ h = h1; }
    else { h = h2; }

    if(vector->at(h - 1) <= vector->at(index - 1)){
      break;
    }else{
      swap(vector, index - 1, h - 1);
      index = h;
    }
    // mostrar_v(vector);
  }
}

template <class Key>
void heapsort(StaticSequence<Key>* vector, int size){
  for (int i = size / 2; i > 0; i--){
    baja(vector, i, size - 1);
  }

  for (int i = size; i > 1; i--){
    swap(vector, 1 - 1, i - 1);
    baja(vector, 1, i - 1);
  }
}

#endif