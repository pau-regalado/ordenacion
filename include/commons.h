#ifndef _METODOS_
#define _METODOS_

#include <iostream>
#include <vector>
#include <climits>

#include "position.h"
#include "staticSequence.h"

template <class Key>
void mostrar_v(StaticSequence<Key>& sequence){
  std::cout << "< ";
  for (int i = 0; i < sequence.getSize(); ++i)
    std::cout << sequence[Position(i)] << " ";
  std::cout << ">" << std::endl;
}

template <class Key>
void swap(StaticSequence<Key>& sequence, int x, int y){
  Key aux = sequence[Position(x)];
  sequence[Position(x)] = sequence[Position(y)];
  sequence[Position(y)] = aux; 
}

#endif