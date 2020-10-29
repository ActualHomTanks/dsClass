#include <iostream>
#include <cstdlib>

#include "singleQueue.hpp"

int main() {
  int meth;
  cque q;

  while(true) {
    std::cout << "1.Enque\t2.Deque\t3.Peek\t4.Size\t5.Empty\t6.Full\t7.DisplayQueue\t8.Exit: ";
    std::cin >> meth;

    switch (meth) {
      case 1: {
        char n;
        std::cout << "Enter element to queue: ";
        std::cin >> n;
        q.enque(n);
        std::cout << n << " Enqueued" << '\n';
        break;
      }

      case 2:{
        char n = q.deque();
        std::cout << n << " Dequeued" << '\n';
        break;
      }

      case 3: {
        char n = q.peek();
        std::cout << n << " is at the front" << '\n';
        break;
      }

      case 4: {
        int n = q.size();
        std::cout << n << " elements" << '\n';
        break;
      }

      case 5: {
        if (q.empty()) {
          std::cout << "Queue is empty" << '\n';
          break;
        }
        else {
          std::cout << "Queue is not empty" << '\n';
          break;
        }
      }

      case 6: {
        if (q.full()) {
          std::cout << "Queue is full" << '\n';
          break;
        }
        else {
          std::cout << "Queue is not full" << '\n';
          break;
        }
      }

      case 7: {
        q.display();
        break;
      }

      case 8: {
        return EXIT_SUCCESS;
      }
    }
  }
  return 0;
}
