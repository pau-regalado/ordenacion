#ifndef __INCRDECMETHOD__
#define __INCRDECMETHOD__

#include "sortMethod.h"
#include "incrDec.h"
#include "commons.h"

template <class Key>
class IncrDecMethod: public SortMethod<Key>{
  private:
    float alpha_;
  public:
    IncrDecMethod(StaticSequence<Key>& s, unsigned size): SortMethod<Key>(s, size) {}
    IncrDecMethod(std::string filename): SortMethod<Key>(filename) {}
    void Sort() {
      incr_dec(this->sequence, this->size);
    }
  
};

#endif