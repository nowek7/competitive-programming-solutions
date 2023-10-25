#include <array>
#include <cassert>
#include <string>

std::string minWindow(std::string s, std::string t)
{
  std::array<int, 128> patternFreq = {0};
  for (char c: t) {
    patternFreq[c]++;
  }

  int left = 0;
  int right = 0;
  int minWindowStart = 0;
  int minWindowLength = s.size() + 1;

  int remaining = t.size();
  while (right < s.size()) {
    if (patternFreq[s[right++]]-- > 0) {
      remaining--;
    }

    while (remaining == 0) {
      if (right - left < minWindowLength) {
        minWindowStart = left;
        minWindowLength = right - left;
      }

      if (patternFreq[s[left++]]++ == 0) {
        remaining++;
      }
    }
  }

  return (minWindowLength == s.size() + 1) ? "" : s.substr(minWindowStart, minWindowLength);
}

int main()
{
  // 76. Minimum Window Substring

  {
    std::string s = "ADOBECODEBANC";
    std::string t = "ABC";
    assert(minWindow(s, t) == "BANC");
  }

  {
    std::string s = "a";
    std::string t = "a";
    assert(minWindow(s, t) == "a");
  }

  {
    std::string s = "a";
    std::string t = "aa";
    assert(minWindow(s, t) == "");
  }
}