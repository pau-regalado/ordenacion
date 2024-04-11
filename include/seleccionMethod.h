#ifndef _SELECCIONMETHOD_
#define _SELECCIONMETHOD_

#include "sortMethod.h"
#include "seleccion.h"
#include "commons.h"

template <class Key>
class SeleccionMethod: public SortMethod<Key>{
  public:
    SeleccionMethod(StaticSequence<Key>& sequence, unsigned size, bool traceMode): SortMethod<Key>(sequence, size, traceMode) {}
    SeleccionMethod(std::string filename): SortMethod<Key>(filename) {}
    void Sort() {
      seleccion(this->sequence, this->size, this->traceMode);
    }   
};

#endif