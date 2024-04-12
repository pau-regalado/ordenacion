#ifndef __QUICKSORT__
#define __QUICKSORT__

#include "staticSequence.h"

template <typename Key>
void quicksort(StaticSequence<Key>& sequence, unsigned ini, unsigned fin, bool traceMode, int contador = 0){
  int i = ini, f = fin;
  long pivote = long(sequence[Position((i+f)/2)]);
  std::cout << "Pivote: " << pivote << std::endl;

  while (i <= f){ 
    while (long(sequence[Position(i)]) < pivote){ i++;}
    while (long(sequence[Position(f)]) > pivote){ f--;}
    int contador = 0;
    
    if (i <= f) {
      swap(sequence,i,f);
      std::cout << "Cambia " << i << " por " << f << std::endl;
      std::cout <<  std::endl;
      if (i != f){
        contador++;
      }
      i++;
      f--;
    }
    
    
    
    if (traceMode) {
      mostrar_v(sequence);
      std::cout << "Iteraciones hechas: " << contador << std::endl;
    }
  }

  if (i < 0) { i = 0; }
  if (f >= sequence.getSize()) { f = sequence.getSize() - 1; }

  if (ini < f){ quicksort(sequence, ini, f, traceMode, contador); }
  if (i < fin){ quicksort(sequence, i, fin, traceMode, contador); }
  
}

#endif