#include <algorithm>
#include <cassert>
#include <string>
#include <unordered_map>
#include <vector>

int maximumLength(std::string s)
{
  int maxLength = -1;

  for (auto length = 1; length < s.length(); ++length) {
    std::unordered_map<std::string, int> frequency;

    for (auto i = 0; i <= s.length() - length; ++i) {
      std::string sub = s.substr(i, length);

      bool isSpecial = true;
      for (auto j = 1; j < length; ++j) {
        if (sub[j] != sub[0]) {
          isSpecial = false;
          break;
        }
      }

      if (isSpecial) {
        ++frequency[sub];
        if (frequency[sub] >= 3) {
          maxLength = std::max(maxLength, length);
        }
      }
    }
  }

  return maxLength;
}

int main()
{
  // 2981. Find Longest Special Substring That Occurs Thrice I

  {
    std::string s = "aaaa";
    assert(maximumLength(s) == 2);
  }

  {
    std::string s = "abcdef";
    assert(maximumLength(s) == -1);
  }

  {
    std::string s = "abcaba";
    assert(maximumLength(s) == 1);
  }

  return 0;
}
