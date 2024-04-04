
#ifndef _SELECCION_
#define _SELECCION_

#include "staticSequence.h"

template <class Key>
void seleccionar(StaticSequence<Key>& sequence, int size){
  for(int i = 0; i < sequence.size() - 1; i++){
    int min = i;
    for(int j = i + 1; j < sequence.size(); j++){
      if (sequence.at(j) < sequence.at(min)){
        min = j;
      }
    }
    swap(sequence,min,i);
    //mostrar_v(sequence);
  }
}

template <class Key>
void seleccion(StaticSequence<Key>* sequence,int size){
  for(int i = 0; i < size - 1; i++){
    seleccionar(sequence, i);
    //mostrar_v(sequence);
  }
}

#endif