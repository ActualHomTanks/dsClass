#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

class linkedListDouble {
  class nodeDouble {
  public:
    int data;
    nodeDouble* next;
    nodeDouble* prev;
    nodeDouble();
    nodeDouble(int data);
  };

private:
  nodeDouble* head;
  nodeDouble* tail;
  void swapLinear(nodeDouble* a, nodeDouble* b);
  void insertNode(int data, nodeDouble* curr);
  void deleteNode(nodeDouble* curr);
public:
  linkedListDouble();
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
  void concat(linkedListDouble& b);
  void merge(linkedListDouble& b);
  void reverse();
  int getSize();
  void display();
};


#endif
