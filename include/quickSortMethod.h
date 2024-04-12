#ifndef _QUICKSORTMETHOD_
#define _QUICKSORTMETHOD_

#include "commons.h"
#include "sortMethod.h"
#include "quickSort.h"

template <class Key>
class QuickSortMethod: public SortMethod<Key> {
  public:
    QuickSortMethod(StaticSequence<Key>& s, unsigned size, bool traceMode): SortMethod<Key>(s, size, traceMode) {  }
    void Sort() {
      this-> contador = 0;
      quicksort(this->sequence, 0, this->size, this->traceMode, this->contador);
      
    }

  private:
    int contador;
};


#endif