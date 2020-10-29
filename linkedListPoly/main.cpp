#include <iostream>
#include "polynomial.hpp"

int main() {
  std::cout << "How many polynomials to store: " << '\n';
  int n;
  std::cin >> n;

  linkedListPoly* arr = new linkedListPoly[n];

  for (int i = 0; i < n; i++) {
    arr[i].read();
    arr[i].display();
  }

  int a, b;
  std::cout << "Which polynomials to add: " << '\n';
  std::cin >> a >> b;

  arr[a].add(arr[b]);
  return 0;
}
