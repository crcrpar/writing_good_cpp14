// NOTE: this program doesn't work correctly by its design.
#include <memory>

template <typename A> void useA(A);

// I expect this func is to be NRVOed.
template <typename A>
std::unique_ptr<A> myFunc(void) {
  std::unique_ptr<A> pa(new A());
  return pa;
}

template <typename A>
void caller(void) {
  const A& rA = *myFunc<A>();
  // *temp_up points to temp_up' == "owned by temp_up"
  // rA points to temp_up' ...
  //       ... ~temp_up -> invalidate rA
  // A: ERROR: rA is unusable, initialized with invalid
  // reference (invalidated by destruction of temporary
  // unique_ptr returned from myFunc)
  use(rA); // ERROR: rA initialized as invalid on line A

  // Fix 1
  const auto p = myFunc<A>();
  const A & rA1 = *p;

  // Fix 2: Temporary Lifetime Extension!
  const auto& rA2 = myFunc<A>();
}
