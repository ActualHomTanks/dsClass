#ifndef POLYNOMIAL
#define POLYNOMIAL

class linkedListPoly{
  class nodePoly {
  public:
    int coef;
    int power;
    nodePoly* next;

  public:
    nodePoly();
    nodePoly(int c, int p);
  };

private:
  nodePoly* head;
  nodePoly* tail;

public:
  linkedListPoly();
  void insert(int c, int p);
  void read();
  void add(linkedListPoly& poly2);
  void display();
};



#endif
