#include <cassert>
#include <string>
#include <vector>

int countSubstrings(std::string s)
{
  std::vector<std::vector<bool>> dp(s.length(), std::vector<bool>(s.length(), false));
  int result = 0;
  for (int i = 0; i < s.length(); ++i) {
    dp[i][i] = true;
    ++result;
  }

  for (int i = 0; i < s.length() - 1; ++i) {
    if (s[i] == s[i + 1]) {
      dp[i][i + 1] = true;
      ++result;
    }
  }

  for (int i = 3; i <= s.length(); ++i) {
    for (int j = 0; j < s.length() - i + 1; ++j) {
      if (s[j] == s[j + i - 1] && dp[j + 1][j + i - 2]) {
        dp[j][j + i - 1] = true;
        ++result;
      }
    }
  }

  return result;
}

int main()
{
  // 647. Palindromic Substrings

  {
    std::string s = "abc";
    assert(countSubstrings(s) == 3);
  }

  {
    std::string s = "aaa";
    assert(countSubstrings(s) == 6);
  }

  return 0;
}
