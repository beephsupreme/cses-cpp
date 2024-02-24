#include <iostream>
#include <sstream>
#include "number_spiral.h"

int main() {
  std::stringstream output = number_spiral(::std::cin);
  std::cout << output.str() << std::endl;
  return 0;
}