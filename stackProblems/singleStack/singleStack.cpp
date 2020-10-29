#include <iostream>
#include <cstdlib>
#include <cstring>
#include "singleStack.hpp"

using std::cout;
using std::endl;
using std::cin;

////////////////////DEFINITION FOR STACK OF CHARS///////////////////////

stac::stac() {top = -1;}

void stac::push(char n) {
  if (full()) {
    std::cout << "Stack will overflow!" << '\n';
    return;
  }

  //You can also just replace the below 3 lines with "return st[++top];"
  //I've done it this way to make what's happening more obvious
  top++;
  st[top] = n;
  return;
}

char stac::pop() {
  if (empty()) {
    std::cout << "Stack will underflow! Returning 0" << '\n';
    return 0;
  }

  //You can also just replace the below 3 lines with "return st[top--];"
  //I've done it this way to make what's happening more obvious
  char n = st[top];
  top--;
  return n;
}

char stac::peek() {
  if (empty()) {
    //std::cout << "Stack is empty! Returning 0" << '\n';
    return 0;
  }

  return st[top];
}

int stac::size() {
  return top+1;
}

bool stac::empty() {
  if (top == -1) {
    return true;
  }
  else return false;
}

bool stac::full() {
  if (top == maximum) {
    return true;
  }
  else return false;
}

void stac::display() {
  if (empty()) {
    std::cout << "Stack is empty!" << '\n';
    return;
  }

  for (int i = 0; i <= top; i++) {
    std::cout << st[i];
  }
  std::cout << '\n';
  return;
}


////////////DEFINITION FOR STACK OF DOUBLES//////////////////////////////////////////////
//We could have used C++ templates to make a single stack class that handled
//both chars and doubles and whatever but idk if it's in the syllabus.
//Further reading: https://www.programiz.com/cpp-programming/templates


stacDouble::stacDouble() {top = -1;}


void stacDouble::push(double n) {
  if (full()) {
    std::cout << "Stack will Overflow!" << '\n';
  }

  top++;
  st[top] = n;
  return;
}

double stacDouble::pop() {
  if (empty()) {
    std::cout << "Stack will underflow! Returning 0" << '\n';
    return 0;
  }

  double n = st[top];
  top--;
  return n;
}

double stacDouble::peek() {
  if (empty()) {
    //std::cout << "Stack is empty! Returning 0" << '\n';
    return 0;
  }

  return st[top];
}

int stacDouble::size() {
  return top+1;
}

bool stacDouble::empty() {
  if (top == -1) {
    return true;
  }
  else return false;
}

bool stacDouble::full() {
  if (top == maximum) {
    return true;
  }
  else return false;
}

void stacDouble::display() {
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

//////////DEFINITION FOR 2D STACKS///////////////////////////////////////////
//I didn't understand how it was in the lecture so this implementation
//might be a lil' bit different idk :/


//In 2D Stack we're manipulating a row of cells at a time instead of
//a single cell like in 1D Stack. st[i] refers to a ROW OF CELLS.
stacTwoDim::stacTwoDim() {
  top = -1;
}

void stacTwoDim::push(char * n) {
  if (full()) {
    std::cout << "Stack will Overflow!" << '\n';
    return;
  }

  top++;
  strcpy(st[top], n);
  return;
}

char* stacTwoDim::pop() {
  if (empty()) {
    return 0;
  }

  return st[top--];
}

char* stacTwoDim::peek() {
  if (empty()) {
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

//prints all rows
void stacTwoDim::display() {
  for (int i = top; i >=0; i--) {
      std::cout << st[i] << '\n';
    }

  return;
}
