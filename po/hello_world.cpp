#include <array>
#include <memory>
#include <iostream>
#include <vector>


// Around 33 minutes of video.
int * f_warmup(void) {
  int * p1 = nullptr, * p2 = nullptr, * p3 = nullptr;

  {
    int i = 1;
    struct mystruct {
      char c;
      char c2;
      int i;
    } s = {'a', 'b', 2};

    std::array<int, 10> a = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    p1 = &i;  // p1 points to i
    p2 = &s.i;  // p2 points to s
    p3 = &a[3];  // p3 points to a
    *p1 = *p2 = *p3 = 42; // valid till here.
  }

  *p1 = 1; // ERROR: `p` was invalidated when i went out of scope. Solution is increasing i's lifetime or reduce p's lifetime.
  *p2 = *p3 = 1; // ditto.

  return p1;
}

int f_warmup2(void){
  int i = 1;  // non-Ptr
  int & ri = i; // ri points to i
  int * pi = &ri; // pi points to i

  int ** ppi = &pi; // ppi points to Ptr pi

  return i;

  auto s = std::make_shared<int>(2);
  auto * ps = &*s; // ps points to Owner s
}

void f_warmup2_dereferencing(void) {
  int i = 0;
  int * pi = &i; // pi points to i
  int ** ppi = & pi; // ppi points to pi

  int * pi2 = *ppi; // IN: ppi points to pi, pi points to i, *ppi points to i. OUT: pi2 points to i

  int j = 0;
  pi = &j; // pi points to j - **ppi points to j.

  pi2 = *ppi; // IN: ppi points to pi, pi points to j. OUT: pi2 points to j.
}

int main() {
  f_warmup();
  return 0;
}
