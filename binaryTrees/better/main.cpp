#include <iostream>
#include "BinaryTree.hpp"

int main()
{
	Node n;
	Node* root = nullptr;
	n.create_BT(root, 5, "L");
	n.create_BT(root, 10, "L");
	n.create_BT(root, 15, "LL");
	n.create_BT(root, 2, "R");
	n.create_BT(root, 7, "LR");
	n.create_BT(root, 45, "RR");
	n.create_BT(root, 789, "LLR");
	
	std::cout << "Inorder:\n";
	n.inorder_iter(root);
	std::cout << "Postorder:\n";
	n.postorder_iter(root);
	std::cout << "Preorder:\n";
	n.preorder_iter(root);

	std::cout << "Leaf Nodes:\n";
	std::cout << n.count_leaf_nodes(root);

}
