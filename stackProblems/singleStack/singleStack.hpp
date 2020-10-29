#ifndef SINGLE_STACK
#define SINGLE_STACK

#include <iostream>
#include <cstdlib>
#define maximum 100


class stac {
private:
  int top;
  char st[maximum];

public:
  stac();
  void push(char n);
  char pop();
  char peek();
  int size();
  bool empty();
  bool full();
  void display();

};


//We could have used C++ templates to make a single stack class that handled
//both chars and doubles and whatever but idk if it's in the syllabus.
//Further reading: https://www.programiz.com/cpp-programming/templates

class stacDouble {
private:
  int top;
  double st[maximum];

public:
  stacDouble();
  void push(double n);
  double pop();
  double peek();
  int size();
  bool empty();
  bool full();
  void display();
};


class stacTwoDim {
private:
  int top;
  char st[maximum][maximum];

public:
  stacTwoDim();
  void push(char n[]);
  char* pop();
  char* peek();
  int size();
  bool empty();
  bool full();
  void display();

};

#endif
