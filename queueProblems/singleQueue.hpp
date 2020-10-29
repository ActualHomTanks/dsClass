#ifndef SINGLE_QUEUE
#define SINGLE_QUEUE

#define maximum 5

class cque {
private:
  char q[maximum];
  int f,r,count;
public:
  cque();
  void enque(char element);
  char deque();
  char peek();
  int size();
  bool empty();
  bool full();
  void display();
};

#endif
