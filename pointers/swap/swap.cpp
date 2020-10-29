#include <iostream>

void swap (int* a, int* b) {
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;

  return;
}

int main() {
  int a, b;

  std::cin >> a >> b;
  std::cout << a << b << '\n';

  swap(&a, &b);

  std::cout << a << b << '\n';

  return 0;
}
