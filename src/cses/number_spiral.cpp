#include "cses.h"
#include <sstream>
#include <iostream>

std::stringstream number_spiral(std::istream &input) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::stringstream output;
  int64_t n;
  int64_t x;
  int64_t y;
  int64_t mx;
  int64_t mid;

  input >> n;
  for (int64_t i{0}; i < n; ++i) {
    input >> x >> y;
    mx = std::max(x, y);
    mid = mx * (mx - 1) + 1;
    mid += (mx % 2) ? (y - x) : (x - y);
    output << mid << std::endl;
  }
  return output;
}