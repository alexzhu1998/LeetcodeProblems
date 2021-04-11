#include <iostream>
using namespace std;


// class Ham {
// private:
//   int y;
// public:
//   int x;
//   int z;
//   void print() { std::cout << "ham"; }
// };

class Ham {
public:
    int x;
    void print();
    // constructors
    Ham() {}
    Ham(int y) {x = y;}
};

int main () {

  Ham h;
  h.x =3;
  
  h.print();
  Ham* p = &h;
  (*p).x = 5;
  p->x = 4;
  return 0;
}