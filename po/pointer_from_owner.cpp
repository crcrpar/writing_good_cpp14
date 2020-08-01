#include <memory>


// around 40 mins.
// Could a compiler really do this? Note that the comments are about static analysis.
int main(void) {
  // not specific to std smart ptrs - intended to work for custom smart pointers
  auto s = std::make_shared<int>(1);
  int * p = s.get(); // p points to s' = an object owned by s (__current value__)

  *p = 42; // ok p is valid.

  // not specific to smart ptrs at all - general rule detects modifying an Owner
  s = std::make_shared<int>(2);  // A: modify s -> invalidate p

  *p = 43; // ERROR: p was invalidated by assignment to s at line A

  return 0;
}
