#include "cses.h"
#include <sstream>
#include <iostream>
#include <algorithm>

std::stringstream palindrome_reorder(std::istream &input) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::stringstream output;

  char alphabet[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
                     'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
                     'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
  int64_t counts[26] = {0};
  int64_t odd_counts{0};
  char middle = '#';

  std::string chars;
  input >> chars;
  uint64_t n = chars.size();
  for (const char &c : chars) {
    counts[c - 65] += 1;
  }
  for (int64_t i : counts) {
    if (i % 2 != 0) {
      odd_counts++;
    }
  }
  if (odd_counts > 1) {
    output << "NO SOLUTION\n";
    return output;
  }
  if (n == 1) {
    for (int i = 0; i < 26; ++i) {
      if (counts[i] == 1) {
        output << alphabet[i] << '\n';
        return output;
      }
    }
  }
  if (n % 2 == 1) {
    for (int i = 0; i < 26; ++i) {
      if (counts[i] % 2 == 1) {
        middle = alphabet[i];
      }
    }
  }
  for (int64_t &count : counts) {
    count /= 2;
  }
  for (int i = 0; i < 26; ++i) {
    if (counts[i] != 0) {
      for (int j = 0; j < counts[i]; ++j) {
        output << alphabet[i];
      }
    }
  }
  std::string clone = output.str();
  std::reverse(clone.begin(), clone.end());
  if (middle != '#') {
    output << middle;
  }
  for (char c : clone) {
    output << c;
  }
  output << '\n';
  return output;
}
