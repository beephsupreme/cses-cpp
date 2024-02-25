#include "increasing_array.h"
#include <sstream>
#include <vector>

std::stringstream increasing_array(std::istream &input) {
  std::stringstream output;
  uint64_t n;
  input >> n;
  std::vector<uint64_t> v(n);
  for (auto &e : v) {
    input >> e;
  }

  uint64_t dif;
  uint64_t mn = 0;

  for (size_t i{1}; i < v.size(); ++i) {
    if (v[i] >= v[i - 1]) {
      continue;
    }
    dif = v[i - 1] - v[i];
    mn += dif;
    v[i] += dif;
  }

  output << mn << '\n';
  return output;
}