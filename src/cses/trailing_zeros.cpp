#include "cses.h"
#include <sstream>
#include <iostream>

std::stringstream trailing_zeros(std::istream &input) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::stringstream output;
  uint64_t n;
  uint64_t result{0};
  input >> n;
  while (n > 0) {
    n /= 5;
    result += n;
  }
  output << result << '\n';
  return output;
}
