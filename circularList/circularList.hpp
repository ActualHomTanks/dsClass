#ifndef CIRCULAR_LINKED_LIST
#define CIRCULAR_LINKED_LIST

#include <iostream>

class linkedListCircular {
  class nodeCircular {
  public:
    nodeCircular* next;
    int data;
    nodeCircular();
    nodeCircular(int data);
  };
public:
  nodeCircular* head;
  nodeCircular* tail;
  void swapLinear(nodeCircular* a, nodeCircular* b);
  void insertNode(int data, nodeCircular* curr);
  void deleteNode(nodeCircular* curr);
public:
  linkedListCircular();
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
  int getSize();
  void sort();
  void concat(linkedListCircular& b);
  void merge(linkedListCircular& b);
  void reverse();
  void display();
};


#endif
