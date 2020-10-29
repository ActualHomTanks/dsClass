#include <iostream>
#include "doublyLinkedList.hpp"

linkedListDouble::nodeDouble::nodeDouble() {
  next = nullptr;
  prev = nullptr;
  data = 0;
}

linkedListDouble::nodeDouble::nodeDouble(int data) {
  next = nullptr;
  prev = nullptr;
  this->data = data;
}

linkedListDouble::linkedListDouble() : head(nullptr), tail(nullptr) {}


void linkedListDouble::swapLinear(nodeDouble* a, nodeDouble* b) {
  int temp = a->data;
  a->data = b->data;
  b->data = temp;

  return;
}


void linkedListDouble::insertNode(int data, nodeDouble* curr) {
  nodeDouble* newNode = new nodeDouble(data);

  newNode->next = curr->next;
  newNode->prev = curr;
  (curr->next)->prev = newNode;
  curr->next = newNode;

  return;
}


void linkedListDouble::deleteNode(nodeDouble* curr) {
  (curr->prev)->next = curr->next;
  (curr->next)->prev = curr->prev;
  delete curr;
  curr = nullptr;
}


void linkedListDouble::insertHead(int data) {
  nodeDouble* newNode = new nodeDouble(data);

  if(!head) {
    head = newNode;
    tail = newNode;
    return;
  }

  newNode->next = head;
  head->prev = newNode;
  head = newNode;
  return;
}


void linkedListDouble::insertTail(int data) {
  nodeDouble* newNode = new nodeDouble(data);

  if (!head) {
    head = newNode;
    tail = newNode;
    return;
  }

  newNode->prev = tail;
  tail->next = newNode;
  tail = newNode;
  return;
}


void linkedListDouble::insertOrdered(int data) {
  if (!head || head->data >= data) {
    insertHead(data);
    return;
  }

  if (tail->data <= data) {
    insertTail(data);
    return;
  }

  nodeDouble* curr = head;

  while(curr) {
    if (curr->data >= data) {
      insertNode(data, curr->prev);
      return;
    }

    curr = curr->next;
  }
}


void linkedListDouble::insertAfter(int key, int data) {
  if (!head) {
    insertHead(data);
    return;
  }

  nodeDouble* curr = head;

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

  std::cout << "Key not found" << '\n';

}


void linkedListDouble::insertBefore(int key, int data) {
  if (!head || head->data == key) {
    insertHead(data);
    return;
  }

  nodeDouble* curr = head;

  while (curr) {
    if (curr->data == key) {
      insertNode(data, curr->prev);
      return;
    }

    curr = curr->next;
  }

  std::cout << "Key not found" << '\n';
}


void linkedListDouble::insertAtPosition(int position, int data) {
  if (!head || position == 1) {
    insertHead(data);
    return;
  }

  nodeDouble* curr = head;
  int i = 2;

  while (curr->next) {
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


void linkedListDouble::deleteHead() {
  if (!head) {
    std::cout << "Empty List!" << '\n';
    return;
  }

  if(head->next == nullptr) {
    delete head;
    head = nullptr;
    tail = nullptr;
    return;
  }

  nodeDouble* curr = head->next;
  curr->prev = nullptr;
  delete head;
  head = curr;

  return;
}


void linkedListDouble::deleteTail() {
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

  nodeDouble* curr = tail->prev;
  curr->next = nullptr;
  delete tail;
  tail = curr;

  return;
}




void linkedListDouble::deleteKey(int key) {
  if (!head) {
    std::cout << "Empty List!" << '\n';
    return;
  }

  if (head->data == key) {
    deleteHead();
    return;
  }

  if (tail->data == key) {
    deleteTail();
    return;
  }

  nodeDouble* curr = head->next;

  while(curr) {
    if (curr->data == key) {
      deleteNode(curr);
      return;
    }

    curr = curr->next;
  }

  std::cout << "Key not found" << '\n';
}


void linkedListDouble::deleteAtPosition(int position) {
    if (!head) {
      std::cout << "Empty List!" << '\n';
      return;
    }

    if (position == 1) {
      deleteHead();
      return;
    }

    nodeDouble* curr = head->next;
    int i = 2;

    while(curr->next != tail) {
      if (i == position) {
        deleteNode(curr);
        return;
      }

      i++;
      curr = curr->next;
    }

    if (i == position) {
      deleteNode(curr);
      return;
    }

    std::cout << "Position not found!" << '\n';
}


void linkedListDouble::deleteAfter(int key) {
  if (!head) {
    std::cout << "Empty List!" << '\n';
    return;
  }

  nodeDouble* curr = head;

  while(curr->next != tail) {
    if (curr->data == key) {
      deleteNode(curr->next);
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


void linkedListDouble::deleteBefore(int key) {
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

  nodeDouble* curr = (head->next)->next;

  while(curr) {
    if (curr->data == key) {
      deleteNode(curr->prev);
      return;
    }
    curr = curr->next;
  }

  std::cout << "Key not found" << '\n';

  return;
}


void linkedListDouble::sort() {
  nodeDouble* curr = head;
  int swapped;

  do {
    swapped = 0;
    curr = head;

    while (curr->next) {
      if (curr->data > (curr->next)->data) {
        swapLinear(curr, curr->next);
        swapped = 1;
      }
      curr = curr->next;
    }
  } while(swapped);
}


void linkedListDouble::concat(linkedListDouble& b) {
  linkedListDouble& a = *this;

  a.tail->next = b.head;
  b.head->prev = a.tail;
  a.tail = b.tail;
}


void linkedListDouble::merge(linkedListDouble& b) {
  linkedListDouble& a = *this;
  linkedListDouble c;

  nodeDouble* currA = a.head;
  nodeDouble* currB = b.head;

  while (currA && currB) {
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

  while (currA) {
    c.insertTail(currA->data);
    currA = currA->next;
  }

  while (currB) {
    c.insertTail(currB->data);
    currB = currB->next;
  }

  c.display();

  return;
}


void linkedListDouble::reverse() {
  linkedListDouble c;
  linkedListDouble& a = *this;

while (a.head) {
  c.insertTail(a.tail->data);
  a.deleteTail();
}

a.head = c.head;
a.tail = c.tail;
}


int linkedListDouble::getSize() {
  int count = 0;

  nodeDouble* curr = head;

  while(curr) {
    count++;
    curr = curr->next;
  }

  return count;
}


void linkedListDouble::display() {
  if (!head) {
    std::cout << "Empty List!" << '\n';
    return;
  }

  nodeDouble* curr = head;

  while(curr) {
    std::cout << curr->data << ' ';
    curr = curr->next;
  }
  std::cout << '\n';

  return;
}
