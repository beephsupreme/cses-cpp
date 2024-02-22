#include "missing_number.h"
#include <bits/stdc++.h>

std::stringstream missing_number(std::istream &input) {
    std::stringstream output;
    uint64_t n, sum, s;
    input >> n;
    sum = n * (n + 1) / 2;
    for (size_t i = 1; i < n; i++) {
        input >> s;
        sum -= s;
    }
    output << sum;
    return output;
}