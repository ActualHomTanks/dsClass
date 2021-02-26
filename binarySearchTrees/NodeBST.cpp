#include <iostream>
#include "NodeBST.hpp"

NodeBST::NodeBST()
{
}

NodeBST::NodeBST(int data) : data(data)
{
}

void NodeBST::recursive_inorder(NodeBST* root)
{
	if (root) {
		recursive_inorder(root->lc);
		std::cout << root->data << " ";
		recursive_inorder(root->rc);
	}
}

void NodeBST::insert_element(NodeBST*& root, int data)
{
	if (!root) {
		root = new NodeBST(data);
		return;
	}

	NodeBST* prev = nullptr;
	NodeBST* curr = root;

	while (curr) {
		prev = curr;
		if (data < curr->data) {
			curr = curr->lc;
		}
		else curr = curr->rc;
	}

	if (data < prev->data) {
		prev->lc = new NodeBST(data);
	}
	else prev->rc = new NodeBST(data);

}

void NodeBST::delete_element(NodeBST*& root, int data)
{
    if (!root) {
        std::cout << "Empty tree\n";
        return;
    }

    NodeBST* prev = nullptr;
    NodeBST* curr = root;

    while (curr && curr->data != data) {
        prev = curr;
        if (data < curr->data)
            curr = curr->lc;
        else
            curr = curr->rc;
    }

    if (curr == nullptr) {
        std::cout << "Key " << data << " not found\n";
        return;
    }

    if (curr->lc == nullptr || curr->rc == nullptr) {

        NodeBST* newCurr = nullptr;

        if (curr->lc == nullptr)
            newCurr = curr->rc;
        else
            newCurr = curr->lc;

        if (prev == nullptr) {
            return;
        }

        if (curr == prev->lc)
            prev->lc = newCurr;
        else
            prev->rc = newCurr;

        delete curr;
    }
    else {
        NodeBST* par = nullptr;
        NodeBST* temp = nullptr;

        temp = curr->rc;
        while (temp->lc) {
            par = temp;
            temp = temp->lc;
        }

        if (par)
            par->lc = temp->rc;
        else
            curr->rc = temp->rc;

        curr->data = temp->data;
        delete temp;
    }
}

void NodeBST::search_element(NodeBST*& root, int data)
{
    if (!root) {
        std::cout << "List is empty\n";
        return;
    }

    NodeBST* curr = root;

    while (curr) {
        if (curr->data == data) {
            std::cout << "Element found\n";
            return;
        }

        if (data < curr->data) {
            curr = curr->lc;
        }
        else curr = curr->rc;
    }

    std::cout << "Element not found\n";
}
