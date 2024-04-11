#ifndef _RADIXSORTMETHOD_
#define _RADIXSORTMETHOD_

#include "sortMethod.h"
#include "radixSort.h"
#include "commons.h"

template <class Key>
class RadixSortMethod: public SortMethod<Key>{
  public:
  RadixSortMethod(StaticSequence<Key>& sequence, unsigned size, bool traceMode): SortMethod<Key>(sequence, size, traceMode) {}
  RadixSortMethod(std::string filename): SortMethod<Key>(filename) {}
    void Sort() {
      radixSort(this->sequence, this->size, this->traceMode);
    }
};

#endif