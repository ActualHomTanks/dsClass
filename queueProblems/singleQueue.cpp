#include <iostream>

#include "singleQueue.hpp"

cque::cque() {
  f = 0;
  r = -1;
  count = 0;
}

void cque::enque(char element) {
  if (full()) {
    std::cout << "Queue is Full!" << '\n';
    return;
  }

  r = (r+1) % maximum;
  q[r] = element;
  count++;
  return;
}

char cque::deque() {
  if (empty()) {
    std::cout << "Queue is Empty! Returning 0" << '\n';
    return 0;
  }

  char element = q[f];
  f = (f+1) % maximum;
  count--;
  return element;
}

char cque::peek() {
  if (empty()) {
    std::cout << "Queue is Empty! Returning 0" << '\n';
    return 0;
  }

  return q[f];
}

int cque::size() {
  return count;
}

bool cque::empty() {
  if (count == 0) {
    return true;
  }
  else return false;
}

bool cque::full() {
  if (count == maximum) {
    return true;
  }
  else return false;
}

void cque::display() {
  if (empty()) {
    std::cout << "Queue is Empty!" << '\n';
    return;
  }

  for (int i = f; i != r; i = (i+1) % maximum) {
    std::cout << q[i];
  }
  std::cout << q[r] << '\n';
  return;
}
