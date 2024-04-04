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
    IncrDecMethod(StaticSequence<Key>& s, unsigned size, float alpha): SortMethod<Key>(s, size), alpha_(alpha) {}
    IncrDecMethod(std::string filename): SortMethod<Key>(filename), alpha_(0.6) {}
    void Sort() {
      incr_dec(this->sequence, this->size, alpha_);
    }
  
};

#endif