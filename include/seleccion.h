
#ifndef _SELECCION_
#define _SELECCION_

#include "staticSequence.h"

template <class Key>
void seleccionar(StaticSequence<Key>& sequence, int size, bool traceMode){
  for(int i = 0; i < size; i++){
    int min = i;
    for(int j = i + 1; j < size + 1; j++){
      if (sequence[Position(j)] < sequence[Position(min)]){
        min = j;
      }
    }
    swap(sequence,min,i);
  }
}

template <class Key>
void seleccion(StaticSequence<Key>& sequence, int size, bool traceMode){
  for(int i = 0; i < size + 1 ; i++){
    seleccionar(sequence, i, traceMode);
    if (traceMode) {
      mostrar_v(sequence);
    }
  }
}

#endif