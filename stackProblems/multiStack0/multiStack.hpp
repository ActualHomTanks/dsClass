#include <iostream>
#define topsize 10
#define boundsize 10
#define arrsize 60

using namespace std;

class multiStac {
private:
  int top[topsize];
  int boundary[boundsize];
  char array[arrsize];
public:
  multiStac(int n);
  void push(char n, int i);
  char peek(int i);
  char pop(int i);
  int size(int i);
  bool empty(int i);
  bool full(int i);
  void display(int i);
};

multiStac::multiStac(int n) {
  for (int i = 0; i < n; i++) {
    top[i]=boundary[i]=((arrsize/n)*i) - 1;
  }
}

void multiStac::push(char n, int i) {
  if (full(i)) {
    std::cout << "Stack Overflow!" << '\n';
    return;
  }

  top[i]++;
  array[top[i]] = n;
  return;
}

char multiStac::peek(int i) {
  if (empty(i)) {
    std::cout << "Stack is empty! Returning 0" << '\n';
    return 0;
  }

  return array[top[i]];
}

char multiStac::pop(int i) {
  if (empty(i)) {
    std::cout << "Stack is empty! Returning 0" << '\n';
    return 0;
  }

  char x = peek(i);
  top[i]--;
  return x;
}

int multiStac::size(int i) {
  if (empty(i)) {
    return 0;
  }
  else return (top[i]-boundary[i]);
}

bool multiStac::empty(int i) {
  if (top[i]==boundary[i]) {
    return true;
  }
  else return false;
}

bool multiStac::full(int i) {
  if ((top[i]==boundary[i+1]) || (top[i] == arrsize-1)) {
    return true;
  }
  else return false;
}

void multiStac::display(int i) {
  if (empty(i)) {
    std::cout << "Stack is empty!" << '\n';
    return;
  }

  for (int j = boundary[i]+1; j <= top[i]; j++) {
    std::cout << array[j] << " ";
  }
  std::cout << '\n';
  return;
}
