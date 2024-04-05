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
  bool traceCheck = false;
  int size;
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
      char* traceCheck = argv[++i];
      if (strcmp(traceCheck, "y") == 0) {
        
      } else if (strcmp(traceCheck, "n") == 0) {
        
      } 
    }
  }

  if (!filename.empty()) {
    switch (orderType) {
      case ordTypes::INCRDEC: {
        ord = new IncrDecMethod<Key>(filename);          
        break;
      };
      case ordTypes::HEAP: {
        ord = new HeapSortMethod<Key>(filename);         
        break;
      };
      case ordTypes::SELECCION: {
        ord = new SeleccionMethod<Key>(filename);
        break;
      };
      case ordTypes::RADIX: {
        ord = new RadixSortMethod<Key>(filename); 
        break;
      };
      case ordTypes::QUICK: {
        ord = new QuickSortMethod<Key>(filename);
        break;
      };
    default:
        ord = new SeleccionMethod<Key>(filename);
      break;
    }
  } else if (initType == initTypes::MANUAL) {
    sequence = new StaticSequence<Key>(size);
    sequence->manualInitializing();
  } else if (initType == initTypes::RANDOM) {
    sequence = new StaticSequence<Key>(size);
    std::cout << "VOOOOOOOOOOOOOOOOOOOOOOOOOYYYY" << std::endl;
    sequence->randomInitializing();
  } else {
    throw std::exception();
  }

  switch (orderType) {
    case ordTypes::INCRDEC: {
      ord = new IncrDecMethod<Key>(*sequence, size, 0.2);          
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

  mostrar_v(*sequence);
  std::cout << "VOY A ORDENAR" << std::endl;
  ord->Sort();
  std::cout << "YA ORDENE" << std::endl;
}

#endif