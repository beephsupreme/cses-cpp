#include <gtest/gtest.h>
#include <bits/stdc++.h>
#include "weird_algorithm.h"

using namespace std;

TEST(CSEStest, WeirdAlgorithm) {
    string directory = "/Users/michael/projects/cses-cpp/tests/test_data/weird_algorithm/";
    std::ifstream questions;
    std::ifstream answers;
    std::stringstream output;
    std::string answer;
    std::vector<std::filesystem::path> filenames;
    std::vector<std::string> answers_list;
    std::vector<std::string> questions_list;

    for (const auto &entry: std::filesystem::directory_iterator(directory)) {
        filenames.emplace_back(entry.path().string());
    }

    for (const std::filesystem::path &file: filenames) {
        if (file.string().find("question") != std::string::npos) {
            questions_list.push_back(file.string());
        }
        if (file.string().find("answer") != std::string::npos) {
            answers_list.push_back(file.string());
        }
    }

    std::sort(answers_list.begin(), answers_list.end());
    std::sort(questions_list.begin(), questions_list.end());

    for (int i = 0; i < answers_list.size(); ++i) {
//        std::cout << "Testing: " << questions_list[i] << std::endl;
        answers.open(answers_list[i], std::ifstream::in);
        questions.open(questions_list[i], std::ifstream::in);
        output = weird_algorithm(questions);
        getline(answers, answer);
        EXPECT_EQ(output.str(), answer);
        questions.close();
        answers.close();
    }
}