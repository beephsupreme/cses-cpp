#include <gtest/gtest.h>
#include <filesystem>
#include <sstream>
#include <fstream>

#include "weird_algorithm.h"
#include "missing_number.h"
#include "repetitions.h"
#include "increasing_array.h"

using namespace std;

class CSEStest : public testing::Test {
 protected:
  string directory;
  std::ifstream questions;
  std::ifstream answers;
  std::stringstream output;
  std::string answer;
  std::vector<std::filesystem::path> filenames;
  std::vector<std::string> answers_list;
  std::vector<std::string> questions_list;

  void SetUp(const std::string &sub_directory, const function<stringstream(istream &)> &func) {
    directory = "/Users/michael/projects/cses-cpp/tests/test_data/";
    directory.append(sub_directory);

//    cout << "directory name: " << directory << endl;
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
//      std::cout << "Testing: " << questions_list[i] << std::endl;
      answers.open(answers_list[i], std::ifstream::in);
      questions.open(questions_list[i], std::ifstream::in);
      output = func(questions);
      getline(answers, answer);
      EXPECT_EQ(output.str(), answer);
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
