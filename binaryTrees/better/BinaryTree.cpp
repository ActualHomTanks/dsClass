#include <iostream>
#include <cstring>
#include "Stack.hpp"
#include "BinaryTree.hpp"

Node::Node() {}

Node::Node(int data) : data(data) {}

void Node::create_BT(Node*& root, int data, char const path[]) {
    if (!root) {
        root = new Node(data);
        return;
    }

    Node* prev = nullptr;
    Node* curr = root;

    int i = 0;
    for (i = 0; i < strlen(path); i++) {
        if (!curr) {
            break;
        }

        prev = curr;

        if (path[i] == 'L') {
            curr = curr->lc;
        }
        else if (path[i] == 'R') {
            curr = curr->rc;
        }

    }

    if (curr != nullptr || i != strlen(path)) {
        std::cout << "Impossible\n";
        return;
    }

    Node* temp = new Node(data);

    if (path[i - 1] == 'L') {
        prev->lc = temp;
    }
    else if (path[i - 1] == 'R') {
        prev->rc = temp;
    }

    return;
}


void Node::recursivePreorder(Node*& root)
{
    if (root) {
        std::cout << root->info << ' ';
        recursivePreorder(root->lc);
        recursivePreorder(root->rc);
    }
    std::cout << '\n';
}


void Node::recursiveInorder(Node*& root)
{
    if (root) {
        recursiveInorder(root->lc);
        std::cout << root->info << ' ';
        recursiveInorder(root->rc);
    }
    std::cout << '\n';
}


void Node::recursivePostorder(Node*& root)
{
    if (root) {
        recursivePostorder(root->lc);
        recursivePostorder(root->rc);
        std::cout << root->info << ' ';
    }
    std::cout << '\n';
}


void Node::inorder_iter(Node*& root) {
    if (!root) {
        return;
    }

    NodePointerStack s;

    Node* curr = root;

    while (curr || !s.empty()) {
        while (curr) {
            s.push(curr);
            curr = curr->lc;
        }

        curr = s.pop();

        std::cout << curr->data << " ";

        curr = curr->rc;
    }

    std::cout << std::endl;

}

void Node::postorder_iter(Node*& root) {

    if (!root) {
        return;
    }

    NodePointerStack s;
    Node* curr = root;

    do
    {
        while (curr)
        {
            if (curr->rc) {
                s.push(curr->rc);
            }

            s.push(curr);
            curr = curr->lc;
        }

        curr = s.pop();

        if (curr->rc && s.peek() == curr->rc)
        {
            s.pop();
            s.push(curr);
            curr = curr->rc;
        }
        else
        {
            std::cout << curr->data << " ";
            curr = nullptr;
        }
    } while (!s.empty());

    std::cout << std::endl;
}


void Node::preorder_iter(Node*& root) {
    if (root == NULL)
        return;

    Node* curr = root;

    NodePointerStack nodeStack;
    nodeStack.push(curr);

    while (!nodeStack.empty()) {
        Node* node = nodeStack.pop();
        std::cout << node->data << " ";

        if (node->rc)
            nodeStack.push(node->rc);
        if (node->lc)
            nodeStack.push(node->lc);
    }

    std::cout << std::endl;

}

int Node::count_leaf_nodes(Node*& root) {
    if(!root) {
        return 0;
    }

    Node* node = root;

    if(node->lc == nullptr && node->rc == nullptr) {
        return 1;
    }
    else {
        return count_leaf_nodes(node->lc) + count_leaf_nodes(node->rc);
    }
}

void Node::display(node*& root, int level)
{
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
