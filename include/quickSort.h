#ifndef __QUICKSORT__
#define _QUICKSORT_

#include "staticSequence.h"

template <typename Key>
void quicksort(StaticSequence<Key>& sequence, unsigned ini, unsigned fin){
  int i = ini, f = fin;
  int pivote = sequence.at((i+f)/2);
  std::cout << "PIV " << pivote << std::endl;

  while (i <= f){ 
    while (sequence.at(i) < pivote){ i++;}
    while (sequence.at(f) > pivote){ f--;}

    if (i <= f) {
      swap(sequence,i,f);
      i++;
      f--;
    }
    //mostrar_v(sequence);
  }

  if (i < 0) { i = 0; }
  if (f >= sequence.size()) { f = sequence.size() - 1; }
  std::cout << "i = " << i << " f = " << f << std::endl;

  if (ini < f){ quicksort(sequence,ini,f); }
  if (i < fin){ quicksort(sequence, i, fin); }
}

#endif