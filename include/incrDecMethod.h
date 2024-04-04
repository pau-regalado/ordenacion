#ifndef __INCRDECMETHOD__
#define __INCRDECMETHOD__

#include "sortMethod.h"

template <class Key>
class IncrDecMethod: public SortMethod<Key>{
  private:
    float alpha_;
  public:
    IncrDecMethod(std::vector<Key>* v, float alpha, unsigned size): SortMethod<Key>{ v, size}, alpha_(alpha) {}
    IncrDecMethod(std::string filename): SortMethod<Key>{ filename } {}
    void Sort() {
      incr_dec(this->seq_, alpha_, this->size_);
    }
  
};

#endif