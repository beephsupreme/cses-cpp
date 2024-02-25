#include "cses.h"
#include <sstream>
#include <iostream>

std::stringstream weird_algorithm(std::istream &input) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::stringstream output;
  uint64_t n;
  input >> n;
  while (true) {
    output << n;
    if (n == 1) break;
    output << ' ';
    if (n % 2 == 0) n /= 2;
    else n = n * 3 + 1;
  }
  output << '\n';
  return output;
}
