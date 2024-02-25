#include <iostream>
#include <sstream>
#include "trailing_zeros.h"

int main() {
  std::stringstream output = trailing_zeros(::std::cin);
  std::cout << output.str() << std::endl;
  return 0;
}