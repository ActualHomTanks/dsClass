#ifndef BINARY_TREE
#define BINARY_TREE

class node {
  int info;
  node* lc;
  node* rc;

public:
  node();
  node(int info);
  void createBT (node*& root, int info, char path[]);
  void recursivePreorder(node*& root);
  void recursiveInorder(node*& root);
  void recursivePostorder(node*& root);
  void iterateInorder(node*& root);
  void display(node*& root, int level);
};

#endif
