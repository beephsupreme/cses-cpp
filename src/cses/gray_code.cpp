#include "cses.h"

#include <iostream>
#include <sstream>
#include <vector>

std::stringstream gray_code(std::istream &input) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::stringstream output;

  uint64_t n;
  uint64_t N{1};
  input >> n;

  for (uint64_t i{0}; i < n; i++) {
    N *= 2;
  }

  std::vector<uint64_t> V(N, 0);
  for (uint64_t i{0}; i < 1u << n; i++) {
    V[i] = i ^ (i >> 1);
  }

  for (auto &v : V) {
    for (uint64_t i = 1u << (n - 1); i > 0; i /= 2)
      output << ((v & i) ? 1 : 0);
    output << '\n';
  }
  return output;
}

