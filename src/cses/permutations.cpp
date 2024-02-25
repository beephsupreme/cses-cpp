#include "permutations.h"
#include <sstream>

std::stringstream permutations(std::istream &input) {
  std::stringstream output;
  uint64_t n;
  input >> n;
  if (n == 1) {
    output << 1;
  } else if (n == 2 || n == 3) {
    output << "NO SOLUTION";
  } else if (n > 3) {
    for (uint64_t i{2}; i <= n; i += 2) {
      output << i << ' ';
    }
    for (uint64_t i{1}; i <= n; i += 2) {
      output << i << ' ';
    }
  }
  output << '\n';
  return output;
}