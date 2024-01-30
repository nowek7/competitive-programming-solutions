#include <cassert>
#include <string>
#include <vector>

int longestCommonSubsequence(std::string text1, std::string text2)
{
  std::vector<std::vector<int>> dp(text1.size() + 1, std::vector<int>(text2.size() + 1, 0));

  for (int i = 1; i <= text1.size(); ++i) {
    for (int j = 1; j <= text2.size(); ++j) {
      dp[i][j] = (text1[i - 1] == text2[j - 1]) ? dp[i - 1][j - 1] + 1 : std::max(dp[i - 1][j], dp[i][j - 1]);
    }
  }

  return dp.back().back();
}

int main()
{
  // 1143. Longest Common Subsequence

  {
    std::string text1 = "abcde";
    std::string text2 = "ace";
    assert(longestCommonSubsequence(text1, text2) == 3);
  }

  {
    std::string text1 = "abc";
    std::string text2 = "abc";
    assert(longestCommonSubsequence(text1, text2) == 3);
  }

  {
    std::string text1 = "abc";
    std::string text2 = "def";
    assert(longestCommonSubsequence(text1, text2) == 0);
  }

  return 0;
}
