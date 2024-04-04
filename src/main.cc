#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <algorithm>
#include <chrono>

#include "../include/simulator.h"
/*
const int MAX_INT = 9999;
const int MIN_INT = 1000;

template <typename Clave>
void fillRandVector (std::vector<Clave>* vector) {
  for(int i = 0; i < vector->size(); ++i){
    vector->at(i) = MIN_INT + rand() % (MAX_INT - MIN_INT);
  }
}
*/

int main (int argc, char* argv[]){
  Simulator simulator;
  simulator.run(argc, argv); 
}