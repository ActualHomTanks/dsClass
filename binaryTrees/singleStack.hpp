#ifndef SINGLE_STACK
#define SINGLE_STACK

#include <iostream>
#include <cstdlib>
#define maximum 100


class stacInt {
private:
  int top;
  double st[maximum];

public:
  stacInt();
  void push(int n);
  int pop();
  int peek();
  int size();
  bool empty();
  bool full();
  void display();
};


#endif
