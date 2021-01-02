#include <iostream>
#include "binaryTree.hpp"

int main() {
  node n;
  node* root = nullptr;
  int meth;


  while(true) {
    std::cout << "1.InsertNode  2.RecursivePreorder  3.RecursiveInorder  4.RecursivePostorder  5.IterateInorder  6.Display" << '\n';
    std::cin >> meth;
    switch(meth) {
      case 1: {
        int info;
        std::cin >> info;
        char path[10];
        std::cin >> path;
        n.createBT(root, info, path);
        break;
      }
      case 2: {
        n.recursivePreorder(root);
        break;
      }
      case 3: {
        n.recursiveInorder(root);
        break;
      }
      case 4: {
        n.recursivePostorder(root);
        break;
      }
      case 5: {
        n.iterateInorder(root);
        break;
      }
      case 6:
        int level;
        level = 0;
        n.display(root, level);
        break;
    }
  }
}
