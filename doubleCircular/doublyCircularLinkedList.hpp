#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

class linkedListDoubleCircular {
  class nodeDoubleCircular {
  public:
    int data;
    nodeDoubleCircular* next;
    nodeDoubleCircular* prev;
    nodeDoubleCircular();
    nodeDoubleCircular(int data);
  };

private:
  nodeDoubleCircular* head;
  nodeDoubleCircular* tail;
  void swapLinear(nodeDoubleCircular* a, nodeDoubleCircular* b);
  void insertNode(int data, nodeDoubleCircular* curr);
  void deleteNode(nodeDoubleCircular* curr);
public:
  linkedListDoubleCircular();
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
  void concat(linkedListDoubleCircular& b);
  void merge(linkedListDoubleCircular& b);
  void reverse();
  int getSize();
  void display();
};


#endif
