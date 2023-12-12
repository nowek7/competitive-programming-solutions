#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> letterCombinations(std::string digits)
{
  std::vector<std::string> result;
  if (digits.empty()) {
    return result;
  }

  std::vector<std::vector<std::string>> dictionary = {
    {"a", "b", "c"},
    {"d", "e", "f"},
    {"g", "h", "i"},
    {"j", "k", "l"},
    {"m", "n", "o"},
    {"p", "q", "r", "s"},
    {"t", "u", "v"},
    {"w", "x", "y", "z"}
  };

  result = dictionary[digits.front() - '0' - 2];
  for (int i = 1; i < digits.size(); ++i) {
    std::vector<std::string> prev = result;
    result.clear();
    auto chars = dictionary[digits[i] - '0' - 2];
    for (auto c: chars) {
      for (auto s: prev) {
        result.push_back(s + c);
      }
    }
  }

  return result;
}

int main()
{
  // 17. Letter Combinations of a Phone Number

  auto printCombination = [](const std::vector<std::string>& comb) {
    if (!comb.empty()) {
      for (int i = 0; i < comb.size() - 1; ++i) {
        std::cout << comb[i] << " ";
      }
      std::cout << comb.back() << '\n';
    }
  };

  {
    std::string digits = "23";
    auto comb = letterCombinations(digits);
    printCombination(comb);
  }

  {
    std::string digits = "";
    auto comb = letterCombinations(digits);
    printCombination(comb);
  }

  {
    std::string digits = "2";
    auto comb = letterCombinations(digits);
    printCombination(comb);
  }

  return 0;
}