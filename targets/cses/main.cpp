#include <iostream>
#include <sstream>
#include "cses.h"

int main() {
  std::stringstream output = gray_code(::std::cin);
  std::cout << output.str() << '\n';
  return 0;
}