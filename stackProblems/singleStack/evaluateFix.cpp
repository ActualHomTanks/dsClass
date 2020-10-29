#include <iostream>
#include <cstdlib>
#include <cstring>
#include "singleStack.hpp"

using std::cout;
using std::endl;
using std::cin;

//coverts char numbers to double numbers
double charToDouble(char a) {
  a = a - 48; //48 is ASCII value of 0. for eg) If a = '5' <-- char, ASCII of 5 is 53. So 53-48 = 5 //
  a = double(a);
  return a;
}

//this function evaluates postfix if the input is an array
double evaluatePostfix(char * postfix) {    //char * postfix is the same thing as char postfix[]

  //BE VERY SURE TO USE A STAC OF DOUBLES.
  //I USED A CHAR STAC FIRST AND GOT STUCK ON WHY I WAS GETTING THE WRONG RESULT AAAAARGHJKDSZLSAGK :(
  //This is because the result can be bigger than 127 or smaller than -128 (limits of char)
  stacDouble evaluate;
  double result;
  double el1;
  double el2;

//READS FROM LEFT TO RIGHT
  for (int i = 0; postfix[i] != '\0'; i++){
    char element = postfix[i];

    switch (element) {
      //We want all the operators to do the same thing.
      //i.e pop the stack twice to get the last two elements, apply operator,
      //push result to stack.
      case '-': {
        el1 = evaluate.pop();
        el2 = evaluate.pop();
        result = el2 - el1;
        evaluate.push(result);
        break;
      }
      case '+': {
        el1 = evaluate.pop();
        el2 = evaluate.pop();
        result = el2 + el1;
        evaluate.push(result);
        break;
      }
      case '*': {
        el1 = evaluate.pop();
        el2 = evaluate.pop();
        result = el2 * el1;
        evaluate.push(result);
        break;
      }
      case '/': {
        el1 = evaluate.pop();
        el2 = evaluate.pop();
        result = el2 / el1;
        evaluate.push(result);
        break;
      }
      //operand should be pushed to stack AFTER CONVERTING IT TO A NUMBER(DOUBLE);
      default: evaluate.push(charToDouble(element)); break;

    }
  }
  return result;
}


//RIGHT TO LEFT //The element popped first is now the first operand.
double evaluatePrefix(char * prefix) {    //char * prefix is the same thing as char prefix[]

  stacDouble evaluate;
  double result;
  double el1;
  double el2;

//Reads from RIGHT TO LEFT
  for (int i = strlen(prefix); i >= 0; i--){
    char element = prefix[i];

    switch (element) {
      //We want all the operators to do the same thing.
      //i.e pop the stack twice to get the last two elements, apply operator,
      //push result to stack.
      case '-': {
        el1 = evaluate.pop();
        el2 = evaluate.pop();
        result = el1 - el2;
        evaluate.push(result);
        break;
      }
      case '+': {
        el1 = evaluate.pop();
        el2 = evaluate.pop();
        result = el1 + el2;
        evaluate.push(result);
        break;
      }
      case '*': {
        el1 = evaluate.pop();
        el2 = evaluate.pop();
        result = el1 * el2;
        evaluate.push(result);
        break;
      }
      case '/': {
        el1 = evaluate.pop();
        el2 = evaluate.pop();
        result = el1 / el2;
        evaluate.push(result);
        break;
      }
      //operand should be pushed to stack AFTER CONVERTING IT TO A NUMBER(DOUBLE);
      default: evaluate.push(charToDouble(element)); break;

    }
  }
  return result;
}
