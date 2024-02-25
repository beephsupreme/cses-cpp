#include <iostream>
#include <sstream>
#include "bit_strings.h"

int main() {
  std::stringstream output = bit_strings(::std::cin);
  std::cout << output.str() << std::endl;
  return 0;
}