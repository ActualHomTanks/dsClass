#include <iostream>
#include "circularList.hpp"

linkedListCircular::nodeCircular::nodeCircular() : next(nullptr), data(0) {}


linkedListCircular::nodeCircular::nodeCircular(int data) : next(nullptr), data(data) {}


linkedListCircular::linkedListCircular() : head(nullptr), tail(nullptr) {}


void linkedListCircular::swapLinear(nodeCircular* a, nodeCircular* b) {
  int temp = a->data;
  a->data = b->data;
  b->data = temp;
  return;
}


void linkedListCircular::insertNode(int data, nodeCircular* curr) {
  nodeCircular* newNode = new nodeCircular(data);

  newNode->next = curr->next;
  curr->next = newNode;

  return;
}


void linkedListCircular::deleteNode(nodeCircular* curr) {
  nodeCircular* temp = curr->next;
  curr->next = (curr->next)->next;
  delete temp;
  temp = nullptr;
  return;
}


void linkedListCircular::insertHead(int data) {
  nodeCircular* newNode = new nodeCircular(data);

  if (!head) {
    head = newNode;
    tail = newNode;
    newNode->next = head;
    return;
  }

  newNode->next = head;
  head = newNode;
  tail->next = head;

  return;
}


void linkedListCircular::insertTail(int data) {
  nodeCircular* newNode = new nodeCircular(data);

  if (!head) {
    head = newNode;
    tail = newNode;
    newNode->next = head;
    return;
  }

  tail->next = newNode;
  tail = newNode;
  tail->next = head;

  return;
}


void linkedListCircular::insertOrdered(int data) {
  if (!head || head->data >= data) {
    insertHead(data);
    return;
  }

  if (tail->data <= data) {
    insertTail(data);
    return;
  }

  nodeCircular* curr = head;
  while (curr->next != head) {
    if ((curr->next)->data >= data) {
      insertNode(data, curr);
      return;
    }
    curr = curr->next;
  }
}


void linkedListCircular::insertAfter(int key, int data) {
  if (!head) {
    insertHead(data);
    return;
  }

  nodeCircular* curr = head;
  while (curr->next != head) {
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


void linkedListCircular::insertBefore(int key, int data) {
  if (!head || head->data == key) {
    insertHead(data);
    return;
  }

  nodeCircular* prev = head;
  nodeCircular* curr = head->next;
  while(curr != head) {
    if (curr->data == key) {
      insertNode(data, prev);
      return;
    }

    prev = curr;
    curr = curr->next;
  }

  std::cout << "Key not found" << '\n';
}


void linkedListCircular::insertAtPosition(int position, int data) {
  if (!head || position == 1) {
    insertHead(data);
    return;
  }

  nodeCircular* curr = head;
  int i = 2;

  while(curr->next != head) {
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


void linkedListCircular::deleteHead() {
  if(!head) {
    std::cout << "Empty List" << '\n';
    return;
  }

  if (head->next == head) {
    delete head;
    head = nullptr;
    tail = nullptr;
    return;
  }

  tail->next = head->next;
  delete head;
  head = tail->next;

  return;
}


void linkedListCircular::deleteTail() {
  if (!head) {
    std::cout << "Empty List!" << '\n';
    return;
  }

  if (head->next == head) {
    delete head;
    head = nullptr;
    tail = nullptr;
    return;
  }

  nodeCircular* curr = head;
  while(curr->next != tail) {
    curr = curr->next;
  }

  delete tail;
  tail = curr;
  tail->next = head;

  return;
}


void linkedListCircular::deleteKey(int key) {
  if (!head) {
    std::cout << "Empty List!" << '\n';
    return;
  }

  if (head->data == key) {
    deleteHead();
    return;
  }

  nodeCircular* prev = head;
  nodeCircular* curr = head->next;
  while(curr->next != head) {
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


void linkedListCircular::deleteAtPosition(int position) {
  if (!head) {
    std::cout << "Empty List!" << '\n';
    return;
  }

  if (position == 1) {
    deleteHead();
    return;
  }

  nodeCircular* curr = head;
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


void linkedListCircular::deleteAfter(int key) {
  if (!head) {
    std::cout << "Empty List!" << '\n';
    return;
  }

  nodeCircular* curr = head;
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


void linkedListCircular::deleteBefore(int key) {
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

  nodeCircular* curr = (head->next)->next;
  nodeCircular* prev = head->next;

  while(curr != head) {
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


void linkedListCircular::sort() {
  nodeCircular* curr = head;
  bool swapped = false;

  do {
    swapped = false;
    curr = head;

    while(curr->next != head) {
      if (curr->data > (curr->next)->data) {
        swapLinear(curr, curr->next);
        swapped = true;
      }
      curr = curr->next;
    }
  } while(swapped);
}


void linkedListCircular::concat(linkedListCircular& b) {
  linkedListCircular& a = *this;

  a.tail->next = b.head;
  a.tail = b.tail;
  a.tail->next = a.head;
}


void linkedListCircular::merge(linkedListCircular& b) {
  linkedListCircular& a = *this;
  linkedListCircular c;

  nodeCircular* currA = a.head;
  nodeCircular* currB = b.head;
  int a_size = a.getSize();
  int b_size = b.getSize();

  while (a_size && b_size) {
    if (currA->data == currB->data) {
      c.insertTail(currA->data);
      currA = currA->next;
      currB = currB->next;
      a_size--;
      b_size--;
    }
    else if (currA->data < currB->data) {
      c.insertTail(currA->data);
      currA = currA->next;
      a_size--;
    }
    else {
      c.insertTail(currB->data);
      currB = currB->next;
      b_size--;
    }
  }

  while(a_size) {
    c.insertTail(currA->data);
    currA = currA->next;
    a_size--;
  }

  while(b_size) {
    c.insertTail(currB->data);
    currB = currB->next;
    b_size--;
  }

  c.display();

  return;
}

void linkedListCircular::reverse() {
  linkedListCircular& a = *this;
  linkedListCircular c;

  while(a.head) {
    c.insertTail(a.tail->data);
    a.deleteTail();
  }

  a.head = c.head;
  a.tail = c.tail;

  return;
}


int linkedListCircular::getSize() {
  int count = 0;

  if(!head) {
    return count;
  }

  nodeCircular* curr = head;
  do {
    count++;
    curr = curr->next;
  } while(curr != head);

  return count;
}


void linkedListCircular::display() {
  if (!head) {
    std::cout << "Empty List!" << '\n';
    return;
  }

  nodeCircular* curr = head;

  do {
    std::cout << curr->data << ' ';
    curr = curr->next;
  } while(curr != head);

  std::cout << '\n';

  return;
}
