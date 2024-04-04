#ifndef _HEAPSORT_
#define _HEAPSORT_

#include "staticSequence.h"

template <class Key>
void baja(StaticSequence<Key>& sequence, int index, int size){

  while(2 * index <= size){
    int h1 = 2 * index;
    int h2 = h1+1;
    int h;

    if (h1 == size){ h = h1;
    } else if(sequence.at(h1 - 1) > sequence.at(h2 - 1)){ h = h1; }
    else { h = h2; }

    if(sequence.at(h - 1) <= sequence.at(index - 1)){
      break;
    }else{
      swap(sequence, index - 1, h - 1);
      index = h;
    }
    // mostrar_v(sequence);
  }
}

template <class Key>
void heapsort(StaticSequence<Key>* sequence, int size){
  for (int i = size / 2; i > 0; i--){
    baja(sequence, i, size - 1);
  }

  for (int i = size; i > 1; i--){
    swap(sequence, 1 - 1, i - 1);
    baja(sequence, 1, i - 1);
  }
}

#endif