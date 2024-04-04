#ifndef __SEQUENCE__
#define __SEQUENCE__
 
#include "position.h"

template <class Key>
class Sequence{
  public:
    virtual Key operator[](const Position&) const = 0;
};

#endif