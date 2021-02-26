#include <iostream>
#include "NodeBST.hpp"

int main()
{
	NodeBST* root = nullptr;
	NodeBST n;

	n.insert_element(root, 5);
	n.insert_element(root, 10);
	n.insert_element(root, 30);
	n.insert_element(root, 3);
	n.insert_element(root, 34);
	n.insert_element(root, 78);
	n.insert_element(root, 9);

	n.recursive_inorder(root);
	std::cout << std::endl;

	n.delete_element(root, 30);
	n.delete_element(root, 5);

	n.recursive_inorder(root);
	std::cout << std::endl;

	n.search_element(root, 5);
	n.search_element(root, 10);
}