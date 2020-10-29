#include <iostream>

int sumArray(int* arr, int arrLen) {
  int* p = arr;
  int sum = 0;

  for (int i = 0; i < arrLen; i++) {
    sum += *(p+i);
  }

  return sum;
}

int main() {

  int arr[100];
  int n;

  std::cin >> n;

  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }

  std::cout << sumArray(arr, n) << '\n';

  return 0;
}
