#include "weird_algorithm.h"
#include <bits/stdc++.h>

using namespace std;

stringstream weird_algorithm() {
    stringstream output;
    uint64_t n;
    //cin >> n;
    ifstream& input;
    input >> n;
    while (true) {
        output << n << ' ';
        if (n == 1) break;
        if (n % 2 == 0) n /= 2;
        else n = n * 3 + 1;
    }
    return output;
}
