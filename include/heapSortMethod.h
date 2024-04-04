#ifndef _HEAPSORTMETHOD_
#define _HEAPSORTMETHOD_
#include "sortMethod.h"

template <class Key>
class HeapSortMethod: public SortMethod<Key>{
  private:
  public:
    HeapSortMethod(StaticSequence<Key>* v, unsigned size): SortMethod<Key>{ v, size} {}
    HeapSortMethod(std::string filename): SortMethod<Key>{ filename } {}
    void Sort() {
      heapsort(this->seq_, this->size_);
    }
};

#endif