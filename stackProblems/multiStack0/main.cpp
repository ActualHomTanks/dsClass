#include <iostream>
#include "multiStack.hpp"

using namespace std;

int main() {
 int numStack;
 int currStack;
 int meth;

 std::cout << "How many stacks: ";
 cin >> numStack;

 multiStac s(numStack);

 while (true) {

   std::cout << "Which Stack to perform operation: ";
   cin >> currStack;
   currStack--;

   cout << "1.Push\t2.Pop\t3.Peek\t4.Size\t5.Empty\t6.Full\t7.DisplayStack\t8.Exit: ";
   cin >> meth;

   switch(meth) {
     case 1: {
       char n;
       cout << "Enter element to push: ";
       cin >> n;
       s.push(n, currStack);
       cout << n << " Pushed" << endl;
       break;
     }

     case 2: {
       char n = s.pop(currStack);
       std::cout << n << " Popped" << '\n';
       break;
     }

     case 3: {
       char n = s.peek(currStack);
       cout << n << " is at the top" << endl;
       break;
     }

     case 4: {
       int n = s.size(currStack);
       std::cout << n << " Elements" << '\n';
       break;
     }

     case 5: {
       if (s.empty(currStack)) {
         cout << "Stack is empty" << endl;
         break;
       }
       else {
         cout << "Stack is not empty" << endl;
         break;
       }
     }

     case 6: {
       if (s.full(currStack)) {
         cout << "Stack is full" << endl;
         break;
       }
       else {
         cout << "Stack is not full" << endl;
         break;
       }
     }

     case 7: {
       s.display(currStack);
       break;
     }

     case 8: return EXIT_SUCCESS;

     default: return EXIT_SUCCESS;
  }
 }
 return 0;
}
