#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

int minExtraChar(std::string s, std::vector<std::string>& dictionary)
{
  std::unordered_set<std::string> dict(dictionary.begin(), dictionary.end());
  std::vector<int> dp(s.length() + 1, s.length() + 1);
  dp[0] = 0;

  for (auto i = 1; i <= s.length(); ++i) {
    dp[i] = dp[i - 1] + 1;
    for (auto j = 1; j <= i; ++j) {
      std::cout << s.substr(i - j, j) << '\n';
      if (dict.find(s.substr(i - j, j)) != dict.end()) {
        dp[i] = std::min(dp.at(i), dp.at(i - j));
      }
    }
  }

  return dp.back();
}

int main()
{
  {
    std::string s = "leetscode";
    std::vector<std::string> dictionary = {"leet", "code", "leetcode"};
    std::cout << minExtraChar(s, dictionary) << '\n';
  }

  {
    std::string s = "sayhelloworld";
    std::vector<std::string> dictionary = {"hello", "world"};
    std::cout << minExtraChar(s, dictionary) << '\n';
  }

  return 0;
}