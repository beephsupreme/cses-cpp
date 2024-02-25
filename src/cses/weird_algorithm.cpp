#include "weird_algorithm.h"
#include <sstream>

std::stringstream weird_algorithm(std::istream &input) {
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
