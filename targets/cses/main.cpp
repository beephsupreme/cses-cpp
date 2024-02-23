#include <iostream>
#include <sstream>;
#include "increasing_array.h"

int main() {
  std::stringstream output = increasing_array(::std::cin);
  std::cout << output.str() << std::endl;
  return 0;
}