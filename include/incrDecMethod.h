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
    IncrDecMethod(StaticSequence<Key>& s, float alpha, unsigned size, bool traceMode): SortMethod<Key>(s, size, traceMode), alpha_(alpha) {}
    void Sort() {
      incr_dec(this->sequence, alpha_, this->size, this->traceMode);
    } 
};

#endif