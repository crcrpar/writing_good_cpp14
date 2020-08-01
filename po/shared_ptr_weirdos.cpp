#include <memory>

void f(int *) {}
void g(std::shared_ptr<int>&, int*) {}

std::shared_ptr<int> gsp = std::make_shared<int>(2);

void Example4(void){
  auto sp = gsp;
  f(gsp.get()); // BAD
  f(sp.get());
  g(sp, sp.get()); // BAD
  g(gsp, sp.get());
}
