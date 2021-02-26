#include <iostream>
#include "singleStack.hpp"
#include <cstring>
using std::cout;
using std::endl;
using std::cin;

////////////////////////////////PREFIX STUFF/////////////////////////////////////////////////////////////////////////////////////////////////
//Returns an int for the prefix precedence value of an operator
int precedencePrefix(char c)
{
	switch (c) {
	case ')': return 1;
	case '+':
	case '-': return 2;
	case '*':
	case '/': return 3;
	case '^': return 4;
	default: return 0;
	}
	return -1;
}

//Returns a stack containing the prefix expression
stac polish(char infix[])
{
	char e1;
	stac s; //stack which holds the operators
	stac output; //output stack
	stac reverseOutput; //stack which contains the reverse of output stack
	//see DS class slides Infix to Prefix Method 2 for logic

	//infix expression is read from right to left
	for (int i = strlen(infix) - 1; i >= 0; i--) {
		e1 = infix[i];

		switch (e1) {
		case ')': s.push(e1); break;

		case '(': {
			while (s.peek() != ')') {
				output.push(s.pop());
			}
			s.pop();
			break;
		}

		case '-':

		case '+':

		case '*':

		case '/': {
			char e2 = s.peek();
			if (precedencePrefix(e1) > precedencePrefix(e2)) {
				s.push(e1);
				break;
			}
			else {
				do {
					output.push(s.pop());
					e2 = s.peek();
				} while (precedencePrefix(e1) <= precedencePrefix(e2));

				s.push(e1);
				break;
			}
		}

		default: output.push(e1); break;  //pushes operand to stack
		}
	}
	//pop stack s until it's empty
	while (s.size() > 0) {
		output.push(s.pop());
	}

	//now we need to reverse the output, we could have used the now empty stack s too!
	//I'm using a new empty stack reverseOutput for clarity's sake
	while (!output.empty()) {
		reverseOutput.push(output.pop());
	}

	return reverseOutput;
}


//Prints infix expression from prefix expression
void prefixToInfix(char* prefix)
{
	stacTwoDim s;
	char element[2];
	char operand1[maximum];
	char operand2[maximum];
	char result[maximum];

	//Reads RIGHT TO LEFT
	for (int i = strlen(prefix) - 1; i >= 0; i--) {
		element[0] = prefix[i];
		element[1] = '\0'; //This is added so the string functions work properly

	  //Checks if element[0] is an operator
		if (element[0] == '-' || element[0] == '+' || element[0] == '*' || element[0] == '/' || element[0] == '^') {
			strcpy(operand1, s.pop());
			strcpy(operand2, s.pop());
			// (operand1 + element + operand2)
			strcpy(result, "(");
			strcat(result, operand1);
			strcat(result, element);
			strcat(result, operand2);
			strcat(result, ")");
			s.push(result);
		}
		else {
			s.push(element); //pushes operands to stack
		}
	}

	//prints infix expression
	for (int i = 0; result[i] != '\0'; i++) {
		std::cout << result[i];
	}
	std::cout << "\n\n";
}


//Prints postfix expression from prefix expression
void prefixToPostfix(char* prefix)
{
	stacTwoDim s;
	char element[2];
	char operand1[maximum];
	char operand2[maximum];
	char result[maximum];

	//Reads RIGHT TO LEFT
	for (int i = strlen(prefix); i >= 0; i--) {
		element[0] = prefix[i];
		element[1] = '\0';

		//Checks if element[0] is an operator
		if (element[0] == '-' || element[0] == '+' || element[0] == '*' || element[0] == '/' || element[0] == '^') {
			strcpy(operand1, s.pop());
			strcpy(operand2, s.pop());
			// operand1 + operand2 + element
			strcpy(result, operand1);
			strcat(result, operand2);
			strcat(result, element);
			s.push(result);
		}
		else {
			s.push(element); //pushes operand to stack
		}
	}

	//Prints postfix expression
	for (int i = 0; result[i] != '\0'; i++) {
		std::cout << result[i];
	}
	std::cout << "\n\n";
}


////////////////////////////////POSTFIX STUFF////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Returns an int for the postfix precedence value of an operator
int precedencePostfix(char c)
{
	switch (c) {
	case '(': return 1;
	case '+':
	case '-': return 2;
	case '*':
	case '/': return 3;
	case '^': return 4;
	default: return 0;
	}
	return -1;
}

//Returns a stack containing the postfix expression
stac reversePolish(char infix[])
{
	char e1;
	stac s; //stack which holds the operators
	stac output; //output stack

	//Reads LEFT TO RIGHT
	for (int i = 0; infix[i] != '\0'; i++) {
		e1 = infix[i];

		switch (e1) {
		case '(': s.push(e1); break;

		case ')': {
			while (s.peek() != '(') {
				output.push(s.pop());
			}
			s.pop();
			break;
		}

		case '-':

		case '+':

		case '*':

		case '/': {
			char e2 = s.peek();
			if (precedencePostfix(e1) > precedencePostfix(e2)) {
				s.push(e1);
				break;
			}
			else {
				do {
					output.push(s.pop());
					e2 = s.peek();
				} while (precedencePostfix(e1) <= precedencePostfix(e2));

				s.push(e1);
				break;
			}
		}

		default: output.push(e1); break; //pushes operand to stack
		}
	}

	//pop stack until it's empty
	while (s.size() > 0) {
		output.push(s.pop());
	}

	return output;
}


//Prints infix expression from postfix expression
void postfixToInfix(char* postfix)
{
	stacTwoDim s;
	char element[2];
	char operand1[maximum];
	char operand2[maximum];
	char result[maximum];

	//Reads LEFT TO RIGHT
	for (int i = 0; postfix[i] != '\0'; i++) {
		element[0] = postfix[i];
		element[1] = '\0';

		//Checks if element[0] is an operator
		if (element[0] == '-' || element[0] == '+' || element[0] == '*' || element[0] == '/' || element[0] == '^') {
			strcpy(operand1, s.pop());
			strcpy(operand2, s.pop());
			//(operand2 + element + operand1)
			strcpy(result, "(");
			strcat(result, operand2);
			strcat(result, element);
			strcat(result, operand1);
			strcat(result, ")");
			s.push(result);
		}
		else {
			s.push(element);  //pushes operand to stack
		}
	}

	//prints postfix expression
	for (int i = 0; result[i] != '\0'; i++) {
		std::cout << result[i];
	}
	std::cout << "\n\n";
}


//Prints prefix expression from postfix expression
void postfixToPrefix(char* postfix)
{
	stacTwoDim s;
	char element[2];
	char operand1[maximum];
	char operand2[maximum];
	char result[maximum];

	//Reads LEFT TO RIGHT
	for (int i = 0; postfix[i] != '\0'; i++) {
		element[0] = postfix[i];
		element[1] = '\0';

		//Checks if element[0] is an operator
		if (element[0] == '-' || element[0] == '+' || element[0] == '*' || element[0] == '/' || element[0] == '^') {
			strcpy(operand1, s.pop());
			strcpy(operand2, s.pop());
			//element + operand2 + operand1
			strcpy(result, element);
			strcat(result, operand2);
			strcat(result, operand1);
			s.push(result);
		}
		else {
			s.push(element);  //pushes operand to stack
		}
	}

	//prints infix expression
	for (int i = 0; result[i] != '\0'; i++) {
		std::cout << result[i];
	}
	std::cout << "\n\n";
}
