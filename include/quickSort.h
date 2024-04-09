#ifndef __QUICKSORT__
#define __QUICKSORT__

#include "staticSequence.h"

template <typename Key>
void quicksort(StaticSequence<Key>& sequence, unsigned ini, unsigned fin){
  int i = ini, f = fin;
  long pivote = long(sequence[Position((i+f)/2)]);
  std::cout << "PIV " << pivote << std::endl;

  while (i <= f){ 
    while (long(sequence[Position(i)]) < pivote){ i++;}
    while (long(sequence[Position(f)]) > pivote){ f--;}

    if (i <= f) {
      swap(sequence,i,f);
      i++;
      f--;
    }
    mostrar_v(sequence);
  }

  if (i < 0) { i = 0; }
  if (f >= sequence.getSize()) { f = sequence.getSize() - 1; }
  std::cout << "i = " << i << " f = " << f << std::endl;
  std::cout << "ini = " << ini << " fin = " << fin << std::endl;

  if (ini < f){ quicksort(sequence, ini, f); }
  if (i < fin){ quicksort(sequence, i, fin); }
}

#endif