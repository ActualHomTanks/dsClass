#include <iostream>
#include <cstring>
#include "Stack.hpp"


Stack::Stack()
{
}

void Stack::push(char n)
{
	if (top == MAX - 1) {
		return;
	}

	arr[++top] = n;
}

char Stack::pop()
{
	if (top == -1) {
		std::cout << "Empty!\n";
		return 0;
	}

	return arr[top--];
}

char Stack::peek() const
{
	if (empty()) {
		std::cout << "Stack is empty\n";
		return 0;
	}

	return arr[top];
}

bool Stack::empty() const
{
	if (top == -1) {
		return true;
	}
	else return false;
}

void Stack::display()
{
	for (int i = 0; i <= top; i++) {
		std::cout << arr[i] << " ";
	}

	std::cout << "\n";
}



IntStack::IntStack()
{
}

void IntStack::push(int n)
{
	if (top == MAX - 1) {
		return;
	}

	arr[++top] = n;
}

int IntStack::pop()
{
	if (top == -1) {
		std::cout << "Empty!\n";
		return 0;
	}

	return arr[top--];
}

bool IntStack::empty()
{
	if (top == -1) {
		return true;
	}
	else return false;
}

void IntStack::display()
{
	for (int i = 0; i <= top; i++) {
		std::cout << arr[i] << " ";
	}

	std::cout << "\n";
}



DoubleStack::DoubleStack()
{
}

void DoubleStack::push(double n)
{
	if (top == MAX - 1) {
		return;
	}

	arr[++top] = n;
}

double DoubleStack::pop()
{
	if (top == -1) {
		std::cout << "Empty!\n";
		return 0;
	}

	return arr[top--];
}

bool DoubleStack::empty()
{
	if (top == -1) {
		return true;
	}
	else return false;
}

void DoubleStack::display()
{
	for (int i = 0; i <= top; i++) {
		std::cout << arr[i] << " ";
	}

	std::cout << "\n";
}


StringStack::StringStack()
{
}

void StringStack::push(char n[])
{
	if (top == MAX - 1) {
		std::cout << "Stack will Overflow!" << '\n';
		return;
	}

	strcpy_s(arr[++top], n);
	return;
}

char* StringStack::pop()
{
	if (empty()) {
		std::cout << "Empty!\n";
		return 0;
	}

	return arr[top--];
}

bool StringStack::empty()
{
	if (top == -1) {
		return true;
	}
	else return false;
}

void StringStack::display()
{
	for (int i = 0; i <= top; i++) {
		std::cout << arr[i] << " ";
	}

	std::cout << "\n";
}



NodePointerStack::NodePointerStack()
{
}

void NodePointerStack::push(Node* n)
{
	if (top == MAX - 1) {
		return;
	}

	arr[++top] = n;
}

Node* NodePointerStack::pop()
{
	if (top == -1) {
		std::cout << "Empty!\n";
		return 0;
	}

	return arr[top--];
}

Node* NodePointerStack::peek() const
{
	if (empty()) {
		return 0;
	}

	return arr[top];
}

bool NodePointerStack::empty() const
{
	if (top == -1) {
		return true;
	}
	else return false;
}

void NodePointerStack::display()
{
	for (int i = 0; i <= top; i++) {
		std::cout << arr[i]->get_data() << " ";
	}

	std::cout << "\n";
}
