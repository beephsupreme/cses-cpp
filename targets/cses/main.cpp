#include <iostream>
#include <sstream>
#include "two_sets.h"

int main() {
  std::stringstream output = two_sets(::std::cin);
  std::cout << output.str() << std::endl;
  return 0;
}