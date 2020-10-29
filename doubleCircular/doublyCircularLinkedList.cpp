#include <iostream>
#include "doublyCircularLinkedList.hpp"

linkedListDoubleCircular::nodeDoubleCircular::nodeDoubleCircular() {
  next = nullptr;
  prev = nullptr;
  data = 0;
}

linkedListDoubleCircular::nodeDoubleCircular::nodeDoubleCircular(int data) {
  next = nullptr;
  prev = nullptr;
  this->data = data;
}

linkedListDoubleCircular::linkedListDoubleCircular() : head(nullptr), tail(nullptr) {}


void linkedListDoubleCircular::swapLinear(nodeDoubleCircular* a, nodeDoubleCircular* b) {
  int temp = a->data;
  a->data = b->data;
  b->data = temp;

  return;
}


void linkedListDoubleCircular::insertNode(int data, nodeDoubleCircular* curr) {
  nodeDoubleCircular* newNode = new nodeDoubleCircular(data);

  newNode->next = curr->next;
  newNode->prev = curr;
  (curr->next)->prev = newNode;
  curr->next = newNode;

  return;
}


void linkedListDoubleCircular::deleteNode(nodeDoubleCircular* curr) {
  (curr->prev)->next = curr->next;
  (curr->next)->prev = curr->prev;
  delete curr;
  curr = nullptr;
}


void linkedListDoubleCircular::insertHead(int data) {
  nodeDoubleCircular* newNode = new nodeDoubleCircular(data);

  if(!head) {
    head = newNode;
    tail = newNode;
    newNode->next = head;
    newNode->prev = tail;
    return;
  }

  newNode->next = head;
  head->prev = newNode;
  head = newNode;
  head->prev = tail;
  tail->next = head;
  return;
}


void linkedListDoubleCircular::insertTail(int data) {
  nodeDoubleCircular* newNode = new nodeDoubleCircular(data);

  if (!head) {
    head = newNode;
    tail = newNode;
    return;
  }

  newNode->prev = tail;
  tail->next = newNode;
  tail = newNode;
  tail->next = head;
  head->prev = tail;
  return;
}


void linkedListDoubleCircular::insertOrdered(int data) {
  if (!head || head->data >= data) {
    insertHead(data);
    return;
  }

  if (tail->data <= data) {
    insertTail(data);
    return;
  }

  nodeDoubleCircular* curr = head;

  while(curr != head) {
    if (curr->data >= data) {
      insertNode(data, curr->prev);
      return;
    }

    curr = curr->next;
  }
}


void linkedListDoubleCircular::insertAfter(int key, int data) {
  if (!head) {
    insertHead(data);
    return;
  }

  nodeDoubleCircular* curr = head;

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

  std::cout << "Key not found" << '\n';

}


void linkedListDoubleCircular::insertBefore(int key, int data) {
  if (!head || head->data == key) {
    insertHead(data);
    return;
  }

  nodeDoubleCircular* curr = head;

  while (curr != head) {
    if (curr->data == key) {
      insertNode(data, curr->prev);
      return;
    }

    curr = curr->next;
  }

  std::cout << "Key not found" << '\n';
}


void linkedListDoubleCircular::insertAtPosition(int position, int data) {
  if (!head || position == 1) {
    insertHead(data);
    return;
  }

  nodeDoubleCircular* curr = head;
  int i = 2;

  while (curr->next != head) {
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


void linkedListDoubleCircular::deleteHead() {
  if (!head) {
    std::cout << "Empty List!" << '\n';
    return;
  }

  if(head->next == head) {
    delete head;
    head = nullptr;
    tail = nullptr;
    return;
  }

  tail->next = head->next;
  delete head;
  head = tail->next;
  head->prev = tail;

  return;
}


void linkedListDoubleCircular::deleteTail() {
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

  head->prev = tail->prev;
  delete tail;
  tail = head->prev;
  tail->next = head;

  return;
}




void linkedListDoubleCircular::deleteKey(int key) {
  if (!head) {
    std::cout << "Empty List!" << '\n';
    return;
  }

  if (head->data == key) {
    deleteHead();
    return;
  }

  nodeDoubleCircular* curr = head->next;
  while(curr != head) {
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

  std::cout << "Key not found" << '\n';
}


void linkedListDoubleCircular::deleteAtPosition(int position) {
    if (!head) {
      std::cout << "Empty List!" << '\n';
      return;
    }

    if (position == 1) {
      deleteHead();
      return;
    }

    nodeDoubleCircular* curr = head->next;
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
      deleteTail();
      return;
    }

    std::cout << "Position not found!" << '\n';
}


void linkedListDoubleCircular::deleteAfter(int key) {
  if (!head) {
    std::cout << "Empty List!" << '\n';
    return;
  }

  nodeDoubleCircular* curr = head;

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


void linkedListDoubleCircular::deleteBefore(int key) {
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

  nodeDoubleCircular* curr = (head->next)->next;

  while(curr != head) {
    if (curr->data == key) {
      deleteNode(curr->prev);
      return;
    }
    curr = curr->next;
  }

  std::cout << "Key not found" << '\n';

  return;
}


void linkedListDoubleCircular::sort() {
  nodeDoubleCircular* curr = head;
  int swapped;

  do {
    swapped = 0;
    curr = head;

    while (curr->next != head) {
      if (curr->data > (curr->next)->data) {
        swapLinear(curr, curr->next);
        swapped = 1;
      }
      curr = curr->next;
    }
  } while(swapped);
}


void linkedListDoubleCircular::concat(linkedListDoubleCircular& b) {
  linkedListDoubleCircular& a = *this;

  a.tail->next = b.head;
  b.head->prev = a.tail;
  a.tail = b.tail;
  a.tail->next = a.head;
  a.head->prev = a.tail;
}


void linkedListDoubleCircular::merge(linkedListDoubleCircular& b) {
    linkedListDoubleCircular& a = *this;
    linkedListDoubleCircular c;

    nodeDoubleCircular* currA = a.head;
    nodeDoubleCircular* currB = b.head;
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


void linkedListDoubleCircular::reverse() {
  linkedListDoubleCircular c;
  linkedListDoubleCircular& a = *this;

while (a.head) {
  c.insertTail(a.tail->data);
  a.deleteTail();
}

a.head = c.head;
a.tail = c.tail;
}


int linkedListDoubleCircular::getSize() {
  int count = 0;

  if (!head) {
    return count;
  }

  nodeDoubleCircular* curr = head;

  do {
    count++;
    curr = curr->next;
  } while(curr != head);

  return count;
}


void linkedListDoubleCircular::display() {
  if (!head) {
    std::cout << "Empty List!" << '\n';
    return;
  }

  nodeDoubleCircular* curr = head;

  do {
    std::cout << curr->data << ' ';
    curr = curr->next;
  } while(curr != head);

  std::cout << '\n';

  return;
}
