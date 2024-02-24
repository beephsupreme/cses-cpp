#include <iostream>
#include <sstream>
#include "two_knights.h"

int main() {
  std::stringstream output = two_knights(::std::cin);
  std::cout << output.str() << std::endl;
  return 0;
}