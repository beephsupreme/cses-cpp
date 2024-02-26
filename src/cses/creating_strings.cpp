#include "cses.h"
#include <sstream>
#include <iostream>
#include <algorithm>

std::stringstream creating_strings(std::istream &input) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::stringstream temp;
  std::stringstream output;
  std::string str;
  uint64_t count{0};
  input >> str;
  std::sort(str.begin(), str.end());
  do {
    count++;
    temp << str << '\n';
  } while (std::next_permutation(str.begin(), str.end()));
  output << count << '\n' << temp.str();
  return output;
}
