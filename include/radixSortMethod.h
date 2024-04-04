#ifndef _RADIXSORTMETHOD_
#define _RADIXSORTMETHOD_

#include "sortMethod.h"
#include "radixSort.h"

template <class Key>
class RadixSortMethod: public SortMethod<Key>{
  public:
  RadixSortMethod(StaticSequence<Key>& sequence, unsigned size): SortMethod<Key>(sequence, size) {}
  RadixSortMethod(std::string filename): SortMethod<Key>(filename) {}
    void Sort() {
      radixSort(this->seq_, this->size);
    }
};

#endif