#include <cassert>
#include <stack>
#include <string>

std::string makeGood(std::string s)
{
  constexpr int DIFF_LOWER_UPPER_CASE = 32;

  std::string goodStr;
  for (std::size_t i = 0; i < s.length(); ++i) {
    if (!goodStr.empty() && (std::abs(s[i] - goodStr.back()) == DIFF_LOWER_UPPER_CASE)) {
      goodStr.pop_back();
    } else {
      goodStr += s[i];
    }
  }

  return goodStr;
}

std::string makeGood_v2(std::string s)
{
  constexpr int DIFF_LOWER_UPPER_CASE = 32;

  std::stack<char> chars;
  for (std::size_t i = 0; i < s.length(); ++i) {
    if (chars.empty()) {
      chars.push(s[i]);
    } else {
      char top = chars.top();
      if (std::abs(s[i] - top) == DIFF_LOWER_UPPER_CASE) {
        chars.pop();
      } else {
        chars.push(s[i]);
      }
    }
  }

  std::string goodStr;
  while (!chars.empty()) {
    char top = chars.top();
    goodStr = top + goodStr;
    chars.pop();
  }

  return goodStr;
}

int main()
{
  // 1544. Make The String Great

  {
    std::string s = "leEeetcode";
    assert(makeGood(s) == "leetcode");
    assert(makeGood_v2(s) == "leetcode");
  }

  {
    std::string s = "abBAcC";
    assert(makeGood(s) == "");
    assert(makeGood_v2(s) == "");
  }

  {
    std::string s = "s";
    assert(makeGood(s) == "s");
    assert(makeGood_v2(s) == "s");
  }

  return 0;
}
