#ifndef _SELECCIONMETHOD_
#define _SELECCIONMETHOD_

#include "sortMethod.h"
#include "seleccion.h"

template <class Key>
class SeleccionMethod: public SortMethod<Key>{
  public:
    SeleccionMethod(StaticSequence<Key>* v, unsigned size): SortMethod<Key>{ v, size } {}
    SeleccionMethod(std::string filename): SortMethod<Key>{ filename } {}
    void Sort() {
      seleccion(this->seq_, this->size_);
    }   
};

#endif