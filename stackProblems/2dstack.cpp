#include <iostream>
#include <cstring>
#include "2dstack.hpp"
using std::cout;

stacTwoDim::stacTwoDim() {
  top = -1;
}

void stacTwoDim::push(char n[]) {
  if ((*this).full()) {
    std::cout << "Stack will Overflow!" << '\n';
    return;
  }

  top++;
  strcpy(st[top], n);
  return;
}

char* stacTwoDim::pop() {
  if ((*this).empty()) {
    return 0;
  }

  return st[top--];
}

char* stacTwoDim::peek() {
  if ((*this).empty()) {
    return 0;
  }
  
  return st[top];
}

int stacTwoDim::size() {
  return top+1;
}

bool stacTwoDim::empty() {
  if (top == -1) {
    return true;
  }
  else return false;
}

bool stacTwoDim::full() {
  if (top == maximum) {
    return true;
  }
  else return false;
}

void stacTwoDim::display() {
  for (int i = top; i >=0; i--) {
      std::cout << st[i] << '\n';
    }

  return;
}
