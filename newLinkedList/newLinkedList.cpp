#include <iostream>
#include "newLinkedList.hpp"

linkedList::node::node() : data(0), next(nullptr) {}


linkedList::node::node(int data) : data(data), next(nullptr) {}


linkedList::linkedList() : head(nullptr), tail(nullptr) {}


void linkedList::swapLinear(node* a, node* b) {
  int temp = a->data;
  a->data = b->data;
  b->data = temp;
  return;
}


void linkedList::insertNode(int data, node* curr) {
  node* newNode = new node(data);

  newNode->next = curr->next;
  curr->next = newNode;

  return;
}


void linkedList::deleteNode(node* curr) {
  node* temp = curr->next;
  curr->next = (curr->next)->next;
  delete temp;
  temp = nullptr;
  return;
}


void linkedList::insertHead(int data) {
  node* newNode = new node(data);

  if (!head) {
    head = newNode;
    tail = newNode;
    return;
  }

  newNode->next = head;
  head = newNode;

  return;
}


void linkedList::insertTail(int data) {
  node* newNode = new node(data);

  if (!head) {
    head = newNode;
    tail = newNode;
    return;
  }

  tail->next = newNode;
  tail = newNode;

  return;
}


void linkedList::insertOrdered(int data) {
  if (!head || head->data >= data) {
    insertHead(data);
    return;
  }

  if (tail->data <= data) {
    insertTail(data);
    return;
  }

  node* curr = head;
  while (curr->next) {
    if ((curr->next)->data >= data) {
      insertNode(data, curr);
      return;
    }
    curr = curr->next;
  }
}


void linkedList::insertAfter(int key, int data) {
  if (!head) {
    insertHead(data);
    return;
  }

  node* curr = head;
  while (curr->next) {
    if (curr->data == key) {
      insertNode(data, curr);
      return;
    }
    curr = curr->next;
  }

  if (curr->data == key) {
    insertTail(data);
    return;
  }

  std::cout << "Key Not Found!" << '\n';
  return;
}


void linkedList::insertBefore(int key, int data) {
  if (!head || head->data == key) {
    insertHead(data);
    return;
  }

  node* prev = head;
  node* curr = head->next;
  while(curr) {
    if (curr->data == key) {
      insertNode(data, prev);
      return;
    }

    prev = curr;
    curr = curr->next;
  }

  std::cout << "Key not found" << '\n';
}


void linkedList::insertAtPosition(int position, int data) {
  if (!head || position == 1) {
    insertHead(data);
    return;
  }

  node* curr = head;
  int i = 2;

  while(curr->next) {
    if (i == position) {
      insertNode(data, curr);
      return;
    }

    i++;
    curr = curr->next;
  }

  if (i == position) {
    insertTail(data);
    return;
  }

  std::cout << "Position not found" << '\n';
}


void linkedList::deleteHead() {
  if(!head) {
    std::cout << "Empty List" << '\n';
    return;
  }

  if (head->next) {
    delete head;
    head = nullptr;
    tail = nullptr;
    return;
  }

  node* temp = head;
  head = head->next;
  delete temp;
  temp = nullptr;

  return;
}


void linkedList::deleteTail() {
  if (!head) {
    std::cout << "Empty List!" << '\n';
    return;
  }

  if (head->next == nullptr) {
    delete head;
    head = nullptr;
    tail = nullptr;
    return;
  }

  node* curr = head;
  while(curr->next != tail) {
    curr = curr->next;
  }

  delete tail;
  tail = curr;
  tail->next = nullptr;

  return;
}


void linkedList::deleteKey(int key) {
  if (!head) {
    std::cout << "Empty List!" << '\n';
    return;
  }

  if (head->data == key) {
    deleteHead();
    return;
  }

  node* prev = head;
  node* curr = head->next;
  while(curr->next) {
    if (curr->data == key) {
      deleteNode(prev);
      return;
    }
    prev = curr;
    curr = curr->next;
  }

  if (curr->data == key) {
    deleteTail();
    return;
  }

  std::cout << "Key not found" << '\n';
}


void linkedList::deleteAtPosition(int position) {
  if (!head) {
    std::cout << "Empty List!" << '\n';
    return;
  }

  if (position == 1) {
    deleteHead();
    return;
  }

  node* curr = head;
  int i = 2;

  while (curr->next != tail) {
    if (i == position) {
      deleteNode(curr);
      return;
    }
    curr = curr->next;
    i++;
  }

  if (i == position) {
    deleteTail();
    return;
  }

  std::cout << "Position not found" << '\n';
  return;
}


void linkedList::deleteAfter(int key) {
  if (!head) {
    std::cout << "Empty List!" << '\n';
    return;
  }

  node* curr = head;
  while(curr->next != tail) {
    if (curr->data == key) {
      deleteNode(curr);
      return;
    }
    curr = curr->next;
  }

  if (curr->data == key) {
    deleteTail();
    return;
  }

  curr = curr->next;

  if (curr->data == key) {
    std::cout << "No node after key" << '\n';
    return;
  }

  std::cout << "Key not found" << '\n';

  return;
}


void linkedList::deleteBefore(int key) {
  if (!head) {
    std::cout << "Empty List!" << '\n';
    return;
  }

  if (head->data == key) {
    std::cout << "No node before key" << '\n';
    return;
  }

  if ((head->next)->data == key) {
    deleteHead();
    return;
  }

  node* curr = (head->next)->next;
  node* prev = head->next;

  while(curr) {
    if ((curr->next)->data == key) {
      deleteNode(prev);
      return;
    }

    prev = curr;
    curr = curr->next;
  }

  std::cout << "Key not found!" << '\n';
  return;
}


void linkedList::sort() {
  node* curr = head;
  bool swapped = false;

  do {
    swapped = false;
    curr = head;

    while(curr->next) {
      if (curr->data > (curr->next)->data) {
        swapLinear(curr, curr->next);
        swapped = true;
      }
      curr = curr->next;
    }
  } while(swapped);
}


void linkedList::concat(linkedList& b) {
  linkedList& a = *this;

  a.tail->next = b.head;
  a.tail = b.tail;
  return;
}


void linkedList::merge(linkedList& b) {
  linkedList& a = *this;
  linkedList c;

  node* currA = a.head;
  node* currB = b.head;

  while(currA && currB) {
    if (currA->data == currB->data) {
      c.insertTail(currA->data);
      currA = currA->next;
      currB = currB->next;
    }
    else if (currA->data < currB->data) {
      c.insertTail(currA->data);
      currA = currA->next;
    }
    else {
      c.insertTail(currB->data);
      currB = currB->next;
    }
  }

  while(currA) {
    c.insertTail(currA->data);
    currA = currA->next;
  }

  while(currB) {
    c.insertTail(currB->data);
    currB = currB->next;
  }

  c.display();

  return;
}

void linkedList::reverse() {
  linkedList& a = *this;
  linkedList c;

  while(a.head) {
    c.insertTail(a.tail->data);
    a.deleteTail();
  }

  a.head = c.head;
  a.tail = c.tail;

  return;
}


int linkedList::getSize() {
  int count = 0;

  node* curr = head;
  while(curr) {
    count++;
    curr = curr->next;
  }

  return count;
}


void linkedList::display() {
  if (!head) {
    std::cout << "Empty List!" << '\n';
    return;
  }

  node* curr = head;

  while(curr) {
    std::cout << curr->data << ' ';
    curr = curr->next;
  }

  std::cout << '\n';

  return;
}
