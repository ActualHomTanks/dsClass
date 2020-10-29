#define maximum 10

class stacTwoDim {
private:
  int top;
  char st[maximum][maximum];

public:
  stacTwoDim();
  void push(char n[]);
  char* pop();
  char* peek();
  int size();
  bool empty();
  bool full();
  void display();

};
