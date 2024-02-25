#include "cses.h"
#include <sstream>
#include <iostream>

std::stringstream coin_piles(std::istream &input) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::stringstream output;
  int64_t n;
  int64_t a;
  int64_t b;

  input >> n;
  for (int64_t i{0}; i < n; ++i) {
    input >> a >> b;
    if (a > (2 * b) || b > (2 * a) || (a + b) % 3 != 0) {
      output << "NO\n";
    } else {
      output << "YES\n";
    }
  }
  return output;
}