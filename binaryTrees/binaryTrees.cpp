#include <iostream>
#include "binaryTree.hpp"
#include "singleStack.hpp"
#include <cstring>

node::node() : info(0), lc(nullptr), rc(nullptr) {}

node::node(int info) : info(info), lc(nullptr), rc(nullptr) {}

void node::createBT(node*& root, int info, char path[]) {

  if (!root) {
    root = new node(info);
    return;
  }

  node* curr = root;
  node* prev = nullptr;
  unsigned int i;

  for (i = 0; i < strlen(path); i++) {
    if (!curr) {
      break;
    }
    prev = curr;

    if (path[i] == 'L') {
      curr = curr->lc;
    }
    else {
      curr = curr->rc;
    }
  }

  if (curr != nullptr || i != strlen(path)) {
    std::cout << "Impossible" << '\n';
    return;
  }

  node* temp = new node(info);

  if (path[i-1] == 'L') {
    prev->lc = temp;
  }
  else {
    prev->rc = temp;
  }

  return;
}


void node::recursivePreorder(node*& root) {
  if (root) {
    std::cout << root->info << ' ';
    recursivePreorder(root->lc);
    recursivePreorder(root->rc);
  }
  std::cout << '\n';
}


void node::recursiveInorder(node*& root) {
  if (root) {
    recursiveInorder(root->lc);
    std::cout << root->info << ' ';
    recursiveInorder(root->rc);
  }
  std::cout << '\n';
}


void node::recursivePostorder(node*& root) {
  if (root) {
    recursivePostorder(root->lc);
    recursivePostorder(root->rc);
    std::cout << root->info << ' ';
  }
  std::cout << '\n';
}


void node::iterateInorder(node*& root) {
  stacInt s;

  node* curr = root;
  node* prev = nullptr;

  while (true){
    while(curr) {
      s.push(curr->info);
      prev = curr;
      curr = curr->lc;
    }

    std::cout << s.pop() << ' ';

    if (!prev->rc && s.empty()) {
      return;
    }

    if(!prev->rc) {
      std::cout << s.pop() << ' ';
    }

    curr = prev->rc;
  }

  std::cout << '\n';
}


void node::display(node*& root, int level) {
  if (!root) {
    return;
  }

  display(root->rc, level + 1);

  for (int i = 0; i < level; i++) {
    std::cout << "    ";
  }

  std::cout << root->info << '\n';
  display(root->lc, level + 1);
}
