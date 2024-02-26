#include "cses.h"
#include <iostream>
#include <sstream>
#include <vector>

void hanoi(std::vector<std::pair<uint64_t, uint64_t>> &m, uint64_t n, uint64_t a, uint64_t b, uint64_t c) {
  if (n == 0) return;
  hanoi(m, n - 1, a, c, b);
  std::pair<uint64_t, uint64_t> p = std::make_pair(a, c);
  m.emplace_back(p);
  hanoi(m, n - 1, b, a, c);
}

std::stringstream hanoi_run(std::istream &input) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::stringstream output;
  std::vector<std::pair<uint64_t, uint64_t>> moves;
  uint64_t n;

  input >> n;
  output << (2 << (n-1)) - 1 << '\n';
  hanoi(moves, n, 1, 2, 3);

  for (auto &move : moves) {
    output << move.first << ' ' << move.second << '\n';
  }
  return output;
}
