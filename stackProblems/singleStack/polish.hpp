#ifndef POLISH
#define POLISH
#include "singleStack.hpp"

int precedencePostfix(char c);
int precedencePrefix(char c);
stac polish(char infix[]);
stac reversePolish(char infix[]);
void prefixToInfix(char * prefix);
void prefixToPostfix(char * prefix);
void postfixToInfix(char * postfix);
void postfixToPrefix(char * postfix);

#endif
