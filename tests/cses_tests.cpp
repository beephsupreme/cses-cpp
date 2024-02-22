#include <gtest/gtest.h>
#include <bits/stdc++.h>
#include "weird_algorithm.h"

using namespace std;

TEST(CSEStest, WeirdAlgorithm)
{
    string prefix = "/Users/michael/projects/cses-cpp/tests/test_data/weird_algorithm_";
    std::ifstream input;
    std::ifstream answer_file;
    std::stringstream output;
    std::string answer;

    input.open(prefix + "01q.txt", std::ifstream::in);
    answer_file.open(prefix + "01a.txt", std::ifstream::in);
    output = weird_algorithm(input);
    getline(answer_file, answer);
    EXPECT_EQ(output.str(), answer);
    input.close();
    answer_file.close();

    input.open(prefix + "02q.txt", std::ifstream::in);
    answer_file.open(prefix + "02a.txt", std::ifstream::in);
    output = weird_algorithm(input);
    getline(answer_file, answer);
    EXPECT_EQ(output.str(), answer);
    input.close();
    answer_file.close();

    input.open(prefix + "03q.txt", std::ifstream::in);
    answer_file.open(prefix + "03a.txt", std::ifstream::in);
    output = weird_algorithm(input);
    getline(answer_file, answer);
    EXPECT_EQ(output.str(), answer);
    input.close();
    answer_file.close();

    input.open(prefix + "04q.txt", std::ifstream::in);
    answer_file.open(prefix + "04a.txt", std::ifstream::in);
    output = weird_algorithm(input);
    getline(answer_file, answer);
    EXPECT_EQ(output.str(), answer);
    input.close();
    answer_file.close();
}