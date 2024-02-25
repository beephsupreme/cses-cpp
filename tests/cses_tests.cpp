#include <gtest/gtest.h>
#include <filesystem>
#include <sstream>
#include <fstream>

#include "weird_algorithm.h"
#include "missing_number.h"
#include "repetitions.h"
#include "increasing_array.h"
#include "permutations.h"
#include "number_spiral.h"
#include "two_knights.h"
#include "two_sets.h"
#include "bit_strings.h"
#include "trailing_zeros.h"

using namespace std;

class CSEStest : public testing::Test {
 protected:
  string directory;
  std::vector<std::filesystem::path> filenames;
  std::ifstream questions;
  std::vector<std::string> questions_list;
  std::ifstream answers;
  std::vector<std::string> answers_list;
  std::string answer;
  std::stringstream result;
  std::stringstream output;

  void SetUp(const std::string &sub_directory,
             const function<stringstream(istream &)> &func) {

    directory = "/Users/michael/projects/cses-cpp/tests/test_data/";
    directory.append(sub_directory);

    for (const auto &entry : std::filesystem::directory_iterator(directory)) {
      filenames.emplace_back(entry.path().string());
    }
    for (const std::filesystem::path &file : filenames) {
      if (file.string().find("test_input") != std::string::npos) {
        questions_list.push_back(file.string());
      }
      if (file.string().find("test_output") != std::string::npos) {
        answers_list.push_back(file.string());
      }
    }
    std::sort(answers_list.begin(), answers_list.end());
    std::sort(questions_list.begin(), questions_list.end());

    for (int i = 0; i < answers_list.size(); ++i) {
      questions.open(questions_list[i], std::ifstream::in);
      answers.open(answers_list[i], std::ifstream::in);
      output = func(questions);
      while (getline(answers, answer)) {
        result << answer << std::endl;
      }
      EXPECT_EQ(output.str(), result.str());
      result.str(std::string());
      questions.close();
      answers.close();
    }
  }
};

TEST_F(CSEStest, WeirdAlgorithm) {
  std::string sub_directory = "weird_algorithm";
  SetUp(sub_directory, weird_algorithm);
}

TEST_F(CSEStest, MissingNumber) {
  std::string sub_directory = "missing_number";
  SetUp(sub_directory, missing_number);
}

TEST_F(CSEStest, Repetitions) {
  std::string sub_directory = "repetitions";
  SetUp(sub_directory, repetitions);
}

TEST_F(CSEStest, IncreasingArray) {
  std::string sub_directory = "increasing_array";
  SetUp(sub_directory, increasing_array);
}

TEST_F(CSEStest, Permutations) {
  std::string sub_directory = "permutations";
  SetUp(sub_directory, permutations);
}

TEST_F(CSEStest, NumberSpiral) {
  std::string sub_directory = "number_spiral";
  SetUp(sub_directory, number_spiral);
}

TEST_F(CSEStest, TwoKnights) {
  std::string sub_directory = "two_knights";
  SetUp(sub_directory, two_knights);
}

TEST_F(CSEStest, TwoSets) {
  std::string sub_directory = "two_sets";
  SetUp(sub_directory, two_sets);
}

TEST_F(CSEStest, BitStrings) {
  std::string sub_directory = "bit_strings";
  SetUp(sub_directory, bit_strings);
}

TEST_F(CSEStest, TrailingZeros) {
  std::string sub_directory = "trailing_zeros";
  SetUp(sub_directory, trailing_zeros);
}
