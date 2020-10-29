#ifndef LINKED_LIST
#define LINKED_LIST

//This definition of single linked list has a tail pointer which points to the
//last element. This is a valid method which sir mentioned in class.
//However this implementation is slightly different than the one shown in class.

//A node class is encapsulated inside a linked list class. The benefit of this
//technique is that we don't need to pass pointers around from main to method
//functions (no member functions return any pointer that you have to manually
//keep track of and store in main, they're all void functions).
//The start pointer (called head in this implementation) is inside
//the linked list class.
class linkedList {
  class node {
  public:
    int data;
    node* next;
    node();
    node(int data);
  };

private:
  node* head; //points to the first element of the list (another name for 'start' pointer)
  node* tail; //points to the last element of the list.
  void swapLinear(node* a, node* b);
  void insertNode(int data, node* curr);
  void deleteNode(node* curr);
public:
  linkedList();
  void insertHead(int data);
  void insertTail(int data);
  void insertOrdered(int data);
  void insertAfter(int key, int data);
  void insertBefore(int key, int data);
  void insertAtPosition(int position, int data);
  void deleteHead();
  void deleteTail();
  void deleteKey(int key);
  void deleteAtPosition(int position);
  void deleteAfter(int key);
  void deleteBefore(int key);
  void sort();
  void concat(linkedList& b);
  void merge(linkedList& b);
  void reverse();
  int getSize();
  void display();
};

#endif
