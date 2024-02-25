#include "trailing_zeros.h"
#include <sstream>

std::stringstream trailing_zeros(std::istream &input) {
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
