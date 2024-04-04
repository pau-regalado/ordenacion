#ifndef _RADIXSORTMETHOD_
#define _RADIXSORTMETHOD_

#include <math.h>
#include "sortMethod.h"
const int kDigits = 4;

template <class Key>
class RadixSortMethod: public SortMethod<Key>{
  public:
  RadixSortMethod(std::vector<Key>* v, unsigned size): SortMethod<Key>{ v, size} {}
  RadixSortMethod(std::string filename): SortMethod<Key>{ filename } {}
    void Sort() {
      radixSort(this->seq_, this->size_);
    }
};

#endif