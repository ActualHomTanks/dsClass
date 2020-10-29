#include <iostream>
#include "singleStack.hpp"
using std::cout;
using std::endl;
using std::cin;

//reads a string and pushes everything into a stack. Then reads the string
//again and pops the stack at each character and compares the two things for equality.
//It's not the fastest way to do this but it's easy to understand
bool palindrome(char array[]) {
  stac word;

  for (int i = 0; array[i] != '\0'; i++) {
    word.push(array[i]);
  }

  for (int j = 0; array[j] != '\0'; j++) {
    if (word.pop() != array[j]) {
      return false;
    }
  }
  return true;
}
