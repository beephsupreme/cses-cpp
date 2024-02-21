#include <gtest/gtest.h>
#include <bits/stdc++.h>
#include "weird_algorithm.h"

using namespace std;

TEST(CSEStest, WeirdAlgorithm)
{
    ifstream ifs;
    ifs.open("weird.txt");
    EXPECT_EQ((weird_algorithm()).str(), "7 22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1");
}