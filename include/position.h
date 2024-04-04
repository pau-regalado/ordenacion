#ifndef __POSITION__ 
#define __POSITION__

#include <vector>
#include <iostream>

class Position {
  private:
    int x;
  
  public:
    Position(int x = 0);
    Position(const Position& p);
    ~Position(void);

    void setX(const int x);
    int getX(void) const;
};

Position::Position(int x){
  this->x = x;
}

Position::Position(const Position& p){
  this->x = p.getX();
}

Position::~Position(void){}

void Position::setX(const int x) { this->x = x; }

int Position::getX(void) const{ return this->x;}

#endif