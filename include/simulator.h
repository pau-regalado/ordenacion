#ifndef __SIMULATOR__
#define __SIMULATOR__

#include <iostream>
#include <fstream>
#include <string.h>

#include "quickSortMethod.h"
#include "incrDecMethod.h"
#include "heapSortMethod.h"
#include "seleccionMethod.h"
#include "radixSortMethod.h"
#include "commons.h"
#include "nif.h"

typedef Nif Key;

enum ordTypes { INCRDEC, HEAP, SELECCION, RADIX, QUICK };
enum initTypes { MANUAL, RANDOM };

class Simulator {
  public:
    Simulator() {}
    void run(int argc, char* argv[]);
}; 

void Simulator::run(int argc, char* argv[]) { 
  bool sizeCheck = false;
  bool ordCheck = false;
  bool traceType = false;
  bool traceCheck = false;
  int size;
  float alpha;
  initTypes initType = initTypes::RANDOM;

  SortMethod<Key>* ord;
  StaticSequence<Key>* sequence;
  std::string filename = "";
  ordTypes orderType = ordTypes::HEAP;

  for (int i = 1; i < argc; ++i) {
    if (strcmp(argv[i], "-size") == 0 && i + 1 < argc) {
      size = std::stoi(argv[i + 1]);
      sizeCheck = true;
    } else if (strcmp(argv[i], "-ord") == 0 && i + 1 < argc) {
      char* ordType = argv[++i];
      if (strcmp(ordType, "incrDec") == 0) {
        orderType = ordTypes::INCRDEC;
        alpha = std::stof(argv[++i]);
        ordCheck = true;
      } else if (strcmp(ordType, "heap") == 0) {
        orderType = ordTypes::HEAP;
        ordCheck = true;
      } else if (strcmp(ordType, "seleccion") == 0) {
        orderType = ordTypes::SELECCION;
        ordCheck = true;
      } else if (strcmp(ordType, "radix") == 0) {
        orderType = ordTypes::RADIX;
        ordCheck = true;
      } else if (strcmp(ordType, "quicksort") == 0) {
        orderType = ordTypes::QUICK;
        ordCheck = true;
      }

    } else if (strcmp(argv[i], "-init") == 0 && i + 1 < argc) {
      char* initializingType = argv[++i];
      if (strcmp(initializingType, "manual") == 0) {      
        initType = initTypes::MANUAL;
      } else if (strcmp(initializingType, "random") == 0) {
        initType = initTypes::RANDOM;
      } else if (strcmp(initializingType, "file") == 0) {
        filename = argv[++i];
      } 
    } else if (strcmp(argv[i], "-trace") == 0 && i + 1 < argc) {
      char* traceType = argv[++i];
      if (strcmp(traceType, "y") == 0) {
        traceCheck = true;
      } else if (strcmp(traceType, "n") == 0) {
        traceCheck = false;
      } 
    }
  }

  if (!filename.empty()) {   
    sequence = new StaticSequence<Key>(filename);
    switch (orderType) {
      case ordTypes::INCRDEC: {      
        ord = new IncrDecMethod<Key>(*sequence, alpha, sequence->getSize());             
        break;
      };
      case ordTypes::HEAP: {
        ord = new HeapSortMethod<Key>(*sequence, sequence->getSize());         
        break;
      };
      case ordTypes::SELECCION: {
        ord = new SeleccionMethod<Key>(*sequence, sequence->getSize());
        break;
      };
      case ordTypes::RADIX: {
        ord = new RadixSortMethod<Key>(*sequence, sequence->getSize()); 
        break;
      };
      case ordTypes::QUICK: {
        ord = new QuickSortMethod<Key>(*sequence, sequence->getSize());
        break;
      };
    default:
        ord = new SeleccionMethod<Key>(*sequence, sequence->getSize());
      break;
    }
  } else if (initType == initTypes::MANUAL) {
    sequence = new StaticSequence<Key>(size);
    sequence->manualInitializing();
  } else if (initType == initTypes::RANDOM) {
    sequence = new StaticSequence<Key>(size);
    sequence->randomInitializing();
  } else {
    throw std::exception();
  }

  switch (orderType) {
    case ordTypes::INCRDEC: {
      ord = new IncrDecMethod<Key>(*sequence, alpha, size);          
      break;
    };
    case ordTypes::HEAP: {
      ord = new HeapSortMethod<Key>(*sequence, size);         
      break;
    };
    case ordTypes::SELECCION: {
      ord = new SeleccionMethod<Key>(*sequence, size);
      break;
    };
    case ordTypes::RADIX: {
      ord = new RadixSortMethod<Key>(*sequence, size); 
      break;
    };
    case ordTypes::QUICK: {
      ord = new QuickSortMethod<Key>(*sequence, size);
      break;
    };
  default:
      ord = new SeleccionMethod<Key>(*sequence, size);
    break;
  }

  //mostrar_v(*sequence);
  ord->Sort();
}

#endif