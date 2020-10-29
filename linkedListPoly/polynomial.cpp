#include <iostream>
#include "polynomial.hpp"

linkedListPoly::nodePoly::nodePoly() : coef(0), power(0), next(nullptr) {}


linkedListPoly::nodePoly::nodePoly(int c, int p) : coef(c), power(p), next(nullptr) {}


linkedListPoly::linkedListPoly() : head(nullptr), tail(nullptr) {}


void linkedListPoly::insert(int c, int p) {
  nodePoly* newPoly = new nodePoly(c, p);

  if (!head) {
    head = newPoly;
    tail = newPoly;
    return;
  }

  tail->next = newPoly;
  tail = newPoly;
  return;
}


void linkedListPoly::read() {

std::cout << "Enter coefficient and power of term: " << '\n';

  while (true) {
    int c, p;
    std::cin >> c >> p;

    if (c == 0) {
      continue;
    }

    if (c == -999) {
      return;
    }

    insert(c, p);
  }
}


void linkedListPoly::add(linkedListPoly& poly2) {
  linkedListPoly& poly1 = *this;

  nodePoly* p1 = poly1.head;
  nodePoly* p2 = poly2.head;

  if (!p2) {
    std::cout << "Addition: ";
    poly1.display();
    return;
  }
  else if (!p1) {
    std::cout << "Addition: ";
    poly2.display();
    return;
  }

  linkedListPoly poly3;

  int newCoef = 0, meth = -1;

  while (p1 != nullptr && p2 != nullptr) {
    if (p1->power == p2->power) {
      meth = 0;
    }
    else if (p1->power > p2->power) {
      meth = 1;
    }
    else {
      meth = 2;
    }

    switch(meth) {
      case 0: {
        newCoef = p1->coef + p2->coef;
        if (newCoef) {
          poly3.insert(newCoef, p1->power);
          p1 = p1->next;
          p2 = p2->next;
          break;
        }
      }
      case 1: {
        poly3.insert(p1->coef, p1->power);
        p1 = p1->next;
        break;
      }
      case 2: {
        poly3.insert(p2->coef, p2->power);
        p2 = p2->next;
        break;
      }
      default: break;
    }
  }

  while (p1) {
    poly3.insert(p1->coef, p1->power);
    p1 = p1->next;
  }

  while (p2) {
    poly3.insert(p2->coef, p2->power);
    p2 = p2->next;
  }

  std::cout << "Addition: ";
  poly3.display();

  return;
}


void linkedListPoly::display() {
  if (!head) {
    return;
  }

  nodePoly* curr = head;

  while(curr->next) {
    std::cout << curr->coef << "x^" << curr->power;
    curr = curr->next;

    if (curr->coef > 0) {
      std::cout << " + ";
    }
    else {
      std::cout << " ";
    }
  }

  std::cout << curr->coef << "x^" << curr->power << '\n';
}
