#include "cses.h"
#include <sstream>
#include <iostream>

std::stringstream two_knights(std::istream &input) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::stringstream output;
  int64_t n;

  input >> n;
  for (int64_t i{1}; i <= n; ++i) {
    output << (i * i * i * i - 9 * i * i + 24 * i - 16) / 2 << '\n';
  }
  return output;
}
