#include <iostream>
#include "singleStack.hpp"
#include "functionImporter.hpp" //HAS ALL FUNCTION HEADERS, ADD NEW IN HERE

using std::cout;
using std::endl;
using std::cin;


int main() {
  int operation;

  do {
    std::cout << "1. ValidExpression \t 2. Palindrome \t 3. InfixToPolish \t 4. PolishConversion \t 5. EvaluatePolish \t 6.Exit: ";
    std::cin >> operation;

    //ALL READ FUNCTIONS ARE INSIDE read.cpp
    switch (operation) {
      case 1: readExpression(); break;
      case 2: readPalindrome(); break;
      case 3: readInfix(); break;
      case 4: readPolishToFix(); break;
      case 5: readPolishEval(); break;
      case 6: return EXIT_SUCCESS;
      default: return EXIT_SUCCESS;
    }
  } while(true);

    return 0;
}
