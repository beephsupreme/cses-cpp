#include "two_sets.h"
#include <sstream>
#include <iostream>
#include <vector>

std::stringstream two_sets(std::istream &input) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::stringstream output;

  int64_t n;
  input >> n;

  int64_t total = n * (n + 1) / 2;

  if (total & 1) {
    output << "NO\n";
  } else {
    output << "YES\n";
    std::vector<int64_t> a;
    std::vector<int64_t> b;
    for (int64_t i{0}; i < n; ++i) {
      int64_t p = i % 4;
      if (p == 0 || p == 3) {
        a.emplace_back(n - i);
      } else {
        b.emplace_back(n - i);
      }
    }
    output << a.size() << '\n';
    for (auto e : a) {
      output << e << ' ';
    }
    output << '\n' << b.size() << '\n';
    for (auto e : b) {
      output << e << ' ';
    }
    output << '\n';
  }
  return output;
}
