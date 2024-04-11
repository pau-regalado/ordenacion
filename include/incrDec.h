#ifndef _INCRDEC_
#define _INCRDEC_

#include "staticSequence.h"

template <class Key>
void sort(StaticSequence<Key>& sequence, int size, int delta, bool traceMode){
  Key x; 
  int j;
  
  if (traceMode) {
    std::cout << " delta = " << delta << std::endl;
  }
  for(int i = delta; i < size; i++){
    x = sequence[Position(i)];
    j = i;
    while ((j >= delta) && (x < sequence[Position(j - delta)])){  
      sequence[Position(j)] = sequence[Position(j - delta)];
      j = j - delta;
    }
    sequence[Position(j)] = x;
    if (traceMode) {
      mostrar_v(sequence);
    }
  }
}

template <class Key>
void incr_dec(StaticSequence<Key>& sequence, float alpha, int size, bool traceMode){
  int delta = size;
  while (delta > 1){
    delta = int(delta * alpha);
    if (delta < 1) {
      delta = 1;
    }
    sort(sequence, size, delta, traceMode);
  }
}

#endif