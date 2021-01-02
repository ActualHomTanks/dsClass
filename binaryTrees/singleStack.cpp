#include <iostream>
#include "singleStack.hpp"


stacInt::stacInt() {top = -1;}


void stacInt::push(int n) {
  if (full()) {
    std::cout << "Stack will Overflow!" << '\n';
  }

  top++;
  st[top] = n;
  return;
}

int stacInt::pop() {
  if (empty()) {
    std::cout << "Stack will underflow! Returning 0" << '\n';
    return 0;
  }

  int n = st[top];
  top--;
  return n;
}

int stacInt::peek() {
  if (empty()) {
    //std::cout << "Stack is empty! Returning 0" << '\n';
    return 0;
  }

  return st[top];
}

int stacInt::size() {
  return top+1;
}

bool stacInt::empty() {
  if (top == -1) {
    return true;
  }
  else return false;
}

bool stacInt::full() {
  if (top == maximum) {
    return true;
  }
  else return false;
}

void stacInt::display() {
  if (empty()) {
    std::cout << "Stack is empty!" << '\n';
    return;
  }

  for (int i = 0; i <= top; i++) {
    std::cout << st[i];
    return;
  }
  std::cout << '\n';
  return;
}
