#include <iostream>
#include <sstream>
#include "cses.h"

int main() {
  std::stringstream output = hanoi_run(::std::cin);
  std::cout << output.str() << '\n';
  return 0;
}