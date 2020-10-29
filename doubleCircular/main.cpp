#include <iostream>
#include "doublyCircularLinkedList.hpp"

int main() {
  int meth, data, key, position;
  linkedListDoubleCircular l;

  while(true) {
    std::cout << "1. InsertHead  2. InsertTail  3. InsertOrdered  4. InsertAfter  5. InsertBefore" << '\n';
    std::cout << "6. InsertAtPosition  7. DeleteHead  8. DeleteTail  9.DeleteKey  10. DeleteAtPosition  11. DeleteAfter" << '\n';
    std::cout << "12. DeleteBefore  13. Size  14. DisplayList  15. Sort  16. Concatenate  17. Merge  18. Reverse  19. Exit" << '\n';
    std::cin >> meth;

    switch (meth) {
      case 1: {
        std::cout << "Enter Element: ";
        std::cin >> data;

        l.insertHead(data);
        break;
      }
      case 2: {
        std::cout << "Enter Element: ";
        std::cin >> data;

        l.insertTail(data);
        break;
      }
      case 3: {
        std::cout << "Enter Element: ";
        std::cin >> data;

        l.insertOrdered(data);
        break;
      }
      case 4: {
        std::cout << "Enter key: ";
        std::cin >> key;

        std::cout << "Enter Element: ";
        std::cin >> data;

        l.insertAfter(key, data);
        break;
      }
      case 5: {
        std::cout << "Enter key: ";
        std::cin >> key;

        std::cout << "Enter Element: ";
        std::cin >> data;

        l.insertBefore(key, data);
        break;
      }
      case 6: {
        std::cout << "Enter position: ";
        std::cin >> position;

        std::cout << "Enter Element: ";
        std::cin >> data;

        l.insertAtPosition(position, data);
        break;
      }
      case 7: {
        l.deleteHead();
        break;
      }
      case 8: {
        l.deleteTail();
        break;
      }
      case 9: {
        std::cout << "Enter key: ";
        std::cin >> key;

        l.deleteKey(key);
        break;
      }
      case 10: {
        std::cout << "Enter position: " << '\n';
        std::cin >> position;

        l.deleteAtPosition(position);
        break;
      }
      case 11: {
        std::cout << "Enter Key: " << '\n';
        std::cin >> key;

        l.deleteAfter(key);
        break;
      }
      case 12: {
        std::cout << "Enter Key: " << '\n';
        std::cin >> key;

        l.deleteBefore(key);
        break;
      }
      case 13: {
        std::cout << l.getSize() << '\n';
        break;
      }
      case 14: {
        l.display();
        break;
      }
      case 15: {
        l.sort();
        l.display();
        break;
      }
      case 16: {
        linkedListDoubleCircular l2;
        l2.insertTail(5);
        l2.insertTail(7);
        l2.insertTail(9);
        std::cout << "Concatenating with: ";
        l2.display();

        l.concat(l2);

        l.display();
        break;
      }
      case 17: {
        linkedListDoubleCircular l2;
        l2.insertTail(5);
        l2.insertTail(7);
        l2.insertTail(9);
        std::cout << "Merging with: ";
        l2.display();

        l.merge(l2);
        break;
      }
      case 18: {
        l.reverse();
        l.display();
        break;
      }
      case 19: {
        return EXIT_SUCCESS;
      }
      default: continue;
    }
    std::cout << "-----------------------------------------------------------------------------" << "\n\n";
  }

}
