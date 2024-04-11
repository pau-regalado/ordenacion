#ifndef _QUICKSORTMETHOD_
#define _QUICKSORTMETHOD_

#include "commons.h"
#include "sortMethod.h"
#include "quickSort.h"

template <class Key>
class QuickSortMethod: public SortMethod<Key> {
  public:
    QuickSortMethod(StaticSequence<Key>& s, unsigned size): SortMethod<Key>(s, size) {}
    void Sort() {
      quicksort(this->sequence, 0, this->size);
    }
};


#endif