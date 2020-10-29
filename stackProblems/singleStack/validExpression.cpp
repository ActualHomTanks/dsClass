#include <iostream>
#include "singleStack.hpp"
using std::cout;
using std::endl;
using std::cin;

//See DS Slides of 6.Stacks for logic and examples.
bool validExpression(char array[]) {
  stac expression;
  for (int i = 0; array[i] != '\0'; i++) {
    char element = array[i];

    switch (element) {
      case '(':
      case '{':
      case '[': expression.push(element); break;
      case ')': {
        if (expression.pop() == '(') continue; else return false;
      }
      case '}': {
        if (expression.pop() == '{') continue; else return false;
      }
      case ']': {
        if (expression.pop() == '[') continue; else return false;
      }
      default: continue;
    }
  }

  if (!expression.empty()) {
    return false;
  }

  return true;
}
