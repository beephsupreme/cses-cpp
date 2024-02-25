#include "cses.h"
#include <sstream>
#include <iostream>

std::stringstream repetitions(std::istream &input) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::stringstream output;
  std::string line;
  input >> line;
  uint64_t count{1};
  uint64_t max{1};
  char curr = line.at(0);
  for (size_t i{1}; i < line.size(); ++i) {
    char next = line.at(i);
    if (curr == next) {
      count++;
      if (count > max) {
        max = count;
      }
      continue;
    }
    curr = next;
    count = 1;
  }
  output << max << '\n';
  return output;
}