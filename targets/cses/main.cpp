#pragma GCC optimize("-O3","unroll-loops")
#pragma GCC optimize("-Ofast")
#include <bits/stdc++.h>
#include "missing_number.h"

int main() {
    std::stringstream output = missing_number(std::cin);
    std::cout << output.str() << std::endl;
    return 0;
}