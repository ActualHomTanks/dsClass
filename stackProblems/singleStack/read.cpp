#include <iostream>
#include "singleStack.hpp"
#include "functionImporter.hpp"

using std::cout;
using std::endl;
using std::cin;

//DON'T USE getline() or get() to take input of any expression in here, use cin,
//it's okay the expression won't have whitespace.
//This caused a lot of headache AAAAAAAAAAAAARGDFJKGDJAGJASADKLJFA
//Reason: https://stackoverflow.com/questions/21567291/why-does-stdgetline-skip-input-after-a-formatted-extraction


//Reads char array input for Valid Expression check
void readExpression() {
  char expre[maximum];

  std::cout << "Enter expression to check: " << '\n';

  cin >> expre;
  cout << validExpression(expre) << "\n\n";

  return;
}

//Reads char array input for infix expression operations. for eg) infix to postfix
void readInfix() {
  char infix[maximum];
  stac output;

  cout << "Enter Infix Expression: " << '\n';
  cin >> infix;


  int meth;
  std::cout << "1.toPrefix \t 2.toPostfix: ";
  cin >> meth;

  switch (meth) {
    case 1: {
      output = polish(infix);
      break;
    }
    case 2: {
      output = reversePolish(infix);
    }
  }

  output.display();
  std::cout << '\n';

  return;
}

//Reads char array input expression for Palindrome check
void readPalindrome() {
  char word[maximum];

  std::cout << "Enter Word: " << '\n';
  cin >> word;

  std::cout << palindrome(word) << "\n\n";
}

//Reads char array input expression to evaluate the value of a polish expression.
void readPolishEval() {
  char polishExp[maximum];

  std::cout << "Enter Polish Expression: " << '\n';
  cin >> polishExp;

  int meth;
  std::cout << "1.FromPrefix 2.FromPostfix" << '\n';
  cin >> meth;

  switch (meth) {
    case 1: {
      std::cout << "Result: " << evaluatePrefix(polishExp) << "\n\n"; break;
    }
    case 2: {
      std::cout << "Result: " << evaluatePostfix(polishExp) << "\n\n"; break;
    }
  }
  return;
}

//Reads char array input polish expression to perform some conversion
void readPolishToFix() {
  char polishExp[maximum];

  std::cout << "Enter Polish Expression: " << '\n';
  cin >> polishExp;

  int meth;
  std::cout << "1. PrefixToInfix \t 2. PostfixToInfix \t 3. PrefixToPostfix \t 4.PostfixToPrefix: ";
  cin >> meth;

  switch (meth) {
    case 1: {
      prefixToInfix(polishExp); break;
    }
    case 2: {
      postfixToInfix(polishExp); break;
    }
    case 3: {
      prefixToPostfix(polishExp); break;
    }
    case 4: {
      postfixToPrefix(polishExp); break;
    }
  }
  return;
}
