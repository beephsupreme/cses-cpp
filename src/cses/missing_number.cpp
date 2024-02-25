#include "cses.h"
#include <sstream>
#include <iostream>

std::stringstream missing_number(std::istream &input) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::stringstream output;
  uint64_t n, sum, s;
  input >> n;
  sum = n * (n + 1) / 2;
  for (size_t i = 1; i < n; i++) {
    input >> s;
    sum -= s;
  }
  output << sum << '\n';
  return output;
}