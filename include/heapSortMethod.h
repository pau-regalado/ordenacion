#ifndef _HEAPSORTMETHOD_
#define _HEAPSORTMETHOD_

#include "sortMethod.h"
#include "commons.h"
#include "heapSort.h"

template <class Key>
class HeapSortMethod: public SortMethod<Key>{
  private:
  public:
    HeapSortMethod(StaticSequence<Key>& s, unsigned size): SortMethod<Key>(s, size) {}
    HeapSortMethod(std::string filename): SortMethod<Key>(filename) {}
    void Sort() {
      heapsort(this->sequence, this->size);
    }
};

#endif