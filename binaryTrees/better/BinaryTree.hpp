#pragma once

class Node {
private:
    int data = 0;
    Node* lc = nullptr;
    Node* rc = nullptr;
public:
    Node();
    Node(int data);
    void create_BT(Node*& root, int data, char const path[]);
    void recursivePreorder(Node*& root);
    void recursiveInorder(Node*& root);
    void recursivePostorder(Node*& root);
    void inorder_iter(Node*& root);
    void postorder_iter(Node*& root);
    void preorder_iter(Node*& root);
    int count_leaf_nodes(Node*& root);
    void display(Node*& root, int level);
    int get_data() { return data; }
};
