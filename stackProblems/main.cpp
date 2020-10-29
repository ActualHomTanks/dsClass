#include <iostream>
#include "2dstack.hpp"
using std::cout;
using std::cin;

int main() {
  int meth;
  stacTwoDim s;

  while (true) {
    std::cout << "1.Push\t2.Pop\t3.Peek\t4.Size\t5.Empty\t6.Full\t7.DisplayStack\t8.Exit: ";
    cin >> meth;

    switch (meth) {
      case 1: {
        char row[maximum];

        std::cout << "Enter String: ";
        cin >> row;

        s.push(row);
        break;
      }

      case 2: {
        char* row;
        row = s.pop();
        if (row == 0) {
          std::cout << "Stack is empty" << '\n';
          break;
        }
        else {
          std::cout << row << '\n';
        }
        break;
      }

      case 3: {
        char* row;
        row = s.peek();
        if (row == 0) {
          std::cout << "Stack is empty" << '\n';
          break;
        }
        else {
          std::cout << row << '\n';
        }
        break;
      }

      case 4: {
        int n;
        n = s.size();
        std::cout << n << '\n';
        break;
      }

      case 5: {
        std::cout << s.empty() << '\n';
        break;
      }

      case 6: {
        std::cout << s.full() << '\n';
        break;
      }

      case 7: {
        s.display();
        break;
      }

      case 8: {
        return EXIT_SUCCESS;
      }
    }
  }
  return 0;
}
