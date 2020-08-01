#include <vector>
#include <memory>

/**
 * ptr -> data_array
 * vec -> <>
 * sv2 -> sv
 * direction: sv -> <> -> data_array
 */

auto main(void) -> int {
  auto sv = std::make_shared<std::vector<int>>(100);
  std::shared_ptr<std::vector<int>>* sv2 = &sv; //sv2 points to sv
  std::vector<int>* vec = &*sv; // vec points to sv'
  int * ptr = &(*sv)[0]; // ptr points to sv''

  *ptr = 1; //ok

  vec->push_back(1); // A: modifying sv'i invalidates sv''

#if 0
  *ptr = 2; // ERROR, ptr was invalidated by "push_back" on line A
#endif

  ptr = &(*sv)[0];  // back to previous state to demonstrate an alternative..

  (*sv2).reset();  // B: modifying sv invalidates sv'

#if 0
  vec->push_back(1); // ERROR: vec was invalidated by "reset" on line B
  *ptr = 3; // ERROR, ptr was invalidated by "reset" on line B
#endif

  return 0;
}
