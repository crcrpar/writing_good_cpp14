#include <iostream>
#include <string>
#include <vector>

#include "absl/types/span.h"
#include "absl/strings/str_join.h"

struct Thing {
  size_t size{1};
  const size_t GetSize() const { return size; }
};

void f(absl::Span<Thing> things) {
  size_t total_size{0};

  for (auto & thing : things) {
    total_size += thing.GetSize();
  }
}

int main() {
  std::vector<std::string> v = {"foo", "bar", "baz"};
  std::string s = absl::StrJoin(v, "-");

  std::cout << "Joined string: " << s << "\n";

  Thing things[10];
  f(things);
  f({things, 5});
  f({things, 30});  // In GSL, this should be compile-time error. Though the name is `array_view`

  return 0;
}
