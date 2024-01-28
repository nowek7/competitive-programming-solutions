#include <array>
#include <cassert>
#include <numeric>
#include <string>

int minSteps(std::string s, std::string t)
{
  std::array<int, 26> frequency {0};
  for (char c: t) {
    ++frequency[c - 'a'];
  }

  for (char c: s) {
    const int idx = c - 'a';
    if (frequency[idx] > 0) {
      --frequency[idx];
    }
  }

  return std::accumulate(frequency.begin(), frequency.end(), 0);
}

int minSteps_v2(std::string s, std::string t)
{
  int len = t.length();
  std::array<int, 26> frequency {0};
  for (char c: t) {
    ++frequency[c - 'a'];
  }

  for (char c: s) {
    const int idx = c - 'a';
    if (frequency[idx] > 0) {
      --frequency[idx];
      --len;
    }
  }

  return len;
}

int main()
{
  // 1347. Minimum Number of Steps to Make Two Strings Anagram

  {
    std::string s = "bab";
    std::string t = "aba";
    assert(minSteps(s, t) == 1);
    assert(minSteps_v2(s, t) == 1);
  }

  {
    std::string s = "leetcode";
    std::string t = "practice";
    assert(minSteps(s, t) == 5);
    assert(minSteps_v2(s, t) == 5);
  }

  {
    std::string s = "anagram";
    std::string t = "mangaar";
    assert(minSteps(s, t) == 0);
    assert(minSteps_v2(s, t) == 0);
  }

  return 0;
}
