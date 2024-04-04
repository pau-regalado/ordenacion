#ifndef _QUICKSORTMETHOD_
#define _QUICKSORTMETHOD_

#include "commons.h"
template <class Key>
class QuickSortMethod: public SortMethod<Key>{
  private:
  public:
    QuickSortMethod(StaticSequence<Key>* v, unsigned ini, unsigned fin): SortMethod<Key>{ v, ini, fin} {}
    QuickSortMethod(std::string filename): SortMethod<Key>{ filename } {}
    void Sort() {
      quicksort(this->seq_, this->ini, this->fin);
    }
};


#endif