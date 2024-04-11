#ifndef _HEAPSORT_
#define _HEAPSORT_

#include "staticSequence.h"

template <class Key>
void baja(StaticSequence<Key>& sequence, int index, int size, bool traceMode){

  int h = index;
  int h1 = 2 * index + 1;
  int h2 = h1 + 1;

  if (h1 < size && sequence[Position(h1)] > sequence[Position(h)]) {
    h = h1;
  }
  
  if (h2 < size && sequence[Position(h2)] > sequence[Position(h)]) {
    h = h2;
  }

  if (h != index) {
    swap(sequence, index, h);
    if (traceMode) {
      mostrar_v(sequence);
    }
    baja(sequence, h, size, traceMode);
  }
}

template <class Key>
void heapsort(StaticSequence<Key>& sequence, int size, bool traceMode){
  for (int i = size / 2; i >= 0; i--){
    baja(sequence, i, size, traceMode);
  }

  for (int i = size - 1; i >= 0; i--){
    swap(sequence, 0, i);
    baja(sequence, 0, i, traceMode);
  }
}

#endif