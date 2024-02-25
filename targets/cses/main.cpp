#include <iostream>
#include <sstream>
#include "cses.h"

int main() {
  std::stringstream output = coin_piles(::std::cin);
  std::cout << output.str() << '\n';
  return 0;
}