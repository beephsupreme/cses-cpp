#include "cses.h"
#include <sstream>
#include <iostream>

std::stringstream bit_strings(std::istream &input) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::stringstream output;

  int64_t n;
  input >> n;

  int64_t result{1};
  for (int64_t i{0}; i < n; ++i) {
    result *= 2;
    result %= 1000000007;
  }
  output << result << '\n';
  return output;
}
