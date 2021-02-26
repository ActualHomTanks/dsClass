#pragma once

class NodeBST
{
private:
	int data = 0;
	NodeBST* lc = nullptr;
	NodeBST* rc = nullptr;

public:
	NodeBST();
	NodeBST(int data);
	void recursive_inorder(NodeBST* root);
	void insert_element(NodeBST*& root, int data);
	void delete_element(NodeBST*& root, int data);
	void search_element(NodeBST*& root, int data);
};

